#pragma once

#include <stdexcept> // Warning: this library may throw
#include <cstddef>

class SearchValueNotFound : public std::runtime_error
{
    public:
        SearchValueNotFound() : SearchValueNotFound("") { }

        explicit SearchValueNotFound(const std::string& error_message)
            : std::runtime_error(error_message) { }

        virtual const char* what() const throw()
        {
            return "Empty queue";
        }
};

// Caution: this function requires T to have defined comparison operators
template <typename T>
std::size_t search(T* arr, std::size_t length, T value);

#include "binary_search.cpp"

