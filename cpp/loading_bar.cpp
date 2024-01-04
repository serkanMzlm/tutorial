#include <iostream>
#include <iomanip>
#include <thread> 

int main() {
    const int totalSteps = 51;

    for (int i = 0; i <= totalSteps; ++i) {
        float percentage = static_cast<float>(i) / totalSteps * 100.0;
        int barWidth = 50;

        std::cout << "\r" << std::setw(3) <<"|";
        int pos = barWidth * percentage / 100.0;
        for (int j = 0; j < barWidth; ++j) {
            if (j < pos) std::cout << "=";
            else if (j == pos) std::cout << ">";
            else std::cout << " ";
        }
        std::cout << "| " << i << "/" << totalSteps << " [" << std::fixed << std::setprecision(2) << percentage << "%]";
        std::flush(std::cout);
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }

    std::cout << std::endl;
    return 0;
}
