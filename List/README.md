<h2>List</h2>
<p>I developed my own C implementation of this simple data structure for using in my future projects (I hope so).
There are some very useful functions and also one data structure (struct node or just node_t). Also you can use main.c to check if everything is working fine.</p>
Data structure has two lines:
<ul>
  <li>data pointer - void* data</li>
  <li>pointer to next node - node_t* next</li>
</ul>
<br>
There are such functions : 
<ol>
  <li><strong>node_t* list_create()</strong> - return new node with no data and no pointer to next node.</li>
  <li><strong>void list_free(node_t* begin)</strong> - call this function if you want to delete whole list.</li>
  <li><strong>int list_is_empty(node_t* begin)</strong> - return 1 if list is empty and 0 if not.</li>
  <li><strong>size_t list_size(node_t* begin)</strong> - return size of the list.</li>
  <li><strong>void* list_front(node_t *begin)</strong> - return pointer to first element of the list (also you can use begin->data).</li>
  <li><strong>void* list_end(node_t* begin)</strong> - return pointer to last element of the list.</li>
  <li><strong>void list_push_top(node_t* begin, void* data)</strong> - insert new data to the start of the list.</li>
  <li><strong>void list_push_back(node_t* begin, void* data)</strong> - insert new data to the end of the list.</li>
  <li><strong>void list_pop_top(node_t** begin)</strong> - remove first element from the list.</li>
  <li><strong>void list_pop_back(node_t* begin)</strong> - remove last element of the list.</li>
  <li><strong>void list_insert(node_t* begin, void* data, size_t pos)</strong> - insert new data to whatever position you want.</li>
  <li><strong>void list_erase(node_t* begin, size_t pos)</strong> - remove data from whatever position you want.</li>
  <li><strong>void* list_at(node_t* begin, size_t index)</strong> - return pointer to data on index positon.</li>
  <li><strong>void list_clear (node_t * begin)</strong> - clear the entire list (delete all elements after the second).</li>
  <li><strong>void list_remove_if(node_t* begin, int cmp (void*))</strong> - remove data if cmp(data) returns 1.</li>
  <li><strong>size_t list_find(node_t* begin, int cmp(void*))</strong> - return index of the first element where cmp returns 1.</li>
  <li><strong>void list_print_as_int(node_t* b)</strong> - ONLY C FUNCTION, ONLY PRINTS INTEGERS.</li>
</ol>

