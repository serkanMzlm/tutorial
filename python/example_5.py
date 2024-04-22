#!/usr/bin/python3 
sayi_sistemleri = ["onlu", "sekizli", "on altılı", "ikili"]

print(("{:^9} "*len(sayi_sistemleri)).format(*sayi_sistemleri))
for i in range(17):
    print("{0:^9} {0:^9o} {0:^9x} {0:^9b}".format(i))