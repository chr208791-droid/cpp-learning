#include <iostream>

void passByValue(int x)
{
    std::cout << "\n--- passByValue ---" << std::endl;

    std::cout << "Before change:" << std::endl;
    std::cout << "x = " << x << std::endl;
    std::cout << "&x = " << &x << std::endl;

    x = 100;

    std::cout << "After change:" << std::endl;
    std::cout << "x = " << x << std::endl;
}

void passByReference(int& x)
{
    std::cout << "\n--- passByReference ---" << std::endl;

    std::cout << "Before change:" << std::endl;
    std::cout << "x = " << x << std::endl;
    std::cout << "&x = " << &x << std::endl;

    x = 200;

    std::cout << "After change:" << std::endl;
    std::cout << "x = " << x << std::endl;
}

int main()
{
    int a = 10;

    std::cout << "Original variable:" << std::endl;
    std::cout << "a = " << a << std::endl;
    std::cout << "&a = " << &a << std::endl;

    passByValue(a);

    std::cout << "\nAfter passByValue:" << std::endl;
    std::cout << "a = " << a << std::endl;

    passByReference(a);

    std::cout << "\nAfter passByReference:" << std::endl;
    std::cout << "a = " << a << std::endl;

    return 0;
}