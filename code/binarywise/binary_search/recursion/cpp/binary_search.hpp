#pragma once

#include <stdexcept> // Warning: this library may throw
#include <cstddef>

class SearchValueNotFound : public std::runtime_error
{
    virtual const char* what() const throw()
    {
        return "Empty queue";
    }
};

// Caution: this function requires T to have defined comparison operators
template <typename T>
std::size_t search(T* arr, std::size_t length, T value);

#include "binary_search.cpp"

