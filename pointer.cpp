#include <iostream>

int main()
{
    int a = 10;
    int b = 20;

    int* p = &a;

    std::cout << "--- Pointer basic test ---" << std::endl;

    std::cout << "a = " << a << std::endl;
    std::cout << "&a = " << &a << std::endl;

    std::cout << "p = " << p << std::endl;
    std::cout << "*p = " << *p << std::endl;

    std::cout << "\nChange a through pointer:" << std::endl;

    *p = 15;

    std::cout << "a = " << a << std::endl;
    std::cout << "*p = " << *p << std::endl;

    std::cout << "\nMake p point to b:" << std::endl;

    p = &b;

    std::cout << "b = " << b << std::endl;
    std::cout << "&b = " << &b << std::endl;
    std::cout << "p = " << p << std::endl;
    std::cout << "*p = " << *p << std::endl;

    std::cout << "\nnullptr test:" << std::endl;

    int* empty_ptr = nullptr;

    std::cout << "empty_ptr = " << empty_ptr << std::endl;

    if (empty_ptr == nullptr)
    {
        std::cout << "empty_ptr points to nothing." << std::endl;
    }

    return 0;
}