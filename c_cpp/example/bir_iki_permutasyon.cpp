// 1 ve 2 kullanılarak bir sayının kaç farklı permitasyonu oluşabileceğini bulmak

#include <iostream>

int factorial(int number);

int sum = 0;
int stairs_number = 6;

int main(){
    int max_two_size = stairs_number / 2;
    int one_size = stairs_number % 2 == 1 ? 1 : 0;

    for(int i = max_two_size; i >= 0; i--){
        int numbers_step = i + one_size; 
        sum += factorial(numbers_step) / (factorial(i) * factorial(one_size));
        one_size += 2;
    }
    std::cout << sum << std::endl;
    return 0;
}

int factorial(int number){
    if(number > 1){
        return number * factorial(number - 1);
    }
    return 1;
}