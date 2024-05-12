#!/usr/bin/python3

"""
Farklı modeller Coefficient of Determination değerleri kıyaslaması
İlerleme yapılırken "sklearn learn machine learning map" kısmına bakılır.
"""

import numpy as np
import pandas as pd

from sklearn.ensemble import RandomForestRegressor
from sklearn.linear_model import Ridge
from sklearn.datasets import fetch_california_housing
from sklearn.model_selection import train_test_split

from myLib.debug import debug

housing = fetch_california_housing()
debug(1, housing)

housing_df = pd.DataFrame(housing["data"], columns=housing["feature_names"])
housing_df["target"] = housing["target"]
debug(2, housing_df)

np.random.seed(1)
X = housing_df.drop("target", axis=1)
y = housing_df["target"]

X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2)

model_ridge = Ridge()
model_ridge.fit(X_train, y_train)
ridge_score = model_ridge.score(X_test, y_test)

model_forest = RandomForestRegressor()
model_forest.fit(X_train, y_train)
forest_score = model_forest.score(X_test, y_test)

print(f"Ridge Model Coef:{ridge_score*100:.2f}% \nRandom Forest Regressor Model Coef: {forest_score*100:.2f}%")