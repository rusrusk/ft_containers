The objective of this project is to implement the various container types of the C++ standard template library + perform tests for each container type.


To achieve success, a solid understanding of the inner workings of templates, iterators, containers, and algorithms was essential. It's important to note that the use of the Standard Template Library (STL) is not permitted, which means that neither <iterator> nor <utility> can be utilized.

Outlined below are the distinct characteristics of the five containers:

➡️ Vector: This dynamic array facilitates insertion at the container's end. Elements can be conveniently accessed using their corresponding index. However, it is not the most efficient container for frequent insertion or deletion operations.

➡️ List: Represented as a circular linked list with a neutral node connecting the beginning and end, the list performs better than a vector when it comes to inserting or deleting elements.

➡️ Stack: This container adapter follows the Last-In-First-Out (LIFO) principle.

➡️ Queue: Operating based on the First-In-First-Out (FIFO) principle, this container adapter handles elements accordingly.

➡️ Map: Utilizing an AVL binary tree that auto-balances itself to optimize search time, this sorted container enables storing data similar to a dictionary, where each key is associated with a value.

All the containers implemented here employ an allocator to effectively manage memory, utilize iterators to access data, and feature the same constructors/methods found in the C++98 STL containers.
