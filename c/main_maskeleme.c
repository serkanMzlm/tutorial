// Main() işlevini kullanmadan "Merhaba" yazdıracak bir C kodu.
// constructor int main önce çalışmasını sağlar.
// destructor int main sonra çalışmasını sağlar.
#include <stdio.h>

#define startup main // Maskeleme

void __attribute__((constructor)) calledFirst();
void __attribute__((destructor)) calledLast();

void startup()
{
    printf("Main\n");
    if(printf("Hello\n")){ // ; kullanmadan ekrana çıktı vermek

    }
}

void calledFirst()
{
    printf("Constructor\n");
}
void calledLast()
{
    printf("Destructor\n");
}