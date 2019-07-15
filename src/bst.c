#include "bst.h"
#include <stdlib.h>

int amount_of_children(BstNode* node) {
    return (node->left != NULL) + (node->right != NULL);
}

BstNode* create_node_bst(elem x) {
    BstNode *node = malloc(sizeof(BstNode));
    
    node->left = node->right = NULL;
    node->content = x;
    
    return node;
}

void recursive_destroy_bst(BstNode* node) {
    if(node == NULL) return;
    recursive_destroy_bst(node->left);
    recursive_destroy_bst(node->right);
    free(node);
}

BstNode* search_node_bst(BstNode* node, elem x) {
    BstNode* curr = node;
    
    while(curr != NULL && curr->content != x){
        if(curr->content > x) curr = curr->left;
        else if(curr->content < x) curr = curr->right;
    }

    return curr;
}

BstNode* insert_node_bst(BstNode *node, elem x){
    if (node == NULL) return create_node_bst(x); 
  
    if (x < node->content) 
        node->left  = insert_node_bst(node->left, x); 
    else if (x > node->content) 
        node->right = insert_node_bst(node->right, x);    
  
    return node; 
} 

BstNode* get_greatest_left(BstNode* node) {
    BstNode* target = node->left;
    
    while(target->right != NULL) {
       target = target->right;
    }

    return target;
}

BstNode* remove_node_bst(BstNode* node, elem x)  {
    if (node == NULL) return NULL;
  
    if (x < node->content) 
        node->left = remove_node_bst(node->left, x);  
    else if (x > node->content) 
        node->right = remove_node_bst(node->right, x); 
    else { 
        int children = amount_of_children(node);
        BstNode* aux;
        
        if (children == 0) {
            free(node);
            return NULL;

        } else if (children == 1) {
            aux = node->left == NULL ? node->right : node->left;
            free(node);
            return aux;
        }
  
        aux = get_greatest_left(node);
        node->content = aux->content;
        node->right = remove_node_bst(node->right, aux->content);
        node->left = NULL;
        free(aux);
    
    } 

    return node; 
} 

void recursive_print_bst(BstNode* node, int hight) {
    if (node == NULL) {
        putchar('\n');
        return;
    }
    
    recursive_print_bst(node->right, hight + 1);
    for (int i = 0; i < hight; i++) putchar('\t');
    printf("[%d]\n", node->content);
    recursive_print_bst(node->left, hight + 1);
}


Bst *create_bst() {
    Bst* bst = calloc(1, sizeof(Bst));
    return bst;
}

void destroy_bst(Bst* bst) {
    recursive_destroy_bst(bst->root);
    if (bst != NULL) free(bst);
}

bool search_bst(Bst* bst, elem x) {
    BstNode* ans = search_node_bst(bst->root, x);
    return (ans != NULL && ans->content == x);
}

void insert_bst(Bst* bst, elem x) {
    bst->root = insert_node_bst(bst->root, x);
}

void remove_bst(Bst* bst, elem x) {
    bst->root = remove_node_bst(bst->root, x);
}

void print_bst(Bst* bst) {
    recursive_print_bst(bst->root, 0);
}