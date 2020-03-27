#include <stdio.h>
#include "linked_list.h"

int cmp(int* a) {
	if (a == NULL) {
		return 0;
	}
	if (*a >= 3 && *a < 5) {
		return 1;
	}
	return 0;
}

int cmp_zero(int* a) {
	if (*a == 0)
		return 1;
	return 0;
}

int main() {
	printf("Linked List\n");

	lln_t* b = ll_create();
	printf("Linked List created\n");

	int* data = malloc(sizeof(int) * 10);
	for(int i = 0; i < 10; i++){
		*(data + i) = i;
		ll_push_top(&b, (data + i));
	}
	printf("Linked List pushhed 10 items from top\n");
	ll_print_as_int(b);

	printf("Front element : %d\n", *(int*)ll_front(b));

	int* data2 = malloc(sizeof(int) * 10);
	for (int i = 0; i < 10; i++) {
		*(data2 + i) = i;
		ll_push_back(&b, (data2 + i));
	}
	printf("Linked List pushhed 10 items from back\n");
	ll_print_as_int(b);

	printf("Last element : %d\n", *(int*)ll_end(b));

	ll_pop_top(&b);
	ll_pop_top(&b);
	printf("Pop from top 2 times\n");
	ll_print_as_int(b);

	for (int i = 0; i < 5; i++) {
		ll_pop_back(b);
	}

	printf("Pop from top 5 times\n");
	ll_print_as_int(b);

	printf("Size of the list : %d\n", ll_size(b));

	printf("Element on the 5 th position : %d\n", *(int*)ll_at(b, 5));

	ll_erase(b, 9);
	ll_erase(b, 2);

	printf("After erase 9 2 \n");
	ll_print_as_int(b);

	int a = 50;
	ll_insert(b, &a, 9);
	ll_insert(b, &a, 2);
	printf("After insert 50 on 9 th and 2 nd position\n");
	ll_print_as_int(b);

	ll_remove_if(&b, cmp);
	printf("After cmp function (>= 3 && < 5)\n");
	ll_print_as_int(b);

	ll_reverse(&b);
	ll_print_as_int(b);

	printf("Element 0 on the %d position\n", ll_find(b, cmp_zero));

	ll_clear(&b);
	printf("After clear size is %d\n", ll_size(b));

	free(data);
	free(data2);
	ll_free(b);
	printf("Linked List freed\n");

	return 0;
}