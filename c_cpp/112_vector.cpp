#include <iostream>
#include <vector>


int main()
{
    std::vector<int> v1 = {10};
    std::vector primes { 2, 3, 5, 7, 11 }; // hold the first 5 prime numbers (as int)
    std::vector<int> data( 10 );
    std::cout << "An int is " << sizeof(int) << " bytes\n";
    std::cout << &(primes[0]) << '\n';
    std::cout << &(primes[1]) << '\n';
    std::cout << &(primes[2]) << '\n';

    std::cout << data[1] << '\n';
    std::cout << data[3] << '\n';
    std::cout << data[5] << '\n';
    std::cout << data.at(1) << '\n';

    std::cout << "data vector size: " << data.size() << std::endl;  
    std::cout << "Capacity: " << data.capacity() << " Length:"	<< data.size() << '\n';

    return 0;
}