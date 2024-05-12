#!/usr/bin/python3

import numpy as np

# Bir den oluşan dizin, shape boyutunu, dtype ise
# türünü belirtir default olarak float64
one_array_1 = np.ones(shape = (2, 4), dtype = int) 


zeros_array = np.zeros((2, 3, 4)) # Sıfırdan oluşan
range_array = np.arange(0, 20, 5) # Belirli bir aralıkta belirli artış miktarına göre oluşturur.

# Random sayıların ilk değer atamasının sürekli sabit olmasını sağlar
# her çalıştırıldığında farklı bir değer almasını engeller. Parametre
# olarak verilen sayı her hangi bir şey olabilir.
# np.random.seed(7) 
random_array_1 = np.random.randint(0, 10, size=(2,4))
random_array_2 = np.random.random((2,4)) # 0.0 - 1.0 arasında sayılar oluşturur.
random_array_3 = np.random.rand(2,4)

print("one array 1:", one_array_1, "\ntype:", one_array_1.dtype)
print("zeros array:\n", random_array_2)
