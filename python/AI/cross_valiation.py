#!/usr/bin/python3

import numpy as np
import pandas as pd
import matplotlib.pyplot as plt

from sklearn.metrics import roc_curve
from sklearn.model_selection import cross_val_score
from sklearn.ensemble import RandomForestClassifier
from sklearn.model_selection import train_test_split

from myLib.debug import debug

np.random.seed(2)
data = pd.read_csv("data/heart-disease.csv")

X = data.drop("target", axis=1)
y = data["target"]

X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2)
model = RandomForestClassifier(n_estimators=100)
model.fit(X_train, y_train)

single_score = model.score(X_test, y_test)

"""
cross_val_score komutu, veriyi belirtilen sayıda farklı parçaya böler, 
böylece farklı parçalara ayrılmış test kümeleri elde edilir. Bu şekilde, 
veri seti bir yere yığılmış olsa bile, veri farklı yerlerden farklı 
şekillerde bölündüğü için daha güvenilir sonuçlar elde edilir. Örneğin, 
5 farklı kat sayısı çıkar ve bu kat sayılarının ortalaması alınarak genel 
bir sonuç elde edilir.
"""
crossval_score = np.mean(cross_val_score(model, X, y, cv=5))
# 5 tane coef değeri gözükücektir. Bunun nedeni model 5 farklı yerden  
# test versi oluşturup tek tek denemesidir.
debug(1, cross_val_score(model, X, y, cv=5)) 
print("single score:", single_score, "\ncross_vall score:", crossval_score)

y_probs = model.predict_proba(X_test)

# [0][1] index de bulunan veriler alınır
y_probs_positive = y_probs[:, 1]
fpr, tpr, thresholds = roc_curve(y_test, y_probs_positive)
def plot_roc_curve(fpr, tpr):
    """
    Plots a ROC curve given the false positive rate (fpr)
    and true positive rate (tpr) of a model.
    """
    # Plot roc curve
    plt.plot(fpr, tpr, color="orange", label="ROC")
    plt.plot([0, 1], [0, 1], color="darkblue", linestyle="--", label="Guessing")
    
    plt.xlabel("False positive rate (fpr)")
    plt.ylabel("True positive rate (tpr)")
    plt.title("Receiver Operating Characteristic (ROC) Curve")
    plt.legend()
    plt.show()

plot_roc_curve(fpr, tpr)

plt.show()