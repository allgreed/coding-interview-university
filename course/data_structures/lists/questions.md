# Non trivial questions

## C

### Commit 52dcd3e378a4ab20155785d5d289a03865d0a89c introduce some shitty warnings (incompatible pointer type), how to get rid of thoose?

I've referenced an anonymous struct inside typedef -> therefore the pointers were inconsistent

## C++

### Why use private, not protected -> if private does not allow inheritance?

### How does templates work in terms of function definition headers?

### return_type function_name(parameter_list) CONST ???

### How to test destructor for memory leaks?

### See comment?

```c++
template <typename T>
class List
{
    protected:
        template<typename _>
        // Why there must be a template here, even if it's empty? o.0
        struct ListNode
        {
            T value;
            ListNode* next;

            ListNode(T value, ListNode* next) : value(value), next(next) {}
            ListNode(ListNode* next) : next(next) {}
            ListNode() {}
        };
}
```

### See comment?

```c++
//todo: move this inside node struct -> how to handle templates in function declaration? Ask Patryk
void nodeEraseAfter(ListNode<T>* preErased);
```

## C++ STL

### How iterators work?
