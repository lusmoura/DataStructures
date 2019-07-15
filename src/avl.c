#include "avl.h"
#include <stdlib.h>
#include <stdio.h>

int max_avl(int a, int b) {
    return (a > b) ? a : b;
}

int abs(int a) {
    return a > 0 ? a : -a;
}

int amount_of_chlidren(AvlNode* node) {
    return (node->left != NULL)  + (node->right != NULL);
}

int get_height(AvlNode* node) {
    return (node == NULL) ? -1 : node->height;
}

int get_balance_factor(AvlNode *n) {
    return get_height(n->left) - get_height(n->right);
}

AvlNode* create_node_avl(elem x) {
    AvlNode* node = calloc(1, sizeof(AvlNode));
    node->content = x;
    node->height = 1;
  
    return node;
}

void recursive_destroy_avl(AvlNode *n) {
    if (n == NULL) return;
    recursive_destroy_avl(n->left);
    recursive_destroy_avl(n->right);
    free(n);
}

AvlNode* search_node_avl(AvlNode* node, elem x) {
    if (node == NULL || node->content == x) return node;
    if (node->content > x) return search_node_avl(node->left, x);
    if (node->content < x) return search_node_avl(node->right, x);
    return NULL;
}

AvlNode* left_rotation(AvlNode* node) {
    AvlNode* newRoot = node->right;
    node->right = newRoot->left;
    newRoot->left = node;

    node->height = 1 + max_avl(get_height(node->left), get_height(node->right));
    newRoot->height = 1 + max_avl(get_height(newRoot->left), get_height(newRoot->right));

    return newRoot;
}

AvlNode* right_rotation(AvlNode* node) {
    AvlNode* newRoot = node->left;
    node->left = newRoot->right;
    newRoot->right = node;

    node->height = 1 + max_avl(get_height(node->left), get_height(node->right));
    newRoot->height = 1 + max_avl(get_height(newRoot->left), get_height(newRoot->right));

    return newRoot;
}

AvlNode* left_right_rotation(AvlNode* node) {
    node->left = left_rotation(node->left);
    return right_rotation(node);
}

AvlNode* right_left_rotation(AvlNode* node) {
    node->right = right_rotation(node->right);
    return left_rotation(node);
}

AvlNode* bring_balance(AvlNode* node) {
    int balance = get_balance_factor(node);
  
    if (balance >= 0)
        return get_balance_factor(node->left) < 0 ? node = left_right_rotation(node) : right_rotation(node);
    else
        return get_balance_factor(node->right) > 0 ? node = right_left_rotation(node) : left_rotation(node);
}

AvlNode* insert_node_avl(AvlNode* node, elem x, bool* erro) {

    if (node == NULL) node = create_node_avl(x);
    else if (node->content > x)  node->left = insert_node_avl(node->left, x, erro);
    else if (node->content < x)  node->right = insert_node_avl(node->right, x, erro);
    else{
        *erro = true; 
        return node;
    }

    node->height = 1 + max_avl(get_height(node->left), get_height(node->right));
    int balanceFactor = get_balance_factor(node);
    if (abs(balanceFactor) > 1)  return bring_balance(node);

    return node;
}

AvlNode* get_greatest_left_avl(AvlNode* node) {
    AvlNode* target = node->left;
    
    while(target->right != NULL) {
       target = target->right;
    }

    return target;
}

AvlNode* remove_node_avl(AvlNode* node, elem x, bool* erro) {
    if (node == NULL) {
        *erro = true;
        return NULL;
    }
  
    AvlNode *aux;

    if (node->content > x) node->left = remove_node_avl(node->left, x, erro);
    else if (node->content < x) node->right = remove_node_avl(node->right, x, erro);
    else  {
        int children = amount_of_chlidren(node);
        if (children == 0) {
            free(node);
            node = NULL;
            return node;
    
        } else if (children == 1) {
            aux = (node->left != NULL) ? node->left : node->right;;
            free(node);
            node = aux;
        } else {
            aux = get_greatest_left_avl(node);
            node->content = aux->content;
            node->left = remove_node_avl(node->left, node->content, erro);
        }
    }

    node->height = 1 + max_avl(get_height(node->left), get_height(node->right));
    int balanceFactor = get_balance_factor(node);
    if (abs(balanceFactor) > 1)  return bring_balance(node);

    return node;
}

void recursive_print_avl(AvlNode* n, int hight) {
    if (n == NULL) {
        putchar('\n');
        return;
    }

    recursive_print_avl(n->right, hight + 1);
    for (int i = 0; i < hight; i++) putchar('\t');
    printf("[%d]\n", n->content);
    recursive_print_avl(n->left, hight + 1);
}


Avl *create_avl() {
    Avl* avl = calloc(1, sizeof(Avl));
    return avl;
}

void destroy_avl(Avl* avl) {
    recursive_destroy_avl(avl->root);
    if (avl != NULL) free(avl);
}

bool search_avl(Avl* avl, elem x) {
    AvlNode* node = search_node_avl(avl->root, x);
    return (node != NULL);
}

bool insert_avl(Avl* avl, elem x) {
    bool erro = false;
    avl->root = insert_node_avl(avl->root, x, &erro);
    return erro;
}

bool remove_avl(Avl* avl, elem x) {
    bool erro = false;
    avl->root = remove_node_avl(avl->root, x, &erro);
    return erro;
}

void print_avl(Avl* avl) {
    recursive_print_avl(avl->root, 0);
}