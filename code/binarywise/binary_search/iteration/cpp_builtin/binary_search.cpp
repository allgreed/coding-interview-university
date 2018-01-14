#include <algorithm>

template <typename T>
std::size_t search(std::vector<T> container, T value)
{
    auto iterator = std::lower_bound(container.begin(), container.end(), value);

    if (*iterator != value)
        throw SearchValueNotFound();

    std::size_t index = std::distance(container.begin(), iterator);
    
    return index;
}

