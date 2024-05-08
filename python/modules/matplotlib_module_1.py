#!/bin/usr/python3

"""
1. yol:
fig = plt.figure()
ax = fig.add_subplot() 
2. yol:
fig = plt.figure()
ax = fig.add_axes([0.1, 0.1, 0.8, 0.8]) -> [x0, y0, width, height] 
3. yol:
fig, ax = plt.subplots()
"""

import matplotlib.pyplot as plt 
import pandas as pd
import numpy as np

# x = [1, 2, 3, 4]
# y = [0, 2, 7, 30]
x = np.linspace(0, 10, 200)
y = x ** 2

# figsize olçüler verir width, height
fig_1, ax_1 = plt.subplots(figsize = (10, 5))
ax_1.plot(x, y)                   # line plot
ax_1.set(title = "Simple Plot",
       xlabel = "x-axis",
       ylabel = "y-axis")

fig_2, ax_2 = plt.subplots(figsize = (10, 5))
ax_2.scatter(x, np.exp(x)) # ax_2.scatter(x, np.sin(x))  scatter plot

data = {"A": 20,
        "B": 1,
        "C": 10}
    
fig_3, ax_3 = plt.subplots(figsize = (10, 5))
ax_3.bar(data.keys(), data.values()) # (dikey) ax_3.barh(list(data.keys()), list(data.values())) (yatay) bar plot

x = np.random.randn(1000)   # gous yasasına göre sayılar oluşturur
fig_4, ax_4 = plt.subplots()
ax_4.hist(x)                # histogram plot

fig_4, ((ax1, ax2), (ax3, ax4)) = plt.subplots(nrows=2, ncols=2, figsize=(10, 5))
ax1.plot(x, x/2)
ax2.scatter(np.random.random(10), np.random.random(10))
ax3.bar(data.keys(), data.values())
ax4.hist(x)
# ya da 
fig_5, ax_5 = plt.subplots(nrows=2, ncols=2, figsize=(10, 5))
ax_5[0, 0].plot(x, x/2)
ax_5[0, 1].scatter(np.random.random(10), np.random.random(10))
ax_5[1, 0].bar(data.keys(), data.values())
ax_5[1, 1].hist(x)

fig_1.savefig("../../images/simple_plot.png")
plt.show()
 
