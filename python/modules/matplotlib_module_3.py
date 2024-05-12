#!/usr/bin/python3

import numpy as np
import matplotlib.pyplot as plt
import pandas as pd

car_sales = pd.read_csv("car_data.csv")

x = np.random.rand(10, 4)
df = pd.DataFrame(x, columns=['a', 'b', 'c', 'd'])
# df.plot.bar() # ya da df.plot(kind="bar")

fix, ax = plt.subplots(figsize=(10, 6))
# 
car_sales.plot(x="Make", y="Odometer(km)", c="Odometer(km)", kind='scatter', ax=ax) 
# c belirli bir veriye göre renk vermeyi sağlar. ax de belirli bir subplots  
# kalıbı içe aktarılabilir. Bu parametreler doldurulmaya bilir.
# car_sales["Odometer(km)"].plot(kind="hist")
# car_sales["Odometer(km)"].plot.hist(bins=30) bins aralık sayısını belirtir.
# ax.set_xlim([45, 56]) x ekseninde görülmesi istediğimiz alanı kaydeder.
# ax.set_ylim([0.2, 1.5])

scatter = ax.scatter(car_sales["Make"], car_sales["Odometer(km)"], 
                        c=car_sales["Odometer(km)"], cmap="winter") # cmap = color map renk ayarı verilmesi sağlanır

ax.set(title="Car", 
    xlabel="Make",
    ylabel="Odometer (KM)")
ax.axhline(car_sales["Odometer(km)"].mean(),
           linestyle="--")
ax.legend(*scatter.legend_elements(), title="Target" )
ax.set_ylim([10000, 150000])
plt.show()