#ifndef DEQUE_H
#define DEQUE_H

#include <stdio.h>
#include "list.h"

typedef List Deque;

Deque* create_deque(size_t elemSize);
void destroy_deque(Deque* deque);

bool push_back_deque(Deque* deque, void* val);
bool push_front_deque(Deque* deque, void* val);

bool pop_back_deque(Deque* deque);
bool pop_front_deque(Deque* deque);

void* front_deque(Deque* deque);
void* back_deque(Deque* deque);

size_t size_deque(Deque* deque);
bool is_empty_deque(Deque* deque);

#endif