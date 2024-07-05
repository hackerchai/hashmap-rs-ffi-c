#include <stdio.h>
#include <stdlib.h>
#include "hashmap_ffi.h"

int main() {
    struct HashMap_CString__CString *map = hashmap_new();
    if (!map) {
        fprintf(stderr, "Failed to create the hashmap.\n");
        return EXIT_FAILURE;
    }

    hashmap_insert(map, "key1", "value1");
    hashmap_insert(map, "key2", "value2");
    hashmap_insert(map, "key3", "value3");

    const char *value;
    value = hashmap_get(map, "key1");
    if (value) {
        printf("The value for 'key1' is: %s\n", value);
    } else {
        printf("Value for 'key1' not found.\n");
    }

    value = hashmap_get(map, "key2");
    if (value) {
        printf("The value for 'key2' is: %s\n", value);
    } else {
        printf("Value for 'key2' not found.\n");
    }

    value = hashmap_get(map, "key3");
    if (value) {
        printf("The value for 'key3' is: %s\n", value);
    } else {
        printf("Value for 'key3' not found.\n");
    }

    value = hashmap_get(map, "nonexistent");
    if (value) {
        printf("The value for 'nonexistent' is: %s\n", value);
    } else {
        printf("Value for 'nonexistent' not found.\n");
    }

    hashmap_free(map);

    return EXIT_SUCCESS;
}

