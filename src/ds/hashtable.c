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

ht_t* ht_init()
{
    ht_t* hash_table = malloc(sizeof(ht_t));
    hash_table->size = 0;

    for (int i = 0; i < TABLE_SIZE; ++i)
    {
        hash_table->entry[i] = NULL;
    }

    for (int i = 0; i < 255; ++i)
    {
        ht_entry_t* entry = malloc(sizeof(ht_entry_t));

        entry->str[0] = (char)i;
        entry->str[1] = '\0';

        ht_insert(hash_table, entry);
    }

    return hash_table;
}

int ht_insert(ht_t* hash_table, ht_entry_t* entry)
{
    if (entry == NULL || hash_table == NULL || hash_table->size >= TABLE_SIZE)
        return 0;

    unsigned int index = hash(entry->str);

    if (hash_table->entry[index] != NULL) // collision
    {
        for (int i = 0; i < TABLE_SIZE; ++i)
        {
            if (hash_table->entry[i] == NULL)
            {
                index = i;
            }
        }
    }

    entry->pos = hash_table->size;

    hash_table->entry[index] = entry;

    hash_table->size++;

    return 1;
}

ht_entry_t* ht_search(ht_t* hash_table, char* str)
{
    unsigned int index = hash(str);
    if (hash_table->entry[index] != NULL && strcmp(hash_table->entry[index]->str, str) == 0)
    {
        return hash_table->entry[index];
    }
    return hash_table->entry[index];
}

void ht_print(ht_t* hash_table)
{
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        if (hash_table->entry[i] == NULL)
        {
            printf("\t%i\t---\n", i);
        }
        else
        {
            printf("\t%i\t%s\n", i, hash_table->entry[i]->str);
        }
    }
}

void ht_free(ht_t* hash_table)
{
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        if (hash_table->entry[i] != NULL)
        {
            free(hash_table->entry[i]);
        }
    }

    free(hash_table);
}
