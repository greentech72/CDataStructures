#include <stdint.h>
#include <stdlib.h>

typedef struct node {
	struct node* next;
	void* data;
} node_t;

node_t* list_create();

void list_free(node_t *begin);

int list_is_empty(node_t* begin); // if true == -1 else something else

size_t list_size(node_t* begin); // O(n)

void* list_front(node_t* begin);

void* list_end(node_t* begin);

void list_push_top(node_t* begin, void* data);

void list_push_back(node_t* begin, void* data);

void list_pop_top(node_t** begin);

void list_pop_back(node_t* begin);

void list_insert(node_t* begin, void* data, size_t pos); // insert after pos

void list_erase(node_t* begin, size_t pos); // erase after pos

void* list_at(node_t* begin, size_t index);

void list_clear(node_t* begin);

//void list_remove_if(node_t* begin, int cmp (void*)); // cmp if true = 1 else 0

void list_print_as_int(node_t* b);