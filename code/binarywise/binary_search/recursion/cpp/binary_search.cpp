//TODO: Allow for templating
template <class T>
static std::size_t _search(T* arr, std::size_t start, std::size_t end, T value)
{
    if (start == end)
    {
        if (arr[start] != value)
            throw SearchValueNotFound();

        return start;
    }

    std::size_t middle = (start + end) / 2;

    return 
        (value <= arr[middle])
        ? _search(arr, start, middle, value)
        : _search(arr, middle + 1, end, value);
}


template <typename T>
std::size_t search(T* arr, std::size_t length, T value)
{
    return _search<T>(arr, 0, length - 1, value);
}

