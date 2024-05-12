#!/usr/bin/python3

import pandas as pd
# import numpy as np

# from sklearn.ensemble import RandomForestClassifier
from sklearn.ensemble import RandomForestRegressor
from sklearn.model_selection import train_test_split
from sklearn.preprocessing import OneHotEncoder
from sklearn.compose import ColumnTransformer

from myLib.debug import debug
data = pd.read_csv("data/car_sales_extended_missing_data.csv")
debug(1, data.isna().sum()) # Boş değerleri gösterir.
debug(2, len(data)) #Datanın uzunluğunu görmemizi sağlar.

# Nan değelerin yerine alabilicek verilerle değiştiemyi sağlarız
data["Make"] = data["Make"].fillna("missing")
data["Colour"] = data["Colour"].fillna("missing")
data["Odometer (KM)"] = data["Odometer (KM)"].fillna(data["Odometer (KM)"].mean())

debug(1, data["Doors"].value_counts()) # Veri hakkında bilgi verir. Hangi gruplamadan kaç tane olduğu bilgisi

# Doors  4.0 -> 811, 5.0 -> 75, 3.0 -> 64
data["Doors"] = data["Doors"].fillna(4) # Coğunlukla 4 olduğu için ortalam almak mantıklı değil küsüraltı kapı olmaz
data.dropna(inplace=True) #Nan değerlerin silinmesini sağlar.
debug(2, len(data)) #Datanın uzunluğunu görmemizi sağlar.
debug(1, data.isna().sum()) # Boş değerleri gösterir.

X = data.drop("Price", axis=1)
y = data["Price"]

categorical_features = ["Make", "Colour", "Doors"]
one_hot = OneHotEncoder()
transformer = ColumnTransformer([("one_hot",
                                   one_hot,
                                   categorical_features)],
                                   remainder="passthrough")

tf_X = transformer.fit_transform(data)

X_train, X_test, y_train, y_test = train_test_split(tf_X, y, test_size=0.2)
model = RandomForestRegressor()
# model = RandomForestClassifier(10)
model.fit(X_train, y_train)
print(f"dogruluk: {model.score(X_test, y_test) * 100:.2f}")