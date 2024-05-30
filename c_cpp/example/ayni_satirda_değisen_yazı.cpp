#include <iostream>
#include <cstdlib> 
#include <ctime>  
#include <unistd.h> 

int main() {
    std::srand(static_cast<unsigned int>(std::time(0))); 
    std::cout << "\n\n\n";
    for (int i = 0; i < 100; ++i) {
        int x = std::rand() % 100;
        int y = std::rand() % 100;
        int z = std::rand() % 100;

        std::cout << "\033[3A"; 

        std::cout << "x: " << x << "\n";
        std::cout << "y: " << y << "\n";
        std::cout << "z: " << z << "\n" << std::flush;

        usleep(100000); 
    }

    std::cout << std::endl;

    return 0;
}