#include "pair.h"
#include "utils.h"
#include <stdlib.h>
#include <string.h>

Pair* make_pair(void* first, void* second, size_t firstSize, size_t secondSize) {
    Pair* pair = (Pair*)calloc(1, sizeof(Pair));

    pair->first = malloc(firstSize);
    pair->second = malloc(secondSize);
    memcpy(pair->first, first, firstSize);
    memcpy(pair->second, second, secondSize);
    
    pair->firstSize = firstSize;
    pair->secondSize = secondSize;

    return pair;
}

void* first_pair(Pair* pair) {
    return pair->first;
}

void* second_pair(Pair* pair) {
    return pair->second;
}

void destroy_pair(Pair* pair) {
    if (pair == NULL) return;
    free(pair->first);
    free(pair->second);
    free(pair);
}