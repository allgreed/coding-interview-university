### Binary Search Trees

Started @: 2018-02-02 18:51
Finished @: yyyy-mm-dd hh:mm

- ### Trees - Notes & Background
    - [ ] [Series: Core Trees (video)](https://www.coursera.org/learn/data-structures-optimizing-performance/lecture/ovovP/core-trees)
    - [ ] [Series: Trees (video)](https://www.coursera.org/learn/data-structures/lecture/95qda/trees)
    - basic tree construction
    - traversal
    - manipulation algorithms
    - BFS (breadth-first search)
        - [x] [MIT (video)](https://www.youtube.com/watch?v=s-CYnVz-uh4&list=PLUl4u3cNGP61Oq3tWYp6V_F-5jb5L2iHb&index=13)
        - level order (BFS, using queue)
            time complexity: O(n)
            space complexity: best: O(1), worst: O(n/2)=O(n)
    - DFS (depth-first search)
        - [ ] [MIT (video)](https://www.youtube.com/watch?v=AfSk24UTFS8&list=PLUl4u3cNGP61Oq3tWYp6V_F-5jb5L2iHb&index=14)
        - notes:
            time complexity: O(n)
            space complexity:
                best: O(log n) - avg. height of tree
                worst: O(n)
        - inorder (DFS: left, self, right)
        - postorder (DFS: left, right, self)
        - preorder (DFS: self, left, right)

- ### Binary search trees: BSTs
    - [x] [Binary Search Tree Review (video)](https://www.youtube.com/watch?v=x6At0nzX92o&index=1&list=PLA5Lqm4uh9Bbq-E0ZnqTIa8LRaL77ica6)
        - starts with symbol table and goes through BST applications
    - [x] [MIT (video)](https://www.youtube.com/watch?v=9Jry5-82I68)
    - C/C++:
        - [x] [Delete a node from Binary Search Tree (video)](https://www.youtube.com/watch?v=gcULXE7ViZw&list=PL2_aWCzGMAwI3W_JlcBbtYTwiQSsOTa6P&index=36)
        - [x] [Find height of a binary tree (video)](https://www.youtube.com/watch?v=_pnqMz5nrRs&list=PL2_aWCzGMAwI3W_JlcBbtYTwiQSsOTa6P&index=31)
        - [ ] [Check if a binary tree is binary search tree or not (video)](https://www.youtube.com/watch?v=yEwSGhSsT0U&index=35&list=PL2_aWCzGMAwI3W_JlcBbtYTwiQSsOTa6P)

    - [x] Implement:
        - [x] insert    // insert value into tree
        - [x] is_in_tree // returns true if given value exists in the tree
        - [x] get_min   // returns the minimum value stored in the tree
        - [x] get_max   // returns the maximum value stored in the tree
        - [x] delete_value
        - [x] get_successor // returns next-highest value in tree after given value, -1 if none
        - [x] get_height // returns the height in nodes (single node's height is 1)
        - [x] get_node_count // get count of values stored
        - [x] print_values // prints the values in the tree, from min to max
        - [x] is_binary_search_tree

    - [ ] Implement in:
        - [x] C
        - [ ] C++
        - [ ] C++ with builtin types

<!-- Redo C template -->

