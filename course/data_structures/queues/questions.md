# Non trivial questions

## C

### Is there a better way to do templating than typedef [type] stoarge_t?

### Can I leverage preprocessor to only compile testing code when compiling unit.c?

## C++

### What is a good practice for indenting initialiser lists?

My example:
```cpp
    template <typename T>
    Queue<T>::Queue(int desired_size) :
        _begin_index(0),
        _size(0),
        _capacity(desired_size)
    {
        T* _data = new T[desired_size];
    }
```



## C++ STL
