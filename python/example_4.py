#!/usr/bin/python3 

metin = "Ser kan"

liste2 = list(metin)
liste = metin.split()
print(liste)
print(liste2)
print(len(liste2))

print("_"*20, end="\n\n")

sayilar = [[0, 10], [6, 60], [12, 54], [67, 99]]
for i in sayilar:
    print(i[0], i[1]) # ya da print(*i)
    print(*i)
    print("-"*20)