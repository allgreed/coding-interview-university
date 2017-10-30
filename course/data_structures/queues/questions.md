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

### Is is a good idea to define class constants as this?

```cpp
    protected:
        static constexpr int DEFAULT_SIZE = 5;
```

### How to check for existance of == operator on class?
Would [This](https://stackoverflow.com/a/31860104) be feasible?

## C++ STL

### Standard circular buffer class?

