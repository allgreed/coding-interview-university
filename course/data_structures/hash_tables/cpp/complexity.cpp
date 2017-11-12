#include "hash_table.hpp"

#include <boost/range/irange.hpp>
#include <iostream>
#include <ctime>
#include <functional>
#include <vector>
#include <algorithm>
#include <iomanip>

// -------------------
// todo: move this to main as lambda
std::string generate_key(long long unsigned seed)
{
    std::string key = std::to_string(seed);

    while(key.length() < 10)
    {
        char randomchar = '0';
        while((randomchar >= '0' && randomchar <= '9')) randomchar = rand() % 128;

        key += randomchar;
    }
    return key;
}

// -------------------

long long unsigned time_of (std::function<void ()> timed_function)
{
    clock_t start, end;
    start = clock();
    timed_function();
    end = clock();

    return (long long unsigned) end - start;
}

// todo: add function pointer as second parameter
// todo-future: make list of parameters dynamic
std::unique_ptr<std::vector<long long unsigned>> time_of_n (std::size_t n)
{
    HashTable<int> hash_table(2 * n);

    auto vector = std::make_unique<std::vector<long long unsigned>>();
    vector->reserve(n);

    for(std::size_t i : boost::irange<std::size_t>(0, n+1))
    {
        // todo: construct proper function to pass
        vector->push_back(time_of([&]()
        {
            // future-todo: pass identifier not lambda literal
            hash_table.add(generate_key(i), i);
        }));
    }

    // every first operation in a block is extremely slow
    // therefore shall not be take into account as it messes calculations
    vector->erase(vector->begin());

    return vector;
}

void report_time(std::unique_ptr<std::vector<long long unsigned>> time_vector)
{
    long long unsigned size = time_vector->size();
    double mean = std::accumulate(time_vector->begin(), time_vector->end(), 0.0) / time_vector->size();
    long long unsigned max = *std::max_element(time_vector->begin(), time_vector->end());

    std::nth_element(time_vector->begin(), time_vector->begin() + size / 2, time_vector->end());
    double avg = *std::next(time_vector->begin(), size / 2);

    std::cout << " max: " << std::setw(5) << max << std::setw(1);
    std::cout << ", avg: " << std::setw(5) << avg << std::setw(1);
    std::cout << ", mean: " << std::setw(5) <<std::setprecision(2) << mean << std::setw(1);
    std::cout << " | clocks for " << std::setw(10) << size << std::setw(1) << " operations" << std::endl;
}

// todo: make this take a function parameter
// todo: and a recipie for constructing it's parameters
void test_complexity(std::size_t start, std::size_t end, std::size_t factor)
{
    // todo-future -> maybe some kind of nicer reporting, like stating case name, ascii decorations?

    for(std::size_t i = start; i < end; i *= factor)
        report_time(time_of_n(i));
}

int main()
{
    test_complexity(1,1e7, 10);

    return 0;
}
