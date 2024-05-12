#!/usr/bin/python3

import numpy as np

# sort sıralamayı sağlar. "argsort" sıralama sonucunda 
# sayıların gerçekte hangi index de olduğunu belirtir.
a1 = np.random.randint(1, 23, (3, 4))
print(a1, np.sort(a1), np.argsort(a1),
                 sep= "\n" + "-"*20 + "\n", end= "\n" +"-"*20 + "\n") 

print(np.argmax(a1), np.argmin(a1))