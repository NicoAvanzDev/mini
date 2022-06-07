//
// Created by tiger on 6/1/2022.
//

#ifndef MINI_LZW_H
#define MINI_LZW_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../ds/hashtable.h"

int lzw_encode(FILE* f_in, FILE* f_out);
int lzw_decode(FILE* f_in, FILE* f_out);

#endif // MINI_LZW_H
