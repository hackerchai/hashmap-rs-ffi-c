#include <stdarg.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

typedef struct HashMap_CString__CString HashMap_CString__CString;

struct HashMap_CString__CString *hashmap_new(void);

void hashmap_insert(struct HashMap_CString__CString *map, const char *key, const char *value);

const char *hashmap_get(struct HashMap_CString__CString *map, const char *key);

void hashmap_free(struct HashMap_CString__CString *map);
