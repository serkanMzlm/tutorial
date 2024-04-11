#include <stdio.h>


int main(){
    float number = 3.2109;
    unsigned int number_2 = 12;
    printf("%7.3f \n", number);
    printf("%-7.3f\n", number);
    printf("%+2.3f\n", number);
    printf("%*.*f\n", 2,3,number); // * koymak verilerin dışardan doldurulmasını sağlar.
    printf("%o\n", number_2);
    printf("%x\n", number_2);
    printf("%#04x\n", number_2);   // # koymak sayının 0x şeklinde yazılmasını sağlar

    return 0;
}