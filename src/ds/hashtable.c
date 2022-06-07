//
// Created by tiger on 6/6/2022.
//

#include "hashtable.h"

unsigned int hash(char* str)
{
    size_t len = strnlen(str, MAX_STR_LENGTH);
    unsigned int hash_value = 0;
    for (int i = 0; i < len; i++)
    {
        hash_value += str[i];
        hash_value = (hash_value * str[i]) % TABLE_SIZE;
    }
    return hash_value;
}

void ht_init()
{
    for (int i = 0; i < TABLE_SIZE; ++i)
    {
        hash_table[i] = NULL;
    }

    for (int i = 0; i < 255; ++i)
    {
        ht_entry_t* entry = malloc(sizeof(ht_entry_t));

        entry->str[0] = (char)i;
        entry->str[1] = '\0';

        ht_insert(entry);
    }
}

int ht_insert(ht_entry_t* entry)
{
    if (entry == NULL || ht_size >= TABLE_SIZE)
        return 0;

    unsigned int index = hash(entry->str);

    if (hash_table[index] != NULL) // collision
    {
        for (int i = 0; i < TABLE_SIZE; ++i)
        {
            if (hash_table[i] == NULL)
            {
                index = i;
            }
        }
    }

    entry->pos = ht_size;

    hash_table[index] = entry;

    ht_size++;

    return 1;
}

ht_entry_t* ht_search(char* str)
{
    unsigned int index = hash(str);
    if (hash_table[index] != NULL && strcmp(hash_table[index]->str, str) == 0)
    {
        return hash_table[index];
    }
    return hash_table[index];
}

void ht_print()
{
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        if (hash_table[i] == NULL)
        {
            printf("\t%i\t---\n", i);
        }
        else
        {
            printf("\t%i\t%s\n", i, hash_table[i]->str);
        }
    }
}

void ht_free()
{
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        if (hash_table[i] != NULL)
        {
            free(hash_table[i]);
        }
    }
}
