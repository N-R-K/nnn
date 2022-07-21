#include <stddef.h>
#include <stdint.h>

#ifdef ICONS_GENERATE

#define ICONS_PROBE_MAX 8
#define ICONS_MATCH_MAX ((size_t)-1)

#ifdef NDEBUG
	#error "NDEBUG"
#endif
#include <assert.h>
#include <stdio.h>
#include <string.h>
#include "icons.h"

#define ASSERT(X) assert(X)
#define ARRLEN(X) (sizeof(X) / sizeof((X)[0]))
#define HGEN_ITERARATION (1ul << 12)
#if 0 /* enable for debugging */
	#define log(...)  fprintf(stderr, "[INFO]: " __VA_ARGS__)
#else
	#define log(...) ((void)0)
#endif

static uint16_t icon_ext_hash(const char *s);

static struct icon_pair table[256];
static uint16_t seen[ARRLEN(table)];
static uint16_t hash_start = 41;
static uint16_t hash_mul = 5731;

static void
rh_insert(const struct icon_pair item, uint32_t idx, uint32_t n)
{
	assert(n != 0);
	for (uint32_t tries = 0; tries < ARRLEN(table); ++tries, ++n) {
		if (seen[idx] == 0) {
			table[idx] = item;
			seen[idx] = n;
			return;
		} else if (seen[idx] < n) {
			struct icon_pair tmp = table[idx];
			uint32_t z = seen[idx];

			table[idx] = item;
			seen[idx] = n;

			rh_insert(tmp, idx, z);
			return;
		}
		idx = (idx + 1) % ARRLEN(table);
	}
	assert(0); /* unreachable */
}

static unsigned int
table_populate(void)
{
	memset(seen, 0x0, sizeof seen);
	memset(table, 0x0, sizeof table);
	for (size_t i = 0; i < ARRLEN(icons_ext); ++i) {
		if (icons_ext[i].icon[0] == '\0') continue;
		uint32_t h = icon_ext_hash(icons_ext[i].match);
		rh_insert(icons_ext[i], h, 1);
	}

	unsigned int max_try = 0;
	for (size_t i = 0; i < ARRLEN(seen); ++i) {
		if (seen[i] > max_try) max_try = seen[i];
	}
	return max_try;
}


#define MAX(A, B)        ((A) > (B) ? (A) : (B))
int
main(void)
{
	assert(ARRLEN(icons_ext) <= ARRLEN(table));
	/* ensure power of 2 hashtable size which allows compiler to optimize
	 * away mod (`%`) operations
	 */
	assert((ARRLEN(table) & (ARRLEN(table) - 1)) == 0);

	unsigned int max_probe = (unsigned)-1;
	uint16_t low_hash_start, low_hash_mul;

	for (size_t i = 0; i < HGEN_ITERARATION; ++i) {
		unsigned z = table_populate();
		if (z < max_probe) {
			max_probe = z;
			low_hash_start = hash_start;
			low_hash_mul = hash_mul;
		}
		hash_start *= 40503u;
		hash_mul *= 40503u;
	}
	assert(max_probe < ICONS_PROBE_MAX);
	hash_start = low_hash_start; hash_mul = low_hash_mul;
	assert(max_probe == table_populate());

	/* sanity check */
	for (size_t i = 0; i < ARRLEN(icons_ext); ++i) {
		if (icons_ext[i].icon[0] == 0) continue;
		uint16_t found = 0, h = icon_ext_hash(icons_ext[i].match);
		for (uint16_t k = 0; k < max_probe; ++k) {
			uint16_t z = (h + k) % ARRLEN(table);
			if (table[z].match && strcmp(icons_ext[i].match, table[z].match) == 0) {
				found = 1;
			}
		}
		assert(found);
	}

	log("hash_start: %u\n", (unsigned)hash_start);
	log("hash_mul  : %u\n", (unsigned)hash_mul);
	log("max_probe : %u\n", max_probe);

	printf("#define ICONS_PROBE_MAX %u\n\n", max_probe);
	printf("#define hash_start %uu\n", hash_start);
	printf("#define hash_mul   %uu\n", hash_mul);
	putchar('\n');

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
	printf("#define ICONS_MATCH_MAX %zuu\n", match_max);

	printf("struct icon_pair { const char match[%zu]; const char icon[%zu]; unsigned char color; };\n\n",
	       match_max, icon_max);

	printf("static struct icon_pair icons_ext[%zu] = {\n", ARRLEN(table));
	for (size_t i = 0; i < ARRLEN(table); ++i) {
		if (table[i].icon == NULL || table[i].icon[0] == '\0') /* skip empty entries */
			continue;
		printf("\t[%u] = {\"%s\", \"%s\", %d },\n",
		       (unsigned)i, table[i].match, table[i].icon,
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
	ASSERT(1u << z == ARRLEN(table));
	const unsigned char *s = (const unsigned char *)str;
	uint16_t hash = hash_start;
	for (size_t i = 0; *s && i < ICONS_MATCH_MAX; ++i, ++s) {
		uint16_t c = TOUPPER(*s);
		hash ^= c | (c << 8);
		hash *= hash_mul;
	}
	hash = (hash >> z) ^ hash;
	hash *= 40503u;
	hash >>= z;
	ASSERT(hash < ARRLEN(table));
	return hash;
}
