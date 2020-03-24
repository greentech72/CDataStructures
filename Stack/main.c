#include <stdio.h>
#include "stack.h"

int main() {
	printf("Stack\n");
	
	stack_t* s = stack_create(10);
	printf("Stack created\n");

	for (int i = 0; i < 20; i++) {
		int* a = malloc(sizeof(int));
		*a = i;
		stack_push(s, a);
	}
	printf("Pushed 20 elements [0, 20)\n");

	for (int i = 0; i < 3; i++) {
		int* a = stack_top(s);
		printf("%d ", *a);
		stack_pop(s);
		free(a);
	}
	printf("\n");
	printf("Poped 3 elements\n");
	


	stack_clear(s);
	printf("After clear function and is_empty() : %d (1 - true)\n", stack_is_empty(s));

	stack_free(s);
	printf("Stack deleted\n");
	
	return 0;
}

