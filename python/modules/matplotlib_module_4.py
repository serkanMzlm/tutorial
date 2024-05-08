#!/bin/usr/python3

import numpy as np
import pandas as pd
import matplotlib.pyplot as plt

x = np.linspace(0, 10, 9) 
y = [(i * 2 if i %4 > 2 else i / 2) for i in x]
print(plt.style.available, sep="\n") # Grafik moddeleri gösterir.
plt.style.use("seaborn-whitegrid") # seaborn

fig1, ax1 = plt.subplots(figsize = (10, 5))
ax1.plot(x, y)

x = np.random.randn(10, 4) 
df = pd.DataFrame(x, columns=['a', 'b', 'c', 'd'])
ax2 = df.plot(kind="bar")
ax2.set(title = "Random Number",
        xlabel = "Row",
        ylabel = "colomn"
        )
ax2.legend().set_visible(True)

plt.show()