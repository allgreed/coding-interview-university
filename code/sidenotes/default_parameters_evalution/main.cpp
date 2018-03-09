#include <iostream>

struct Test
{
    public:
        int a = 1;

    Test() : a(3)
    {
    
    }
};

int main()
{
    Test test;
    std::cout << test.a << std::endl;    
}
