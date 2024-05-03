#! /usr/bin/python3
import pandas as pd

series = pd.Series(['BMW', 'Toyota', 'Honda'])
color = pd.Series(["Red", "Blue", "Green"])

car_data = pd.DataFrame({"Car Frame":series, "Color":color}) #İki farklı Seriyi birleştirilmesini sağlar.
print(car_data, end="\n____________\n\n") 

# Belirli bir csv dosyayı içe aktarmayı sağlar. İnternet adresinden de veri çekilebilir.
# Github kısmından veri çekilmek için "raw" kımsına basılıp link kopyalanır
car_sales = pd.read_csv("car_data.csv")  
car_sales_1 = pd.read_csv("https://raw.githubusercontent.com/serkanMzlm/tutorial/main/python/modules/car_data.csv")
print(car_sales)

# Belili bir değişiklik yapıldıktan sonra faklı çıktı olarak kaydedilebilir.
# Aynı şekilde to_dict, to_excel... farklı veri dosyasına çevrile bilir. csv 
# dosyasının geçerliliği her yerde olduğu için kullanılır. index = False  
# sayesinde satır sayıları tekrar alınmaz 
car_sales.to_csv("export_car_sales.csv", index = False) 