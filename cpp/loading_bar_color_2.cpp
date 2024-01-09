#include <iostream>
#include <iomanip>
#include <thread>

// ANSI Escape Codes for text color
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define YELLOW  "\033[33m"
#define GREEN   "\033[32m"

int main() {
    const int totalSteps = 51;
    std::cout << std::endl;
    for (int i = 0; i <= totalSteps; ++i) {
        float percentage = static_cast<float>(i) / totalSteps * 100.0;
        int barWidth = 50;

        std::cout << "\r" << std::setw(2) << "[" << i << "/" << totalSteps << "]"  <<"|";
        int pos = barWidth * percentage / 100.0;
        for (int j = 0; j < barWidth; ++j) {
            if (j < pos) std::cout << "=";
            else if (j == pos) std::cout << ">";
            else std::cout << " ";
        }
        std::cout << "|" << "[" << std::fixed;
        if (percentage <= 35.0)
            std::cout << RED << std::setprecision(2) << percentage << "%" << RESET << "]";
        else if (percentage <= 75.0)
            std::cout << YELLOW << std::setprecision(2) << percentage << "%" << RESET << "]";
        else
            std::cout << GREEN << std::setprecision(2) << percentage << "%" << RESET << "]";
        std::flush(std::cout);
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }

    std::cout << std::endl << std::endl;
    return 0;
}
