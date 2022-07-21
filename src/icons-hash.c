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
#define log(...)  fprintf(stderr, "[INFO]: " __VA_ARGS__)

static uint16_t icon_ext_hash(const char *s);

static uint16_t seen[256];
static uint16_t hash_start = 41;
static uint16_t hash_mul = 5731;
static unsigned int max_try;
static struct icon_pair table[ARRLEN(seen)];

static void
rh_insert(const struct icon_pair item, uint32_t idx, uint32_t start)
{
	uint32_t n = start;
	while (n <= ICONS_PROBE_MAX) {
		if (seen[idx] == 0) {
			table[idx] = item;
			seen[idx] = 1;
			return;
		} else if (seen[idx] < n) {
			struct icon_pair tmp = table[idx];
			uint32_t z = seen[idx];

			table[idx] = item;
			seen[idx] = n;

			rh_insert(tmp, idx, z);
			return;
		}
		++n;
		++idx;
	}
	assert(n <= ICONS_PROBE_MAX);
}

static void
table_populate(void)
{
	memset(seen, 0x0, sizeof seen);
	for (size_t i = 0; i < ARRLEN(icons_ext); ++i) {
		uint32_t h = icon_ext_hash(icons_ext[i].match);
		rh_insert(icons_ext[i], h, 1);
	}

	max_try = 0;
	for (size_t i = 0; i < ARRLEN(seen); ++i) {
		if (seen[i] > max_try) max_try = seen[i];
	}
	assert(max_try < ICONS_PROBE_MAX);
	log("max_try after robin-hood: %u\n", max_try);
}


#define MAX(A, B)        ((A) > (B) ? (A) : (B))
int
main(void)
{
	assert(ARRLEN(icons_ext) <= ARRLEN(seen));
	assert((ARRLEN(seen) & (ARRLEN(seen) - 1)) == 0);

	uint32_t tries = 0;

again:
	assert(tries < (1ul << 16));
	max_try = 0;
	for (size_t i = 0; i < ARRLEN(icons_ext); ++i) {
		uint16_t k,  z = icon_ext_hash(icons_ext[i].match);

		if (icons_ext[i].icon[0] == '\0') /* skip empty entries */
			continue;

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
	log("hash_start: %u hash_mul: %u max_try before robin-hood: %u\n",
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

	table_populate();
	printf("#define ICONS_PROBE_MAX %u\n", max_try + 1);

	printf("struct icon_pair { const char match[%zu]; const char icon[%zu]; unsigned char color; };\n\n",
	       match_max, icon_max);

	printf("static struct icon_pair icons_ext[%zu] = {\n", ARRLEN(seen));
	for (size_t i = 0; i < ARRLEN(table); ++i) {
		if (table[i].icon == NULL || table[i].icon[0] == '\0') /* skip empty entries */
			continue;
		printf("\t[%u] = {\"%s\", \"%s\", %d },\n",
		       (unsigned)i,
		       table[i].match,
		       table[i].icon,
		       (unsigned)table[i].color);
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
