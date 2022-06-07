//
// Created by tiger on 6/1/2022.
//

#include "lzw.h"

int lzw_encode(FILE* f_in, FILE* f_out)
{
    ht_init();

    char word[MAX_STR_LENGTH] = {'\0'};
    int word_length = 0;

    char c;

    while (fread(&c, sizeof(char), 1, f_in))
    {
        char new_word[MAX_STR_LENGTH] = {'\0'};

        strncat(new_word, word, strnlen(word, MAX_STR_LENGTH));
        strncat(new_word, &c, 1);

        ht_entry_t* entry = ht_search(new_word);
        if (entry != NULL)
        {
            strcpy(word, new_word);
            word_length++;
        }
        else
        {
            ht_entry_t* word_pos = ht_search(word);
            if (word_pos != NULL)
            {
                fwrite((const void*)&word_pos->pos, sizeof(int), 1, f_out);
                // printf("%d ", word_pos->pos);
            }

            ht_entry_t* new_entry = malloc(sizeof(ht_entry_t));

            strcpy(new_entry->str, new_word);

            ht_insert(new_entry);

            word[0] = c;
            word[1] = '\0';
            word_length = 1;
        }
    }

    ht_free();

    return 0;
}

int lzw_decode(FILE* f_in, FILE* f_out)
{
    int c;
    while (fread(&c, sizeof(int), 1, f_in))
    {
        printf("%d ", c);
    }
    return 0;
}