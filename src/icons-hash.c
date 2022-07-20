#include <stddef.h>
#include <stdint.h>

#ifndef ICONS_PROBE_MAX
	#define ICONS_PROBE_MAX 8
#endif

#ifdef ICONS_GENERATE

#ifdef NDEBUG
	#error "NDEBUG"
#endif
#include <assert.h>
#include <stdio.h>
#include <string.h>
#include "icons.h"

#define ASSERT(X) assert(X)
#define ARRLEN(X) (sizeof(X) / sizeof((X)[0]))
#define log(...)  fprintf(stderr, __VA_ARGS__)

static uint16_t icon_ext_hash(const char *s);

static uint16_t seen[256];
static uint16_t hash_start = 41;
static uint16_t hash_mul = 5731;


#define MAX(A, B)        ((A) > (B) ? (A) : (B))
int
main(void)
{
	assert(ARRLEN(icons_ext) <= ARRLEN(seen));
	assert((ARRLEN(seen) & (ARRLEN(seen) - 1)) == 0);

	uint32_t tries = 0, max_try;

again:
	assert(tries < (1ul << 16));
	max_try = 0;
	for (size_t i = 0; i < ARRLEN(icons_ext); ++i) {
		uint16_t k,  z = icon_ext_hash(icons_ext[i].match);
		assert(z < ARRLEN(seen));
		for (k = 0; k < ARRLEN(seen); ++k) {
			if (!seen[(z + k) % ARRLEN(seen)])
				break;
		}
		if (k > max_try)
			max_try = k;
		if (max_try >= ICONS_PROBE_MAX) {
			hash_start *= 40503u;
			hash_mul *= 40503u;
			++tries;
			goto again;
		}
		seen[(z + k) % ARRLEN(seen)] = 1;
	}
	log("hash_start: %u hash_mul: %u max_try: %u\n",
	    (unsigned)hash_start, (unsigned)hash_mul, (unsigned)max_try);
	printf("#define hash_start %uu\n", hash_start);
	printf("#define hash_mul   %uu\n", hash_mul);

	size_t match_max = 0, icon_max = 0;
	for (size_t i = 0; i < ARRLEN(icons_name); ++i) {
		match_max = MAX(match_max, strlen(icons_name[i].match) + 1);
		icon_max = MAX(icon_max, strlen(icons_name[i].icon) + 1);
	}
	for (size_t i = 0; i < ARRLEN(icons_ext); ++i) {
		match_max = MAX(match_max, strlen(icons_ext[i].match) + 1);
		icon_max = MAX(icon_max, strlen(icons_ext[i].icon) + 1);
	}
	icon_max = MAX(icon_max, strlen(dir_icon.icon) + 1);
	icon_max = MAX(icon_max, strlen(exec_icon.icon) + 1);
	icon_max = MAX(icon_max, strlen(file_icon.icon) + 1);
	printf("struct icon_pair { const char match[%zu]; const char icon[%zu]; unsigned char color; };\n\n",
	       match_max, icon_max);

	memset(seen, 0x0, sizeof seen);
	printf("static struct icon_pair icons_ext[%zu] = {\n", ARRLEN(seen));
	for (size_t i = 0; i < ARRLEN(icons_ext); ++i) {
		uint16_t z, k, h = icon_ext_hash(icons_ext[i].match);
		for (k = 0; k < ICONS_PROBE_MAX; ++k) {
			z = (h + k) % ARRLEN(seen);
			if (!seen[z]) break;
		}
		assert(k != ICONS_PROBE_MAX);
		seen[z] = 1;
		printf("\t[%u] = {\"%s\", \"%s\", %d },\n",
		       (unsigned)z,
		       icons_ext[i].match,
		       icons_ext[i].icon,
		       (unsigned)icons_ext[i].color);
	}
	printf("};\n");
}

#else
	#define ASSERT(X) ((void)0)
#endif /* ICONS_GENERATE */

#ifndef TOUPPER
	#define TOUPPER(ch)     (((ch) >= 'a' && (ch) <= 'z') ? ((ch) - 'a' + 'A') : (ch))
#endif

static uint16_t
icon_ext_hash(const char *str)
{
	uint16_t z = 8;
	ASSERT(1u << z == ARRLEN(seen));
	const unsigned char *s = (const unsigned char *)str;
	uint16_t hash = hash_start;
	while (*s) {
		uint16_t c = TOUPPER(*s);
		++s;
		hash ^= c | (c << 8);
		hash *= hash_mul;
	}
	hash = (hash >> z) ^ hash;
	hash *= 40503u;
	hash >>= z;
	ASSERT(hash < ARRLEN(seen));
	return hash;
}
