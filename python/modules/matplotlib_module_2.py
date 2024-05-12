#!/usr/bin/python3

import matplotlib.pyplot as plt
import pandas as pd
import numpy as np


car_sales = pd.read_csv("car_data.csv")
ts = pd.Series(np.random.randn(1000), index = pd.date_range("1/5/2024", periods=1000))
ts = ts.cumsum() # Her bir sonraki datayı toplayıp bir sonraki adıma koyar
ts.plot()

car_sales["Price"] = car_sales["Price"].str.replace('[\$\,\.]', '', regex=True)
car_sales["Price"] = car_sales["Price"].str[:-2].astype(int)

car_sales["Sale Date"] = pd.date_range("1/5/2024", periods=len(car_sales))
car_sales["Total Sales"] = car_sales["Price"].cumsum()
car_sales.plot(x="Sale Date", y="Total Sales")
car_sales.plot(x="Sale Date", y="Total Sales", kind="scatter")

print(car_sales)
plt.show()