### Linked Lists

Started @: 2017-10-04 18:29
Finished @: yyyy-mm-dd hh:mm


- [ ] Description:
    - [ ] [Singly Linked Lists (video)](https://www.coursera.org/learn/data-structures/lecture/kHhgK/3singly-linked-lists)
    - [ ] [CS 61B - Linked Lists 1 (video)](https://archive.org/details/ucberkeley_webcast_htzJdKoEmO0)
    - [ ] [CS 61B - Linked Lists 2 (video)](https://archive.org/details/ucberkeley_webcast_-c4I3gFYe3w)on.
- [x] Linked List vs Arrays:
    - [In The Real World Linked Lists Vs Arrays (video)](https://www.coursera.org/learn/data-structures-optimizing-performance/lecture/QUaUd/in-the-real-world-lists-vs-arrays)
- [x] [why you should avoid linked lists (video)](https://www.youtube.com/watch?v=YQs6IC-vgmo)
- [x] Gotcha: you need pointer to pointer knowledge:
    (for when you pass a pointer to a function that may change the address where that pointer points)
    This page is just to get a grasp on ptr to ptr. I don't recommend this list traversal style. Readability and maintainability suffer due to cleverness.
    - [Pointers to Pointers](https://www.eskimo.com/~scs/cclass/int/sx8.html)
- [ ] implement (I did with tail pointer & without):
    - [x] value_at(index) - returns the value of the nth item (starting at 0 for first)
    - [x] empty() - bool returns true if empty
    - [x] insert(index, value) - insert value at index, so current item at that index is pointed to by new item at index
    - [x] erase(index) - removes node at given index
    - [x] size() - returns number of data elements in list
    - [x] push_front(value) - adds an item to the front of the list
    - [x] pop_front() - remove front item and return its value
    - [x] push_back(value) - adds an item at the end
    - [x] pop_back() - removes end item and returns its value
    - [x] front() - get value of front item
    - [x] back() - get value of end item
    - [x] value_n_from_end(n) - returns the value of the node at nth position from the end of the lists

    - [ ] remove_value(value) - removes the first item in the list with this value
    - [ ] reverse() - reverses the list
<!-- todo get rid of these shitty warnings -->
- [ ] Implement in:
    - [ ] C
    - [ ] C++
    <!-- Todo: Unit testing C++ -->
    <!-- https://github.com/google/googletest/blob/master/googletest/docs/Primer.md -->
    <!-- Testing exceptions -->
    - [ ] C++ with builtin types
- [x] Doubly-linked List
    - [Description (video)](https://www.coursera.org/learn/data-structures/lecture/jpGKD/doubly-linked-lists)
    - No need to implement

<!-- Update template if necessary -->
