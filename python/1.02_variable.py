#!/usr/bin/python3
val_1 = val_2 = 10                             # val_1 ve val_2 değerine 10 atanır.

a, b = 1, 2                                    # Sırası ile atama işlemi yapılır.
c, d, *other = [1, 2, 3, 4, 5, 6, 7]           # İlk iki kısım sırayla atanır gerisi other liste olarak atanır.
e, f, *other_2, g = [1, 2, 3, 4, 5, 6, 7, 8]   # Son değer g ye atanır ilk değerler e ve f atanır gerisi other

print(a)
print(b)
print(c)
print(other)
print(d)