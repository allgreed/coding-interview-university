template <typename T>
std::size_t search(T* arr, std::size_t length, T value)
{
    std::size_t start = 0;
    std::size_t end = length - 1;
    
    while(start != end)
    {
        std::size_t middle = (start + end) / 2;

        value <= arr[middle] 
            ? (end = middle) 
            : (start = middle + 1);
    }

    if (arr[start] != value)
        throw SearchValueNotFound();

    return start;
}

