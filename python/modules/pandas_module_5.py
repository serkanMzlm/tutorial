#!/usr/bin/python3
import pandas as pd

num_of_line = 50

car_sales = pd.read_csv("car_data.csv")
print(car_sales["Make"].str.lower())
print("_" * num_of_line)
seats_column = pd.Series([5, 5, 5, 12])
car_sales["Seats"] = seats_column # Yeni bir sutün ekler
print(car_sales)
print("_" * num_of_line)

# NaN kısımlara o sutün ortalaması ile değiştirir.
# inplace 'True' ise o anki veride işlemler yaılır 'False'
# ise geriye bir kalıp döndürür.
car_sales["Doors"] = car_sales["Doors"].fillna(car_sales["Doors"].mean(), inplace = False)
# NaN kısımları o satırları siler
car_sales["Seats"].dropna(inplace = True) 
car_sales["copy"] = 12.9
print(car_sales)
print("_" * num_of_line)

# Axis 0 satır, axis 1 sutündur.
car_sales = car_sales.drop("copy", axis= 1) # Belirli bir sutün siler
print(car_sales)
print("_" * num_of_line)

# Data set karıştırmak için kullanılır. "frac" yüzde kaçı karıştırmak 
# istediğimizi belirtir. 1 = 100, 0.5 = 50 bu bizim büyük verilerin belli 
# karıştırılıp kullanmak istediğimizde 02 yazarak verinin %20 alır ve karıştırır
# car_sales.reset_index() tekrardan düzenler
print(car_sales.sample(frac=1))
print("_" * num_of_line)

car_sales["Doors"] = car_sales["Doors"].apply(lambda x: x -1)
print(car_sales)
print("_" * num_of_line)

