### Queue

Started @: 2017-10-18 18:33
Finished @: 2017-11-01 12:17

- [x] Description:
    - [x] [Queue (video)](https://www.coursera.org/learn/data-structures/lecture/EShpq/queue)
    - [x] [Circular buffer/FIFO](https://en.wikipedia.org/wiki/Circular_buffer)
    - [x] [Priority Queues (video)](https://www.youtube.com/watch?v=wptevk0bshY)
- [x] Implement using linked-list, with tail pointer:
    - enqueue(value) - adds value at position at tail
    - dequeue() - returns value and removes least recently added element (front)
    - empty()
- [x] Implement in:
    - [x] C
    - [x] C++
    - [x] C++ with builtin types
    - [x] Memtest via valgrind
- [x] Implement using fixed-sized array:
    - enqueue(value) - adds item at end of available storage
    - dequeue() - returns value and removes least recently added element
    - empty()
    - full()
- [x] Implement in:
    - [x] C
    - [x] C++ (start index + tracking size)
    - [x] C++ with builtin types
- [x] Cost:
    - a bad implementation using linked list where you enqueue at head and dequeue at tail would be O(n)
        because you'd need the next to last element, causing a full traversal each dequeue
    - enqueue: O(1) (amortized, linked list and array [probing])
    - dequeue: O(1) (linked list and array)
    - empty: O(1) (linked list and array)
