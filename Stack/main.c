#include <stdio.h>
#include "stack.h"

int main() {
	printf("Stack\n");
	
	stack_t* s = stack_create(150);
	printf("Stack created\n");

	for (int i = 0; i < 10; i++) {
		int* a = malloc(sizeof(int));
		*a = i;
		stack_push(s, a);
	}
	printf("Pushed 10 elements [0, 10)\n");

	for (int i = 0; i < 3; i++) {
		int* a = stack_top(s);
		printf("%d ", *a);
		stack_pop(s);
		free(a);
	}
	printf("\n");
	printf("Poped 3 elements 9, 8, 7\n");

	stack_clear(s);
	printf("After clear function and is_empty() : %d (1 - true)\n", stack_is_empty(s));

	stack_free(s);
	printf("Stack deleted\n");
	
	return 0;
}