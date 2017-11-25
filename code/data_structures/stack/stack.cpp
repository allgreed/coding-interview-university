#include <iostream>
#include <ctime>
#include <string>

#include <stack>
#include <vector>
#include <list>
#include <deque>

const int OP_COUNT = 10'000'000;

template <class T>
void runTest(std::string container_name)
{
    typedef typename T::value_type value_T;

    clock_t begin = clock();

    std::stack<value_T, T> stack;

    for(int i = 0; i < OP_COUNT; i++)
    {
        stack.push(i);
    }

    for(int i = 0; i < OP_COUNT; i++)
    {
        int temp = stack.top();
        stack.pop();
    }

    clock_t end = clock();

    std::cout << container_name << std::endl;
    std::cout << "Clocks per single push/top/pop: " << std::endl;
    std::cout << ((double)(end - begin) / OP_COUNT) << std::endl;

    std::cout << std::endl;
}

int main(int argc, char const *argv[])
{
    std::cout << std::endl;
    std::cout << "--------------------------------" << std::endl;
    std::cout << "Operation count: " << OP_COUNT << std::endl;
    std::cout << "--------------------------------" << std::endl;
    std::cout << std::endl;

    runTest<std::list<int>>("std::list");
    runTest<std::vector<int>>("std::vector");
    runTest<std::deque<int>>("std::deque");

    return 0;
}