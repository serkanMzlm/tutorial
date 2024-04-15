#include <stdio.h>

int main() {
    char karakterDizisi[50]; // Karakter dizisi için yer ayırılıyor
    int a, b, c; // İki tane tamsayı değişkeni tanımlanıyor
    char sayilar[] = "42 65 78"; // Karakter dizisi içindeki sayılar

    // sprintf kullanarak karakter dizisine bir metin ve bir tamsayı yazılıyor
    sprintf(karakterDizisi, "Ali %d", 10);

    // sscanf kullanarak karakter dizisinden tamsayıları alıyoruz
    sscanf(sayilar, "%d %d %d", &a, &b, &c);

    // Yazdırılan değerler
    printf("sprintf ile oluşturulan karakter dizisi: %s\n", karakterDizisi);
    printf("sscanf ile alınan tamsayılar: %d, %d, %d\n", a, b, c);

    return 0;
}