//
// Created by tiger on 6/6/2022.
//

#ifndef MINI_HASHTABLE_H
#define MINI_HASHTABLE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR_LENGTH 255
#define TABLE_SIZE 4095

typedef struct
{
    char str[MAX_STR_LENGTH];
    int pos;
} ht_entry_t;

static ht_entry_t* hash_table[TABLE_SIZE];
static int ht_size = 0;

void ht_init();
void ht_free();

void ht_print();

int ht_insert(ht_entry_t* entry);
ht_entry_t* ht_search(char* str);

#endif // MINI_HASHTABLE_H
