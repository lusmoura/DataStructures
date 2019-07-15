#ifndef AVL_H
#define AVL_H

typedef int elem;

#include <stdbool.h>

typedef struct avlNode {
    elem content;
    int height;
    struct avlNode* left;
    struct avlNode* right;
} AvlNode;

typedef struct avl{
  AvlNode* root;
} Avl;

Avl* create_avl();

bool insert_avl(Avl* avl, elem x);
bool search_avl(Avl* avl, elem x);
void print_avl(Avl* avl);
bool remove_avl(Avl* avl, elem x);
void destroy_avl(Avl* avl);

#endif