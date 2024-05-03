#!/usr/bin/python3
import pandas as pd
import matplotlib.pyplot as plt 

car_sales = pd.read_csv("car_data.csv")
# crosstab iki veya daha fazla faktörün kesişimini inceleyerek bir tablo oluşturur. 
# Bu tablo, kategorik değişkenlerin birbirleriyle nasıl ilişkili olduğunu, her bir
# kombinasyonun gözlemlenen sayısını ve/veya yüzdesini içerir
print(pd.crosstab(car_sales["Make"], car_sales["Doors"]))

print("______________________________________")
print(car_sales)
car_sales["Price"] = car_sales["Price"].str.replace('[\$\.\,]', '', regex=True).astype(int)
print("______________________________________")
print(car_sales)
print("______________________________________")
car_sales["Doors"].plot()
car_sales["Price"].plot()
car_sales["Doors"].hist()
plt.show()