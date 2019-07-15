#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include "list.h"

typedef List Stack;

Stack* create_stack(size_t elemSize);
void destroy_stack(Stack* stack);

bool push_stack(Stack* stack, void* val);

bool pop_stack(Stack* stack);

void* front_stack(Stack* stack);

size_t size_stack(Stack* stack);
bool is_empty_stack(Stack* stack);

#endif