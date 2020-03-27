#include "linked_list.h"

lln_t* ll_create() {
	lln_t* start = malloc(sizeof(lln_t));
	start->data = NULL;
	start->next = NULL;
	start->prev = NULL;
	return start;
}

void ll_free(lln_t* begin) {
	if (begin->data == NULL) {
		free(begin);
		return;
	}
	lln_t* prev = begin->prev->prev, * next = begin;
	lln_t* tmp;
	while (next->next != NULL) {
		tmp = next->next;
		free(next);
		next->next = NULL;
		next->prev = NULL;
		next = tmp;
		if (next == prev || prev->prev == NULL) {
			return;
		}
		tmp = prev->prev;
		free(prev);
		prev->next = NULL;
		prev->prev = NULL;
		prev = tmp;
	}
}

int ll_is_empty(lln_t* begin) {
	if (begin->next == NULL) {
		return 1;
	}
	return 0;
}

size_t ll_size(lln_t* begin) {
	if (ll_is_empty(begin) == 1)
		return 0;
	lln_t* next = begin, * prev = begin->prev->prev;
	size_t size = 0;
	while (next->data != NULL && next != prev) {
		next = next->next;
		size++;
		if (next == prev) {
			break;
		}
		prev = prev->prev;
		size++;
	}
	return size + 1;
}

void* ll_front(lln_t* begin) {
	return begin->data;
}

void* ll_end(lln_t* begin) {
	return begin->prev->prev->data;
}

void ll_push_top(lln_t** begin, void* data) {
	lln_t* new_node = ll_create();
	new_node->data = data;
	if ((*begin)->data == NULL) {
		new_node->next = (*begin);
		new_node->prev = (*begin);
		(*begin)->next = new_node;
		(*begin)->prev = new_node;
	}
	else {
		new_node->prev = (*begin)->prev;
		(*begin)->prev->next = new_node;
		new_node->next = (*begin);
		(*begin)->prev = new_node;

	}
	*begin = new_node;
}

void ll_push_back(lln_t** begin, void* data) {
	lln_t* new_node = ll_create();
	new_node->data = data;
	if ((*begin)->data == NULL) {
		new_node->next = (*begin);
		new_node->prev = (*begin);
		(*begin)->next = new_node;
		(*begin)->prev = new_node;
		*begin = new_node;
		return;
	}
	new_node->next = (*begin)->prev;
	new_node->prev = (*begin)->prev->prev;
	(*begin)->prev->prev->next = new_node;
	(*begin)->prev->prev = new_node;
}

void ll_pop_top(lln_t** begin) {
	if ((*begin)->data == NULL) {
		return;
	}
	lln_t* next = (*begin)->next;
	(*begin)->prev->next = next;
	next->prev = (*begin)->prev;
	free(*begin);
	*begin = next;
}

void ll_pop_back(lln_t* begin) {
	if (begin->data == NULL) {
		return;
	}
	lln_t* del = begin->prev->prev;
	begin->prev->prev = del->prev;
	del->prev->next = begin->prev;
	free(del);
}

void ll_insert(lln_t* begin, void* data, size_t pos) {
	size_t len = ll_size(begin);
	if (ll_is_empty(begin) == 1 || pos > len || pos == 0){
		return;
	}
	else if (pos <= len / 2) {
		lln_t* before = begin;
		for (size_t i = 0; i < pos - 1; i++) {
			before = before->next;
		}
		lln_t* new_node = ll_create();
		new_node->data = data;
		new_node->next = before->next;
		before->next = new_node;
		new_node->prev = before;
		new_node->next->prev = new_node;
	}
	else {
		lln_t* after = begin->prev->prev;
		for (size_t i = 0; i < len - pos - 1; i++) {
			after = after->prev;
		}
		lln_t* new_node = ll_create();
		new_node->data = data;
		new_node->next = after;
		new_node->prev = after->prev;
		after->prev->next = new_node;
		after->prev = new_node;
	}
}

void ll_erase(lln_t* begin, size_t pos) {
	size_t len = ll_size(begin);
	if (pos >= len) {
		return;
	}
	else if (pos == 0) {
		return;
	}
	else if (pos <= len / 2) {
		lln_t* del = begin;
		for (int i = 0; i < pos; i++) {
			del = del->next;
		}
		del->next->prev = del->prev;
		del->prev->next = del->next;
		free(del);
	}
	else {
		lln_t* del = begin->prev->prev;
		for (int i = 0; i < len - pos - 1; i++) {
			del = del->prev;
		}
		del->next->prev = del->prev;
		del->prev->next = del->next;
		free(del);
	}
}

void* ll_at(lln_t* begin, size_t index) {
	if (index > ll_size(begin))
		return NULL;
	lln_t* curr = begin;
	for (int i = 0; i < index; i++) {
		if (curr->data == NULL) {
			return NULL;
		}
		curr = curr->next;
	}
	return curr->data;
}

void ll_clear(lln_t** begin) {
	ll_free(*begin);
	*begin = ll_create();
}

void ll_remove_if(lln_t** begin, int cmp(void*)) {
	if (ll_is_empty(*begin) == 1) {
		return;
	}
	lln_t* next = *begin, * prev = (*begin)->prev->prev;
	lln_t* tmp = NULL;
	while (next->data != NULL && prev->data != next->prev) {
		if (next->data != NULL && cmp(next->data) == 1) {
			tmp = next->prev;
			tmp->next = next->next;
			next->next->prev = next->prev;
			free(next);
			next = tmp;
		}
		if (prev != next && cmp(prev->data) == 1) {
			tmp = prev->next;
			prev->prev->next = prev->next;
			prev->next->prev = prev->prev;
			free(prev);
			prev = tmp;
		}
		next = next->next;
		prev = prev->prev;
	}
}

size_t ll_find(lln_t* begin, int cmp(void*)) {
	size_t i = 0;
	for (lln_t * curr = begin; curr->data != NULL; curr = curr->next) {
		if (cmp(curr->data) == 1) {
			return i;
		}
		i++;
	}
}

void ll_reverse(lln_t** begin) {
	if (ll_is_empty(*begin) == 1) {
		return;
	}
	lln_t* next = (*begin), * prev = (*begin)->prev;
	lln_t* tmp;
	while (next != prev) {
		tmp = next->next;
		next->next = next->prev;
		next->prev = tmp;
		if (next == prev)
			break;
		next = next->prev;
		
		tmp = prev->next;
		prev->next = prev->prev;
		prev->prev = tmp;
		if (next == prev)
			break;
		prev = prev->next;
	}
	*begin = (*begin)->next->next;
}

#ifndef __cplusplus
void ll_print_as_int(lln_t* begin) {
	lln_t* curr = begin;
	while (curr->data != NULL) {
		printf("%d ", *(int*)(curr->data));
		curr = curr->next;
	}printf("\n");
}
#endif