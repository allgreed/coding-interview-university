#include "vector.hpp"


#include <iostream>

#include <assert.h>

// Create and destroy

void init_test()
{
    Vector <int>vector;

    assert(vector.whatSize() == 0);
    assert(vector.whatCapacity() == 16);

    // better test creation ???
    // assert(vector.data != nullptr);
}

void init_of_size_test()
{
    Vector<int> vector(20);

    assert(vector.whatCapacity() == 32);
}

void insertTest()
{
    Vector<int> vector;

    vector.insert_at(0,6);
    vector.insert_at(1,7);
    vector.insert_at(2,8);
    vector.insert_at(3,9);
    vector.insert_at(4,10);

    assert(vector.at(0) == 6);
    assert(vector.at(1) == 7);
    assert(vector.at(2) == 8);
    assert(vector.at(3) == 9);
    assert(vector.at(4) == 10);
    assert(vector.whatSize() == 5);

}

void updateTest()
{
    Vector<int> vector;
    vector.insert_at(0,128);

    vector.update_at(0,-200);

    assert(vector.at(0) == -200);
    assert(vector.whatSize() == 1);
}

void deleteTest()
{
    Vector<int> vector;
    vector.insert_at(0,4556);
    vector.insert_at(1,-8999);

    vector.delete_at(0);

    assert(vector.at(0) == -8999);
    assert(vector.whatSize() == 1);
}

void isEmptyTest()
{
    Vector<int> vector;

    assert(vector.isEmpty() == true);

    vector.insert_at(0, -500);

    assert(vector.isEmpty() == false);

    vector.delete_at(0);

    assert(vector.isEmpty() == true);
}

void pushTest()
{
    Vector<int> vector;

    vector.push(58);

    assert(vector.at(0) == 58);
    assert(vector.whatSize() == 1);
}

void popTest()
{
    Vector<int> vector;

    vector.push(58);
    int tmp = vector.pop();

    assert(tmp == 58);
    assert(vector.isEmpty() == true);
}


void prependTest()
{
    Vector<int> vector;

    vector.push(64);
    vector.push(4);

    vector.prepend(58);

    assert(vector.at(0) == 58);
    assert(vector.at(1) == 64);
    assert(vector.at(2) == 4);

    assert(vector.whatSize() == 3);
}

void findTest()
{
    Vector<int> vector;

    vector.push(64);
    vector.push(4);

    assert(vector.find(4) == 1);
    assert(vector.find(50) == -1);

}

void removeTest()
{
    Vector<int> vector;
    vector.push(7);
    vector.push(7);
    vector.push(5);
    vector.push(4);
    vector.push(7);
    vector.push(7);
    vector.push(3);
    vector.push(7);
    vector.push(5);
    vector.push(7);
    vector.push(7);

    vector.remove(7);

    assert(vector.at(0) == 5);
    assert(vector.at(1) == 4);
    assert(vector.at(2) == 3);
    assert(vector.at(3) == 5);

    assert(vector.whatSize() == 4);
}

void zeroCapacityUsabilityTest()
{
    Vector<int> vector(0);

    vector.push(5);
    int retval = vector.pop();

    assert(retval == 5);
}

void resizeTest()
{
    Vector<int> vector;

    for (int i = 0; i < 16; i++)
        vector.push(1234567890);

    assert(vector.whatCapacity() == 32);

    for (int i = 0; i < 12; i++)
        vector.pop();

    assert(vector.whatCapacity() == 8);

}

int main()
{
    init_test();
    init_of_size_test();

    insertTest();
    updateTest();
    deleteTest();

    resizeTest();

    isEmptyTest();
    pushTest();
    popTest();
    prependTest();
    findTest();

    removeTest();

    zeroCapacityUsabilityTest();

    std::cout << "All tests passed!" << std::endl;
    return 0;
}
