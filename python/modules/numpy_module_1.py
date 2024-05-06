#! /bin/usr/python3
import numpy as np
import pandas as pd

a1 = np.array([1, 2, 3])

a2 = np.array([[1, 2, 3],
              [4, 5, 6]])

a3 = np.array([[[1, 2, 2.3],
                [3, 3.4, 4],
                [2, 4.3, 5]],

                [[0, 2, 2.3],
                [2, 2.2, 4],
                [2, 3.2, 5]]]
              )

print("a1:", a1.shape, "| a2:", a2.shape, "| a3:", a3.shape)
print("a1 boyut:", a1.ndim, "| a2 boyut:", a2.ndim, "| a3 boyut:", a3.ndim)
print("a1:", a1.dtype, "| a2:", a2.dtype, "| a3:", a3.dtype)
print("a1:", a1.size, "| a2:", a2.size, "| a3:", a3.size)

print("-" * 40)
df = pd.DataFrame(a2)
print(df)
