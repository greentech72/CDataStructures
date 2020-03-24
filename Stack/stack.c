#include "stack.h"

static void stack_resize(stack_t* stack) {
	stack->size *= 2;
	stack->data = realloc(stack->data, stack->size * sizeof(void*));
}

stack_t* stack_create(size_t size) {
	stack_t* n = malloc(sizeof(stack_t));
	if (size == 0) 
		n->size = 100;
	else
		n->size = size;
	n->data = malloc(sizeof(void*) * n->size);
	n->index = 0;
	return n;
}

void stack_free(stack_t* stack) {
	free(stack->data);
	free(stack);
}

int stack_is_empty(stack_t* stack) {
	if (stack->index == 0) {
		return 1;
	}
	return 0;
}

void* stack_top(stack_t* stack) {
	if (stack->index == NULL)
		return NULL;
	return *(((size_t*)stack->data) + stack->index - 1);
}

void stack_push(stack_t* stack, void* data) {
	if (stack->index == stack->size)
		stack_resize(stack);
	*(((size_t*)stack->data) + stack->index++) = data;
}

void stack_pop(stack_t* stack) {
	if (stack->index == 0)
		return;
	stack->index--;
	*(((size_t*)stack->data) + stack->index) = NULL;
}

void stack_clear(stack_t* stack) {
	while (stack->index != 0) {
		stack_pop(stack);
	}
}
