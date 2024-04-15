#include <stdio.h>

// İki tamsayıyı toplayan fonksiyon
int add(int a, int b) {
    return a + b;
}

int main() {
    // Fonksiyon işaretçisi tanımlanıyor ve "add" fonksiyonuna işaret ediliyor
    int (*addPtr)(int, int) = add;

    // İşaretçi ile fonksiyon çağrısı yapılıyor
    int result = addPtr(3, 5);

    printf("Toplam: %d\n", result);

    return 0;
}