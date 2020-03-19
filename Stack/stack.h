#ifndef STACK_H
#define STACK_H

#include <stdlib.h>
#include <stdint.h>

typedef struct stack {
	void** data;
	size_t index;
	size_t size;
}stack_t;

stack_t* stack_create(size_t size);

void stack_free(stack_t* stack);

int stack_is_empty(stack_t* stack);

void* stack_top(stack_t* stack);

void stack_push(stack_t* stack, void* data);

void stack_pop(stack_t* stack);

void stack_clear(stack_t* stack);

#endif