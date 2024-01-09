#include <iostream>
#include <iomanip>
#include <thread>
#include <chrono>

int main() {
    const int totalSteps = 58;
    std::cout << std::endl;
    auto startTime = std::chrono::steady_clock::now();

    for (int i = 0; i <= totalSteps; ++i) {
        float percentage = static_cast<float>(i) / totalSteps * 100.0;
        int barWidth = 50;

        auto currentTime = std::chrono::steady_clock::now();
        auto elapsedTime = std::chrono::duration_cast<std::chrono::milliseconds>(currentTime - startTime).count();

        int seconds = static_cast<int>(elapsedTime / 1000);
        int minutes = seconds / 60;
        seconds %= 60;
        int milliseconds = elapsedTime % 1000;

        std::cout << "\r" << "|";
        int pos = barWidth * percentage / 100.0;
        for (int j = 0; j < barWidth; ++j) {
            if (j < pos) {
                std::cout << "█";
            } else {
                std::cout << " ";
            }
        }
        std::cout << "| " << i << "/" << totalSteps << " [" << std::fixed << 
                                        std::setprecision(2) << percentage << "%]";
        std::cout << "[" << std::setw(2) << std::setfill('0') << minutes << ":" << std::setw(2) 
                                    << std::setfill('0') << seconds << "." << std::setw(3) << milliseconds << "]";
        std::flush(std::cout);
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }

    std::cout << std::endl << std::endl;
    return 0;
}
