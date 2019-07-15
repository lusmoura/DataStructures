#ifndef BST_H
#define BST_H

#include <stdio.h>
#include <stdbool.h>

typedef int elem;

typedef struct bstNode {
    elem content;
    struct bstNode* left;
    struct bstNode* right;
} BstNode;

typedef struct _bst {
    BstNode* root;
} Bst;

Bst* create_bst();
bool insert_bst(Bst* bst, elem x);
bool search_bst(Bst* bst, elem x);
bool remove_bst(Bst* bst, elem x);
void print_bst(Bst* bst);
void destroy_bst(Bst* bst);

#endif