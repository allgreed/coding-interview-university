### Queue

Started @: 2017-10-18 18:33
Finished @: yyyy-mm-dd hh:mm

- ### Queue
    - [ ] Description:
        - [ ] [Queue (video)](https://www.coursera.org/learn/data-structures/lecture/EShpq/queue)
        - [ ] [Circular buffer/FIFO](https://en.wikipedia.org/wiki/Circular_buffer)
        - [x] [Priority Queues (video)](https://www.youtube.com/watch?v=wptevk0bshY)
    - [x] Implement using linked-list, with tail pointer:
        - enqueue(value) - adds value at position at tail
        - dequeue() - returns value and removes least recently added element (front)
        - empty()
    - [ ] Implement in:
        - [x] C
        - [x] C++
        - [ ] C++ with builtin types
        - [ ] C++ (manual memory leak test)
    - [ ] Implement using fixed-sized array:
        - enqueue(value) - adds item at end of available storage
        - dequeue() - returns value and removes least recently added element
        - empty()
        - full()
    - [ ] Implement in:
        - [ ] C
        - [ ] C++
        - [ ] C++ (manual memory leak test)
        - [ ] C++ with builtin types
    - [ ] Cost:
        - a bad implementation using linked list where you enqueue at head and dequeue at tail would be O(n)
            because you'd need the next to last element, causing a full traversal each dequeue
        - enqueue: O(1) (amortized, linked list and array [probing])
        - dequeue: O(1) (linked list and array)
        - empty: O(1) (linked list and array)

<!-- append this to template -->
<!-- - [ ] Implement in:
    - [ ] C
    - [ ] C++
    - [ ] C++ with builtin types -->

<!-- template -->
    <!-- cpp -> move stdexcept to .cpp file from header -->

<!-- template -->
    <!-- Convert indentation to tabs in makefiles -->
