#include <iostream>
#include <string>

void printRainbow(const std::string& text) {
    std::string resetColor = "\033[0m";
    for (char c : text) {
        switch (c) {
            case 'a': case 'A': std::cout << "\033[31m" << c << resetColor; break; // red
            case 'b': case 'B': std::cout << "\033[32m" << c << resetColor; break; // green
            case 'c': case 'C': std::cout << "\033[33m" << c << resetColor; break; // yellow
            case 'd': case 'D': std::cout << "\033[34m" << c << resetColor; break; // blue
            case 'e': case 'E': std::cout << "\033[35m" << c << resetColor; break; // magenta
            case 'f': case 'F': std::cout << "\033[36m" << c << resetColor; break; // cyan
            case 'g': case 'G': std::cout << "\033[37m" << c << resetColor; break; // white
            case 'h': case 'H': std::cout << "\033[30m" << c << resetColor; break; // black
            case 'i': case 'I': std::cout << "\033[90m" << c << resetColor; break; // bright black
            case 'j': case 'J': std::cout << "\033[91m" << c << resetColor; break; // bright red
            case 'k': case 'K': std::cout << "\033[92m" << c << resetColor; break; // bright green
            case 'l': case 'L': std::cout << "\033[93m" << c << resetColor; break; // bright yellow
            case 'm': case 'M': std::cout << "\033[94m" << c << resetColor; break; // bright blue
            case 'n': case 'N': std::cout << "\033[95m" << c << resetColor; break; // bright magenta
            case 'o': case 'O': std::cout << "\033[96m" << c << resetColor; break; // bright cyan
            case 'p': case 'P': std::cout << "\033[97m" << c << resetColor; break; // bright white
            default: std::cout << c;
        }
    }
    std::cout << std::endl;
}

int main() {
    std::string text = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    printRainbow(text);
    return 0;
}