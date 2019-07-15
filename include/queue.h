#ifndef QUEUE_H
#define QUEUE_H

#include <stdio.h>
#include "list.h"

typedef List Queue;

Queue* create_queue(size_t elemSize);
void destroy_queue(Queue* queue);

bool push_queue(Queue* queue, void* val);

bool pop_queue(Queue* queue);

void* back_queue(Queue* queue);

size_t size_queue(Queue* queue);
bool is_empty_queue(Queue* queue);

#endif