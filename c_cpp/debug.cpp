#include <iostream>
#include <limits>

using std::cin;

int main(){
     [[maybe_unused]] int a = 10;  // Bu değişkenin kullanılmamış olasının sorun olmadıgını belirtmiş oluruz.
     [[maybe_unused]] int b(39);
     [[maybe_unused]] int c {3};

    int n = 0;
    std::cout << "Enter a number: " << std::endl;
    cin >> n;
    if (std::cin.fail()) {  // Girilen değerde bir hata olduğunda çalışır
        std::cin.clear();   // Hatayı temizler
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Hatalı girilen okunmamış verileri temizler
        std::cin.get();
    }
    return 0;
}