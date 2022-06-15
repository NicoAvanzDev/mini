//
// Created by tiger on 6/10/2022.
//

#include "../src/ds/hashtable.h"

#define ASSERT_NOT_NULL(ptr)                                                                                           \
    if (ptr == NULL)                                                                                                   \
    {                                                                                                                  \
        printf("%s:%d: %s is NULL\n", __FILE__, __LINE__, #ptr);                                                       \
        return 1;                                                                                                      \
    }

int main()
{
    ht_t* hash_table = ht_init();
    ASSERT_NOT_NULL(hash_table);
    return 0;
}