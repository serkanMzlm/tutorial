#!/usr/bin/python3 
sayi_sistemleri = ["onlu", "sekizli", "on altılı", "ikili"]

print(("{:^9} "*len(sayi_sistemleri)).format(*sayi_sistemleri))
for i in range(17):
    print("{0:^9} {0:^9o} {0:^9x} {0:^9b}".format(i))

metin_1 = "bu Türkçe bir cümledir.".encode("utf-8", errors="strict")
metin_2 = "bu Türkçe bir cümledir.".encode("ascii", errors="ignore")
metin_3 = "bu Türkçe bir cümledir.".encode("ascii", errors="replace")
metin_4 = "bu Türkçe bir cümledir.".encode("ascii", errors="xmlcharrefreplace")

print(metin_1)
print(metin_2)
print(metin_3)
print(metin_4)