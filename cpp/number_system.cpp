#include <iostream>


int main()
{
    int a = 11;
    int b = 011;
    int c = 0x11;
    int d = 0b11;

    std::cout << "a: " << a << std::endl;
    std::cout << "b: " << b << std::endl;
    std::cout << "c: " << c << std::endl;
    std::cout << "d: " << d << std::endl;
    std::cout << "_________________" << std::endl;
    std::cout << std::dec << "a: " << a << std::endl;
    std::cout << std::oct << "b: " << b << std::endl;
    std::cout << std::hex << "c: " << c << std::endl;
    std::cout << "d: " << d << std::endl;

}