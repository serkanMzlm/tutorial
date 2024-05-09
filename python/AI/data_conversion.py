#!/bin/python3 

"""
Gereksiz ve geçersiz verileri temizlemek, bilgisayarın
anladığı şekilde cevirme yapmak lazımdır.
"""

import pandas as pd
import numpy as np
# from sklearn.ensemble import RandomForestClassifier
from sklearn.ensemble import RandomForestRegressor
from sklearn.model_selection import train_test_split
from sklearn.preprocessing import OneHotEncoder
from sklearn.compose import ColumnTransformer

from myLib.debug import debug
data = pd.read_csv("data/car_sales_extended.csv")
X = data.drop("Price", axis=1)
y = data["Price"]

# Doors kısmında bulunan dataları ve kaç tane olduğunu gösterir.
debug(1, data["Doors"].value_counts()) 
debug(2, data.dtypes)
model = RandomForestRegressor()

"""
String değişkenleri bilgisayarın anladığı şekilde cevirmek için
"one hot" modelini kullanık bu model stringleri Make , Colour gibi
sütün başlığı yapar ve bu kısımlara eğer uygunsa 1 değilse 0 yazar.
"remainder" kısmı belirtiğimiz başlıkların dışındaki sütünlara ne yapılıcağını
karar verir. Bu kodda aynı şekilde yazılmasını sağladık. 
"""
categorical_features = ["Make", "Colour", "Doors"]
one_hot = OneHotEncoder()
tf = ColumnTransformer([("one_hot", one_hot,
                         categorical_features)],
                         remainder="passthrough") 
tf_X = tf.fit_transform(X)

# Benzer işlev tek farkı daha anlaşılır olması 
dummies = pd.get_dummies(data[["Make", "Colour", "Doors"]])

np.random.seed(42)
X_train, X_test, y_train, y_test = train_test_split(tf_X, y, test_size=0.2)
# X_train, X_test, y_train, y_test = train_test_split(dummies, y, test_size=0.2)
# X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2)

model.fit(X_train, y_train)
print(model.score(X_test, y_test))