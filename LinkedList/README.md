<h2>Linked list</h2>
<p>I developed my own C implementation of this data structure for using in my future projects (I hope so).
There are some very useful functions and also one data structure (struct LinkedListNode or just lln_t, or even node_t if regular list isn't included). 
Difference between list and linked_list is complexity. List have complexity O(n), but LinkedList have complexity O(n / 2) (not in all cases).<br>
Also you can use main.c to check if everything is working fine.</p>
Data structure has three lines:
<ul>
  <li>pointer to next element - lln_t* next</li>
  <li>pointer to previous element - lln_t* prev</li>
  <li>pointer to data - void* data</li>
</ul>
<br>
There are such functions : 
<ol>
  <li><strong>lln_t* ll_create()</strong> - return new node of the linked list with NULL data.</li>
  <li><strong>void ll_free(lln_t* begin)</strong> - call this function if you want to delete whole linked list.</li>
  <li><strong>int ll_is_empty(lln_t* begin)</strong> - return 1 if linked list is empty and 0 if not.</li>
  <li><strong>size_t ll_size(lln_t* begin)</strong> - return size of the linked list.</li>
  <li><strong>void* ll_front(lln_t* begin)</strong> - return pointer to data from the front.</li>
  <li><strong>void* ll_end(lln_t* begin)</strong> - return pointer to data from the back.</li>
  <li><strong>void ll_push_top(lln_t* begin, void* data)</strong> - insert new data to the begining of the list.</li>
  <li><strong>void ll_push_back(lln_t* begin, void* data)</strong> - insert new data to the end of the list.</li>
  <li><strong>void ll_pop_top(lln_t* begin)</strong> - delete node from the begining of the list.</li>
  <li><strong>void ll_pop_back(lln_t* begin)</strong> - delete node from the end of the list.</li>
  <li><strong>void ll_insert(lln_t* begin, void* data, size_t pos)</strong> - insert new node to the list.</li>
  <li><strong>void ll_erase(lln_t* begin, size_t pos)</strong> - delete node from the list.</li>
  
  <li><strong>void* ll_at(lln_t* begin, size_t index)</strong> - return data of the element on index position.</li>
  <li><strong>void ll_clear(lln_t** begin)</strong> - clear entire list (call free function and then ll_create).</li>
  <li><strong>void ll_remove_if(lln_t** begin, int cmp(void*))</strong> - delete node if cmp(data) == 1.</li>
  <li><strong>size_t ll_find(lln_t* begin, int cmp(void*))</strong> - return index of the first node where cmp(data) == 1.</li>
  <li><strong>void ll_reverse(lln_t** begin)</strong></li>
  <li><strong>void ll_print_as_int(lln_t* begin)</strong> - only c function!</li>
  
  
</ol>

