#!/usr/bin/python3

import pandas as pd
import numpy as np

from sklearn.ensemble import RandomForestClassifier # Rastgele orman sınıflandırıcı ve regresör modellerini oluşturmak için kullanılır
from sklearn.ensemble import RandomForestRegressor
from sklearn.model_selection import train_test_split #Veri setini eğitim ve test alt kümelerine bölmek için kullanılır.
from sklearn.preprocessing import OneHotEncoder #Kategorik özellikleri binary özelliklere dönüştürmek için kullanılır.
from sklearn.compose import ColumnTransformer #Sütun bazında dönüşümler uygulamak için kullanılır.

from sklearn.impute import SimpleImputer # Eksik verileri doldurmak için kullanılır.
from sklearn.compose import ColumnTransformer

from myLib.debug import debug

data = pd.read_csv("data/car_sales_extended_missing_data.csv")
debug(1, data.isna().sum())
debug(1, data["Doors"].value_counts())
data.dropna(subset=["Price"], inplace=True)

X = data.drop("Price", axis=1)
y = data["Price"]

# Rastgelelik kontrolü için NumPy kütüphanesindeki 
# random sayı üreticisinin önceden belirlenmiş bir tohum değeriyle başlatır.
np.random.seed(42)
X_train, X_test, y_train, y_test = train_test_split(X,
                                                    y,
                                                    test_size=0.2)

"""
Eksik değerleri doldurmak için kullanılan sınıftır. "straegy" doldurma sırasında
kullanılıcak stratejiyi beliler örnek olarak "mean" (ortalama), "median" (medyan), 
"most_frequent" (en sık tekrar eden değer) veya "constant" (sabit bir değer) olabilir.
fill_value: Bu parametre, eksik değerleri doldurmak için kullanılacak sabit değeri belirtir.
"""
cat_imputer = SimpleImputer(strategy="constant", fill_value="missing")
door_imputer = SimpleImputer(strategy="constant", fill_value=4)
num_imputer = SimpleImputer(strategy="mean")

cat_features = ["Make", "Colour"]
door_feature = ["Doors"]
num_features = ["Odometer (KM)"]

"""
ColumnTransformer: Bu sınıf, farklı sütunlara farklı dönüşümler veya işlemler uygulamak 
için kullanılır. İlk parametre dönüşüme ad verme için kullanılır.
"""
imputer = ColumnTransformer([
    ("cat_imputer", cat_imputer, cat_features),
    ("door_imputer", door_imputer, door_feature),
    ("num_imputer", num_imputer, num_features)
])

filled_X_train = imputer.fit_transform(X_train)
filled_X_test = imputer.transform(X_test)

car_sales_filled_train = pd.DataFrame(filled_X_train, 
                                      columns=["Make", "Colour", "Doors", "Odometer (KM)"])

car_sales_filled_test = pd.DataFrame(filled_X_test, 
                                     columns=["Make", "Colour", "Doors", "Odometer (KM)"])

print(car_sales_filled_train.isna().sum())

categorical_features = ["Make", "Colour", "Doors"]
one_hot = OneHotEncoder()
"""
remainder="passthrough" parametresi, dönüşüm sırasında 
diğer sütunların değiştirilmeden kalmasını sağlar.
"""
transformer = ColumnTransformer([("one_hot", 
                                 one_hot, 
                                 categorical_features)],
                                 remainder="passthrough")

transformed_X_train = transformer.fit_transform(car_sales_filled_train)
transformed_X_test = transformer.transform(car_sales_filled_test)

debug(2, transformed_X_train.toarray())
model = RandomForestRegressor()
model.fit(transformed_X_train, y_train)
print(model.score(transformed_X_test, y_test))