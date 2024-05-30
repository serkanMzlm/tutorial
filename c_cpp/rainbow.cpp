#include <iostream>
#include <chrono>
#include <thread>

int main() {
    const char* red = "\x1b[41m";
    const char* green = "\x1b[42m";
    const char* yellow = "\x1b[43m";
    const char* blue = "\x1b[44m";
    const char* magenta = "\x1b[45m";
    const char* cyan = "\x1b[46m";
    const char* white = "\x1b[47m";
    const char* reset = "\x1b[0m";

    std::string text = "Rainbow!";

    for (size_t i = 0; i < text.size(); ++i) {
        switch (i % 7) {
            case 0: std::cout << red << std::endl; break;
            case 1: std::cout << green << std::endl; break;
            case 2: std::cout << yellow << std::endl; break;
            case 3: std::cout << blue << std::endl; break;
            case 4: std::cout << magenta << std::endl; break;
            case 5: std::cout << cyan << std::endl; break;
            case 6: std::cout << white << std::endl; break;
        }
        std::cout << text[i] << reset;
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        std::cout << '\r';
    }

    std::cout << std::endl;
    return 0;
}