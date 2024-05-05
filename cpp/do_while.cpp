#include <iostream>

bool echo(int number){
    if (number == 0){
        return false;
    }

    std::cout << "Hello World" << std::endl;
    return true;
}

int main(){
    int number = 0;
    do{
        number = 0;
        std::cout << "(0: exit, 1: echo) => ";
        std::cin >> number;
    }while(echo(number));
}