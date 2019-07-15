#include "list.h"
#include <stdlib.h>
#include <string.h>
#include "utils.h"

void* front_list(List* list) {
    return list == NULL ? NULL : list->begin->content;
}

void* back_list(List* list) {
    return list == NULL ? NULL : list->end->content;
}

size_t size_list(List* list) {
    return list == NULL ? 0 : list->size;
}

bool is_empty_list(List* list) {
    return list == NULL ? true : (list->size == 0);
}

void increase_size(List* list) {
    if (list != NULL) list->size++;
}

void decrease_size(List* list) {
    if (list != NULL) list->size--;
}

Node* create_node(void* content, int size) {
    Node* node = (Node*)calloc(1, sizeof(Node));
    if (node == NULL) return NULL;

    node->content = malloc(size);
    memcpy(node->content, content, size);
    
    node->next = NULL;
    node->prev = NULL;
    
    return node;
}

List* create_list(size_t elemSize) {
    List* list = (List*)calloc(1, sizeof(List));
    if (list == NULL) return NULL;

    list->begin = NULL;
    list->end = NULL;
    list->size = 0;
    list->elemSize = elemSize;

    return list;
}

Node* get_node_in_pos(List* list, int pos) {
    Node* curr = list->begin;
    while (pos--) curr = curr->next;
    return curr->prev;
}

void destroy_list(List* list) {
    if (list == NULL) return;
    
    while (!is_empty_list(list)) 
        pop_front_list(list);

    free(list);
}

bool push_in_pos_list(List* list, void* content, int pos) {
    if (!list || pos < 0 || pos > size_list(list)) return false;

    if (pos == 0) 
        return push_front_list(list, content);
    else if (pos == size_list(list)) 
        return push_back_list(list, content);

    Node* curr = get_node_in_pos(list, pos);
    Node* newNode = create_node(content, list->elemSize);
    if (newNode == NULL) return false;

    curr->next->prev = newNode;
    newNode->next = curr->next;
    newNode->prev = curr;
    curr->next = newNode;

    list->size++;
    return true;
}

bool push_back_list(List* list, void* content) {
    if (!list) return false;
    
    if (is_empty_list(list))
        return push_front_list(list, content);

    Node* newNode = create_node(content, list->elemSize);
    if (newNode == NULL) return false;

    list->end->next = newNode;
    newNode->prev = list->end;
    list->end = newNode;

    increase_size(list);
    return true;
}

bool push_front_list(List* list, void* content) {
    if (!list) return false;
    
    Node* newNode = create_node(content, list->elemSize);
    if (newNode == NULL) return false;

    if (is_empty_list(list)) {
        list->begin = newNode;
        list->end = newNode;
    } else {
        newNode->next = list->begin;
        list->begin->prev = newNode;
        list->begin = newNode;
    }
    
    increase_size(list);
    return true;
}

bool pop_from_pos_list(List* list, int pos) {
    if (!list || pos < 0 || pos >= size_list(list)) return false;
    
    if (pos == 0)
        return pop_front_list(list);
    else if (pos == size_list(list) - 1)
        return pop_back_list(list);

    Node* toBeRemoved = NULL;
    toBeRemoved = get_node_in_pos(list, pos+1);
    toBeRemoved->next->prev = toBeRemoved->prev;
    toBeRemoved->prev->next = toBeRemoved->next;

    if (toBeRemoved->content != NULL) free(toBeRemoved->content);
    if (toBeRemoved != NULL) free(toBeRemoved);
    
    decrease_size(list);
    return true;
}

bool pop_front_list(List* list) {
    if (!list || is_empty_list(list)) return false;

    Node* toBeRemoved = list->begin;
    list->begin = list->begin->next;
    if (list->begin != NULL) list->begin->prev = NULL;

    if (toBeRemoved->content != NULL) free(toBeRemoved->content);
    if (toBeRemoved != NULL) free(toBeRemoved);
    
    decrease_size(list);
    return true;
}

bool pop_back_list(List* list) {
    if (!list || is_empty_list(list)) return false;
        
    if (size_list(list) == 1) 
        return pop_front_list(list);
    
    Node* toBeRemoved = list->end;
    list->end = list->end->prev;
    if (list->end != NULL) list->end->next = NULL;

    if (toBeRemoved != NULL) free(toBeRemoved);
    decrease_size(list);
    return true;
}

int search_int_list(List* list, int target) {
    Node* currNode = list->begin;
    int pos = -1;
    int currPos = 0;

    while (currNode != NULL) {
        if (*(int*)(currNode->content) == target) {
            pos = currPos;
            break;
        }

        currNode = currNode->next;
        currPos++;
    }

    return pos;
}

void print_int_list(List* list) {
    Node* curr = list->begin;
    
    while (curr != NULL) {
        printf("%d ", *(int*)curr->content);
        curr = curr->next;
    }

    printf("\n");
}