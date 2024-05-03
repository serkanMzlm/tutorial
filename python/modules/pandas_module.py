#! /usr/bin/python3
import pandas as pd

series = pd.Series(['BMW', 'Toyota', 'Honda'])
color = pd.Series(["Red", "Blue", "Green"])

car_data = pd.DataFrame({"Car Frame":series, "Color":color}) #İki farklı Seriyi birleştirilmesini sağlar.
print(car_data, end="\n____________\n\n") 

car_sales = pd.read_csv("car_data.csv")  #Belirli bir csv dosyayı içe aktarmayı sağlar.
print(car_sales)


# Belili bir değişiklik yapıldıktan sonra faklı çıktı olarak kaydedilebilir.
# Aynı şekilde to_dict, to_excel... farklı veri dosyasına çevrile bilir. csv 
# dosyasının geçerliliği her yerde olduğu için kullanılır. index = False sayesinde 
# satır sayıları tekrar alınmaz 
car_sales.to_csv("export_car_sales.csv", index = False) 