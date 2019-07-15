#include "list.h"
#include "deque.h"
#include "pair.h"
#include "queue.h"
#include "stack.h"
#include "trie.h"
#include "bst.h"
#include "avl.h"
#include "utils.h"
#include <stdio.h>
#include <stdlib.h>

void test_list() {
    printf("---------List--------\n");
    List* list = create_list(sizeof(int));
    int num = 1;
    push_front_list(list, &num);
    num = 2;
    push_front_list(list, &num);
    num = 3;
    push_back_list(list, &num);
    num = 4;
    push_in_pos_list(list, &num, 3);
    printf("List: ");
    print_int_list(list);

    printf("Found in pos: %d\n", search_int_list(list, 10));

    pop_back_list(list);
    pop_front_list(list);
    printf("List: ");
    print_int_list(list);
    printf("front: %d\n", *(int*)front_list(list));
    printf("back: %d\n", *(int*)back_list(list));

    destroy_list(list);
}

void test_deque() {
    printf("\n---------Deque--------\n");
    Deque* deque = create_queue(sizeof(int));
    int num = 1;
    push_front_deque(deque, &num);
    num = 2;
    push_front_deque(deque, &num);
    num = 3;
    push_back_deque(deque, &num);
    printf("Deque: ");
    print_int_list(deque);

    pop_back_list(deque);
    pop_front_list(deque);
    printf("Deque: ");
    print_int_list(deque);
    printf("front: %d\n", *(int*)front_deque(deque));
    printf("back: %d\n", *(int*)back_deque(deque));

    destroy_deque(deque);
}

void test_pair() {
    printf("\n---------Pair--------\n");
    int num = 1;
    int num2 = 2;
    Pair* pair = make_pair(&num, &num2, sizeof(int), sizeof(int));
    printf("%d, %d\n", *(int*)first_pair(pair), *(int*)second_pair(pair));
    destroy_pair(pair);
}

void test_queue() {
    printf("\n---------Queue--------\n");
    Queue* queue = create_queue(sizeof(int));
    int num = 1;
    push_queue(queue, &num);
    printf("Queue: ");
    print_int_list(queue);
    num = 2;
    push_queue(queue, &num);
    printf("Queue: ");
    print_int_list(queue);
    num = 3;
    push_queue(queue, &num);
    printf("Queue: ");
    print_int_list(queue);

    pop_queue(queue);
    printf("Queue: ");
    print_int_list(queue);
    pop_queue(queue);
    printf("Queue: ");
    print_int_list(queue);
    pop_queue(queue);
    printf("Queue: ");
    print_int_list(queue);

    destroy_queue(queue);
}

void test_stack() {
    printf("\n---------Stack--------\n");
    Stack* stack = create_stack(sizeof(int));
    int num = 1;
    push_stack(stack, &num);
    printf("Stack: ");
    print_int_list(stack);
    num = 2;
    push_stack(stack, &num);
    printf("Stack: ");
    print_int_list(stack);
    num = 3;
    push_stack(stack, &num);
    printf("Stack: ");
    print_int_list(stack);

    pop_stack(stack);
    printf("Stack: ");
    print_int_list(stack);
    pop_stack(stack);
    printf("Stack: ");
    print_int_list(stack);
    pop_stack(stack);
    printf("Stack: ");
    print_int_list(stack);

    destroy_stack(stack);
}
 
void test_trie() {
    printf("\n---------Trie--------\n");
    Trie* trie = create_trie();
    char* word = "teste";
    insert_word(trie, word);
    word = "test";
    insert_word(trie, word);
    word = "top";
    insert_word(trie, word);
    printf("%d\n", search_word(trie, word));
    print_trie(trie);

    remove_word(trie, word);
    print_trie(trie);
    destroy_trie(trie);
}

void test_bst() {
    printf("\n---------Binary Search Tree--------\n");
    Bst* bst = create_bst();
    printf("Tree: ");
    insert_bst(bst, 2);
    insert_bst(bst, 1);
    insert_bst(bst, 1);
    insert_bst(bst, 3);
    insert_bst(bst, 4);
    print_bst(bst);

    printf("\n");

    remove_bst(bst, 2);
    remove_bst(bst, 1);
    printf("Tree: ");
    print_bst(bst);

    printf("%d\n", search_bst(bst, 10));

    destroy_bst(bst);
}

void test_avl() {
    printf("\n---------AVL--------\n");
    Avl* avl = create_avl();
    insert_avl(avl, 1);
    insert_avl(avl, 1);
    insert_avl(avl, 2);
    insert_avl(avl, 3);
    insert_avl(avl, 4);
    printf("Tree: ");
    print_avl(avl);

    remove_avl(avl, 2);
    printf("Tree: ");
    print_avl(avl);

    printf("%d\n", search_avl(avl, 1));

    destroy_avl(avl);
}

int main() {
    test_list();
    test_deque();
    test_pair();
    test_queue();
    test_stack();
    test_trie();
    test_bst();
    test_avl();

    return 0;
}