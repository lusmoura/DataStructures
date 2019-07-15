#ifndef PAIR_H
#define PAIR_H

#include <stdio.h>

typedef struct pair {
    void* first;
    void* second;
    size_t firstSize;
    size_t secondSize;
} Pair;

Pair* make_pair(void* first, void* second, size_t firstSize, size_t secondSize);
void* first_pair(Pair* pair);
void* second_pair(Pair* pair);
void destroy_pair(Pair* pair);

#endif