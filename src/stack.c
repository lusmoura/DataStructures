#include "stack.h"

Stack* create_stack(size_t elemSize) {
    return create_list(elemSize);
}

void destroy_stack(Stack* stack) {
    destroy_list(stack);
}

bool push_stack(Stack* stack, void* content) {
    return push_front_list(stack, content);
}

bool pop_stack(Stack* stack) {
    return pop_front_list(stack);
}

void* front_stack(Stack* stack) {
    return stack->begin;
}

size_t size_stack(Stack* stack) {
    return stack->size;
}

bool is_empty_stack(Stack* stack) {
    return stack->size == 0;
}