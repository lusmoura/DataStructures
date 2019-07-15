#include "queue.h"

Queue* create_queue(size_t elemSize) {
    return create_list(elemSize);
}

void destroy_queue(Queue* queue) {
    destroy_list(queue);
}

bool push_queue(Queue* queue, void* content) {
    return push_back_list(queue, content);
}

bool pop_queue(Queue* queue) {
    return pop_front_list(queue);
}

void* back_queue(Queue* queue) {
    return queue->end;
}

size_t size_queue(Queue* queue) {
    return queue->size;
}

bool is_empty_queue(Queue* queue) {
    return queue->size == 0;
}