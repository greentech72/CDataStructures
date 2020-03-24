#include "list.h"

node_t* list_create() {
	node_t* ret = malloc(sizeof(node_t));
	ret->data = NULL;
	ret->next = NULL;
	return ret;
}

void list_free(node_t* begin) {
	node_t* next;
	while (begin->next != NULL) {
		next = begin->next;
		free(begin);
		begin = next;
	}
	free(begin);
}


int list_is_empty(node_t* begin) {
	// if true == 1 else -1
	if (begin->next == NULL) {
		return 1;
	}
	return 0;
}


size_t list_size(node_t* begin) {
	// O(n)
	node_t* curr = begin;
	size_t ret = 0;
	while (curr->next != NULL) {
		curr = curr->next;
		ret++;
	}
	return ret;
}

void* list_front(node_t* begin) {
	return begin->data;
}

void* list_end(node_t* begin) {
	node_t* curr = begin;
	while (curr->next->next != NULL) {
		curr = curr->next;
	}
	return curr->data;
}

void list_push_top(node_t* begin, void* data) {
	node_t *node = list_create();
	node->data = begin->data;
	begin->data = data;
	node->next = begin->next;
	begin->next = node;
}

void list_push_back(node_t* begin, void* data) {
	node_t* curr = begin;
	while (curr->next != NULL) {
		curr = curr->next;
	}
	curr->data = data;
	curr->next = list_create();
}

void list_pop_top(node_t** begin) {
	node_t* next = (*begin)->next;
	free(*begin);
	*begin = next;
}


void list_pop_back(node_t* begin) {
	node_t* curr = begin;
	while (curr->next->next != NULL) {
		curr = curr->next;
	}
	node_t* del = curr->next;
	free(del);
	curr->next = NULL;
}


void list_insert(node_t* begin, void* data, size_t pos) {
	node_t* curr = begin;
	size_t i = 0;
	while (i < pos) {
		if (curr->next == NULL)
			return;
		curr = curr->next;
		i++;
	}
	if (curr->next == NULL) {
		return;
	}
	node_t* tmp = list_create();
	tmp->data = data;
	tmp->next = curr->next;
	curr->next = tmp;
}


void list_erase(node_t* begin, size_t pos) {
	node_t* curr = begin;
	size_t i = 0;
	while (i < pos) {
		if (curr->next == NULL)
			return;
		curr = curr->next;
		i++;
	}
	if (curr->next == NULL)
		return;
	node_t* tmp = curr->next->next;
	free(curr->next);
	curr->next = tmp;
}

void* list_at(node_t* begin, size_t index) {
	size_t i = 0;
	node_t* curr = begin;
	while (i < index) {
		if (curr->next == NULL)
			return NULL;
		curr = curr->next;
		i++;
	}
	return curr->data;
}

void list_clear(node_t* begin) {
	list_free(begin->next);
	begin->next = NULL;
}

#ifndef __cplusplus
void list_print_as_int(node_t* b) {
	node_t* curr = b;
	while (curr->next != NULL) {
		printf("%d ", *(int*)curr->data);
		curr = curr->next;
	}
	printf("\n");
}
#endif

void list_remove_if(node_t* begin, int cmp(void*)) {
	// If cmp(data) == 1 remove
	size_t i = 0;
	node_t* curr = begin;
	node_t* prev;
	while (curr->next != NULL) {
		if (cmp(curr->data) == 1) {
			if (i == 0) {
				list_pop_top(&begin);
			}
			else if (i == list_size(begin)) {
				list_pop_back(begin);
			}
			else{
				list_erase(begin, i - 1);
				curr = prev;
				i -= 1;
			}
		}
		i++;
		if (curr->next == NULL)
			return;
		prev = curr;
		curr = curr->next;
	}
}

size_t list_find(node_t* begin, int cmp(void*)) {
	size_t i = 0;
	node_t* curr = begin;
	while (curr->next != NULL) {
		if (cmp(curr->data) == 1) {
			return i;
		}
		i++;
		if (curr->next == NULL)
			return 0;
		curr = curr->next;
	}
	return 0;
}

void list_reverse(node_t** begin) {
	node_t* curr = *begin;
	node_t* prev = list_create();
	node_t* next = NULL;
	while (curr->next != NULL) {
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	*begin = prev;
}