<h2>Stack</h2>
<p>I developed my own C implementation of this simple data structure for using in my future projects (I hope so).
There are some very useful functions and also one data structure (struct stack or just stack). Also you can use main.c to check if everything is working fine.</p>
Data structure has three lines:
<ul>
  <li>data pointer to array of pointers to data - void** data</li>
  <li>size of array of pointers (max elements amount) - size_t size</li>
  <li>index to element after current - size_t index</li>
</ul>
<br>
There are such functions : 
<ol>
  <li><strong>stack_t* stack_create(size_t size)</strong> - return new stack with no data.</li>
  <li><strong>void stack_free(stack_t* stack)</strong> - call this function if you want to delete whole stack.</li>
  <li><strong>int stack_is_empty(stack_t* stack)</strong> - return 1 if stack is empty and 0 if not.</li>
  <li><strong>void* stack_top(stack_t* stack)</strong> - return pointer to element</li>
  <li><strong>void stack_push(stack_t* stack, void* data)</strong> - insert new data to the top of the stack.</li>
  <li><strong>void stack_pop(stack_t* stack)</strong> - remove top element</li>
  <li><strong>void stack_clear(stack_t* stack)</strong> - clear the entire stack.</li>
</ol>

