#!/bin/usr/python3

import numpy as np

a1 = np.random.randint(1, 10, size=(2, 3, 3))
a2 = np.ones((2, 3, 3))

end_ = "\n" + "-"*25 + "\n"

# Erişim için [,] şeklinde ilerlenir.
print(a1[0], end = end_)
print(a1[1,1, 1], end = end_)
print(a1[:2, :2, :2], end = end_)

# Diziler üstünde aritmatik işlemler yapılabilir.
print(a1 + a2, end = end_) # np.add(a1, a2)
print(a1 - a2, end = end_)
print(a1 * a1, end = end_)
print(a1 / a1, end = end_)
print(a1 // a1, end = end_)
print(a1 ** 3, end = end_) # ya da np.square(a1)
print(a1 % 3, end = end_)
np.exp(a1)
np.log(a1)

np.sum(a1) # sum(a1) aynı işlemi yapsada np.sum daha hızlı işlem gerçekleştirir.
np.mean(a1)
np.max(a1)
np.min(a1)
np.std(a1)
np.var(a1)
np.sqrt(a1)
