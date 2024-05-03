import pandas as pd

car_sales = pd.read_csv("car_data.csv")
print("________________________________")
# İlk kısımda bulunan 5 satırı döndürür
# parametre olarak bu sayı değiştirilebilir.
# "tail()" ile son 5 satır da alınabilir.
print(car_sales.head()) 
print("________________________________")
print(car_sales["Colour"]) # ya da car_sales.Colour aynı anlamı taşır.
print("________________________________")
print(car_sales[car_sales["Make"] == "Toyota"]) # Sadece "Toyota" blockları gellir
print("________________________________")
print(car_sales[car_sales["Odometer(km)"] > 12041242]) # Koşulu sağlayanları gösterir
print("________________________________")
animals = pd.Series(["Dog", "Cat", "Bird", "Panda"],
                    index = [1, 3, 2, 2]) # İndex isteğe gibi düzenlenebilmesini sağlar.
print(animals)
print("________________________________")
print(animals.loc[2]) # Belirli bir index değerini verir
print(animals.loc[:2]) # Belirli index'e kadar değeri verir
print("________________________________")
print(animals.iloc[1]) # Pos göre döndürür. (ilk değer 0 olarak sayılır)