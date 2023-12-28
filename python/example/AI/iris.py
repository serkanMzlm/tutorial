#!/usr/bin/python3
from sklearn.datasets import load_iris
from sklearn.model_selection import train_test_split
import matplotlib.pyplot as plt
import pandas as pd

iris = load_iris()
# print(iris.keys())
# print(iris['DESCR']) Kısa bilgilendirme içerir
# print(iris['target_names'])
# print(iris['feature_names'])
# print(type(iris['data']))
#########################################

print("Toplam Data",iris['data'].shape) # Datanın boyutlarını gösterir.
print("___________________________________________________________")

# Veriler Test ve eğitim olarak iki gruba ayrılır
x_train, x_test, y_train, y_test = train_test_split(iris['data'], 
                                                    iris['target'], random_state=0)

print("X Train: ", x_train.shape)
print("Y Train: ", y_train.shape)
print("X Test: ", x_test.shape)
print("Y Test: ", y_test.shape)

# Data frame yapısına çevrilir.
iris_df = pd.DataFrame(x_train, columns=iris.feature_names)

# Saçılım matrix grafiği çizilir.
pd.plotting.scatter_matrix(iris_df, c = y_train, figsize=(15, 15), marker='o',
                        hist_kwds={'bins': 20}, s = 80, alpha = 0.8)
plt.show()