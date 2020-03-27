#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdint.h>
#include <stdlib.h>

struct LinkedListNode {
	struct LinkedListNode* next;
	struct LinkedListNode* prev;
	void* data;
};

typedef struct LinkedListNode lln_t;
#ifndef LIST_H
typedef lln_t node_t;
#endif

lln_t* ll_create();

void ll_free(lln_t* begin);

int ll_is_empty(lln_t* begin);

size_t ll_size(lln_t* begin);

void* ll_front(lln_t* begin);

void* ll_end(lln_t* begin);

void ll_push_top(lln_t* begin, void* data);

void ll_push_back(lln_t* begin, void* data);

void ll_pop_top(lln_t* begin);

void ll_pop_back(lln_t* begin);

void ll_insert(lln_t* begin, void* data, size_t pos);

void ll_erase(lln_t* begin, size_t pos);

void* ll_at(lln_t* begin, size_t index);

void ll_clear(lln_t** begin);

void ll_remove_if(lln_t** begin, int cmp(void*));

size_t ll_find(lln_t* begin, int cmp(void*));

void ll_reverse(lln_t** begin);

#ifndef __cplusplus
void ll_print_as_int(lln_t* begin);
#endif

#endif /* LINKED_LIST_H */