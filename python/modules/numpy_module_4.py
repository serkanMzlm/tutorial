#!/bin/usr/python3

import numpy as np

a1 = np.random.randint(1, 10, size=(2, 3, 3))
a2 = np.random.randint(1, 10, size=(2, 3))
print("a1:\n", a1, "\n\na2:\n", a2)

# a1 * a2 olabilmesi için boyutlarının uyumlu olması 
# lazımdır. reshape yeniden boyutlandırmayı sağlar.
a2_reshape = a2.reshape(2, 3, 1)
print("\na1 * a2_reshape:\n", a1 * a2_reshape)

# Transpose = eksenlerin yer değiştirmesini sağlar.
print("\na2 shape:", a2.shape, "\n" , a2,
      "\na2 Transpose shape:", a2.T.shape, "\n" , a2.T
      )

# Vektorel çarpımda (a,b)x(b,c) = (a,c) şeklinde 
# boyutları olması lazımdır.
a3 = np.random.randint(5, size=(4, 3))
a4 = np.random.randint(5, size=(3, 2))
print("\n\n",np.dot(a3, a4))

print("\n", "****"*7, "\n")

a5 = np.random.randint(1, 10, (3, 4))
a6 = np.random.randint(1, 10, (3, 4))
print(a5, a6, a5 >= a6, sep="\n")
