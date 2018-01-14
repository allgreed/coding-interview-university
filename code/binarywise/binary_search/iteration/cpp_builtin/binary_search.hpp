#pragma once

#include <stdexcept> // Warning: this library may throw
#include <cstddef>
#include <vector>

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

template <typename T>
std::size_t search(std::vector<T> container, T value);

#include "binary_search.cpp"

