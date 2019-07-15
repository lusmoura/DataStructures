#ifndef LIST_H
#define LIST_H

#include <stdio.h>
#include <stdbool.h>

typedef struct node {
    void* content;
    struct node* prev;
    struct node* next;
} Node;

typedef struct list {
    size_t elemSize;
    size_t size;
    Node* begin;
    Node* end;
} List;

List* create_list(size_t elemSize);
void destroy_list(List* list);

bool push_in_pos_list(List* list, void* content, int pos);
bool push_back_list(List* list, void* content);
bool push_front_list(List* list, void* content);

bool pop_from_pos_list(List* list, int pos);
bool pop_back_list(List* list);
bool pop_front_list(List* list);

void* front_list(List* list);
void* back_list(List* list);

size_t size_list(List* list);
bool is_empty_list(List* list);
int search_int_list(List* list, int target);
void print_int_list(List* list);

#endif