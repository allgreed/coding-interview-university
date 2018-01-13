#include "bitwise.hpp"

#include <type_traits>
#include <climits>
#include <cstddef>

template <typename T>
T next_power_of_two(T number)
{
    static_assert(std::is_integral<T>::value and std::is_unsigned<T>::value, "Unsigned integral type required!");

    --number;
    
    for(std::size_t i = 1; i < sizeof(T) * CHAR_BIT; i *= 2)
    {
        number = number | (number >> i);
    }

    ++number; 

    return number;
}

