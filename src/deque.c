#include "deque.h"
#include "utils.h"

Deque* create_deque(size_t elemSize) {
    return create_list(elemSize);
}

void destroy_deque(Deque* deque) {
    destroy_list(deque);
}

bool push_back_deque(Deque* deque, void* content) {
    return push_back_list(deque, content);
}

bool push_front_deque(Deque* deque, void* content) {
    return push_front_list(deque, content);
}

bool pop_back_deque(Deque* deque) {
    return pop_back_list(deque);
}

bool pop_front_deque(Deque* deque) {
    return pop_front_list(deque);
}

void* front_deque(Deque* deque) {
    return deque->begin->content;
}

void* back_deque(Deque* deque) {
    return deque->end->content;
}

size_t size_deque(Deque* deque) {
    return deque->size;
}

bool is_empty_deque(Deque* deque) {
    return deque->size == 0;
}
