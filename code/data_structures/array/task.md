### Implement an automatically resizing vector.

Started @: yyyy-mm-dd hh:mm
Finished @: 2017-10-04 00:07

- [x] Description:
    - [x] [UC Berkeley CS61B - Linear and Multi-Dim Arrays (video)](https://archive.org/details/ucberkeley_webcast_Wp8oiO_CZZE) (Start watching from 15m 32s)
    - [x] [Dynamic Arrays (video)](https://www.coursera.org/learn/data-structures/lecture/EwbnV/dynamic-arrays)
    - [x] [Jagged Arrays (video)](https://www.youtube.com/watch?v=1jtrQqYpt7g)
    - [x] [Resizing arrays (video)](https://www.lynda.com/Developer-Programming-Foundations-tutorials/Resizable-arrays/149042/177108-4.html)
- [x] Implement a vector (mutable array with automatic resizing):
    - [x] Practice coding using arrays and pointers, and pointer math to jump to an index instead of using indexing.
    - [x] new raw data array with allocated memory
        - can allocate int array under the hood, just not use its features
        - start with 16, or if starting number is greater, use power of 2 - 16, 32, 64, 128
    - [x] size() - number of items
    - [x] capacity() - number of items it can hold
    - [x] is_empty()
    - [x] at(index) - returns item at given index, blows up if index out of bounds
    - [x] push(item)
    - [x] pop() - remove from end, return value
    - [x] delete(index) - delete item at index, shifting all trailing elements left
    - [x] insert(index, item) - inserts item at index, shifts that index's value and trailing elements to the right
    - [x] prepend(item) - can use insert above at index 0
    - [x] remove(item) - looks for value and removes index holding it (even if in multiple places)
    - [x] find(item) - looks for value and returns first index with that value, -1 if not found
    - [x] resize(new_capacity) // private function
        - when you reach capacity, resize to double the size
        - when popping an item, if size is 1/4 of capacity, resize to half
- [x] Time
    - O(1) to add/remove at end (amortized for allocations for more space), index, or update
    - O(n) to insert/remove elsewhere
- [x] Space
    - contiguous in memory, so proximity helps performance
    - space needed = (array capacity, which is >= n) * size of item, but even if 2n, still O(n)

- [x] Implement in:
    - [x] C
    - [x] C++
    - [x] C++ with builtin types
