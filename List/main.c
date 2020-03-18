#include "list.h"
#include <stdio.h>

int main() {
	printf("List\n");

	struct node* a = list_create();
	printf("Created first node\n");

	for (int i = 0; i < 10; i++) {
		int* b = malloc(sizeof(int));
		*b = i;
		list_push_back(a, b);
	}

	printf("Push Back 10 integers\n");
	list_print_as_int(a);

	for (int i = 0; i < 10; i++) {
		int* b = malloc(sizeof(int));
		*b = i;
		list_push_top(a, b);
	}

	printf("Push Top 10 integers\n");
	list_print_as_int(a);

	printf("There are %d elements\n", list_size(a));

	printf("At 5 th position is %d\n", *(int*)list_at(a, 5));

	printf("After pop from top\n");
	list_pop_top(&a);
	list_print_as_int(a);
	
	printf("After pop from back\n");
	list_pop_back(a);
	list_print_as_int(a);
	
	for (int i = 4; i < 9; i++) {
		list_erase(a, 4);
	}

	printf("After erase (4, 9]\n");
	list_print_as_int(a);
	
	for (int i = 4; i < 7; i++) {
		int *b = malloc(sizeof(int));
		*b = i;
		list_insert(a, b, i);
	}
	
	printf("After insert (4, 7]\n");
	list_print_as_int(a);

	list_clear(a);
	printf("After clear and is_empty functions : %d (1 - is empty)\n", list_is_empty(a));

	list_free(a);
	printf("Deleted whole list\n");

	return 0;
}