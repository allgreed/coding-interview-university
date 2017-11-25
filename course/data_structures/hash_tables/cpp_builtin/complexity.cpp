#include "hash_table.hpp"

#include <boost/range/irange.hpp>
#include <boost/type_index.hpp>
#include <iostream>
#include <ctime>
#include <functional>
#include <vector>
#include <algorithm>
#include <iomanip>

template <class Function_T>
long long unsigned time_of (const Function_T& timed_function)
{
    clock_t start, end;
    start = clock();
    timed_function();
    end = clock();

    return (long long unsigned) end - start;
}

template <class T,  class U>
std::unique_ptr<std::vector<long long unsigned>> time_of_n (std::size_t n, const U& setup_function, const T& timed_function_generator)
{
    auto tested_object_ptr = setup_function(n);

    auto vector = std::make_unique<std::vector<long long unsigned>>();
    vector->reserve(n);

    for(std::size_t i : boost::irange<std::size_t>(0, n+1))
        vector->push_back(time_of(timed_function_generator(tested_object_ptr, i)));

    // every first operation in a block is extremely slow
    // therefore shall not be take into account as it messes calculations
    vector->erase(vector->begin());

    return vector;
}

void report_time(std::unique_ptr<std::vector<long long unsigned>> time_vector)
{
    // todo: rolling max, min, avg, mean
    long long unsigned size = time_vector->size();
    double mean = std::accumulate(time_vector->begin(), time_vector->end(), 0.0) / time_vector->size();
    long long unsigned max = *std::max_element(time_vector->begin(), time_vector->end());

    std::nth_element(time_vector->begin(), time_vector->begin() + size / 2, time_vector->end());
    double avg = *std::next(time_vector->begin(), size / 2);

    std::cout << " max: " << std::setw(5) << max << std::setw(1);
    std::cout << " | avg: " << std::setw(5) << avg << std::setw(1);
    std::cout << " | mean: " << std::setw(7) <<std::setprecision(2) << mean << std::setw(1);
    std::cout << " | clocks for " << std::setw(10) << size << std::setw(1) << " operations" << std::endl;
}

template <class T, class U>
void test_complexity(std::size_t start, std::size_t end, std::size_t factor, const U& setup_function, const T& test_function_generator, std::string suite_name, std::string case_name)
{
    // std::cout << boost::typeindex::type_id<T>().pretty_name() << std::endl;
    // std::cout << boost::typeindex::type_id<U>().pretty_name() << std::endl;

    std::cout << std::endl << suite_name << "::" << case_name << std::endl;

    std::cout << std::setw(76) << std::setfill('-') << "" << std::setw(1) << std::setfill(' ') << std::endl;

    for(std::size_t n = start; n < end; n *= factor)
        report_time(time_of_n(n, setup_function, test_function_generator));

    std::cout << std::setw(76) << std::setfill('-') << "" << std::setw(1) << std::setfill(' ') << std::endl;
    std::cout << std::endl;
}

int main()
{
    auto setup = [](std::size_t sample_size) -> std::unique_ptr<HashTable<int>>
    {
        sample_size++;
        return std::make_unique<HashTable<int>>();
    };

    // todo: bind this first parameter to the setup function return parameter type
    // maybe some kind of template?
    auto lambda = [](std::unique_ptr<HashTable<int>>& hash_table, std::size_t iteration)
    {
        auto generate_key = [](long long unsigned seed)
        {
            std::string key = std::to_string(seed);

            while(key.length() < 10)
            {
                char randomchar = '0';
                while((randomchar >= '0' && randomchar <= '9')) randomchar = rand() % 128;

                key += randomchar;
            }
            return key;
        };

        return [&]()
        {
            hash_table->add(generate_key(iteration), iteration);
        };
    };

    // todo: infer case name and suite name from functions somehow
    test_complexity(1,1e7, 10, setup, lambda, "HashTable", "add(key, value)");

    return 0;
}
