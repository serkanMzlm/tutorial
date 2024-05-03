import pandas as pd

car_sales = pd.read_csv("car_data.csv")
print(car_sales)
print("________________________________")
print(car_sales.dtypes)  # Veri türünü gösterir.
print("________________________________")
print(car_sales.columns) # Sütünları alır 
print("________________________________")
print(car_sales.index)   # Satır bilgise verir. (start, stop, step)
print("________________________________")
print(car_sales.describe()) # Sayısal sütünlar hakkında bilgi verir.
print("________________________________")
print(car_sales.info())  # Veri hakkında bilgi verir
print("________________________________")

car_prices = pd.Series([2000, 4000, 1000, 3000, 0])
print(car_prices.mean()) # Ortalamayı verir
print("________________________________")
print(car_sales.sum())   # Bütün sütünları kendi arasında toplar
print("________________________________")
print("Toplam:", car_sales["Doors"].sum(), "Uzunluk:", len(car_sales)) # Belirli bir sutünü toplar
print("________________________________")
