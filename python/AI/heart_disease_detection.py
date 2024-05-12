#!/usr/bin/python3

"""
X: Yapay zeka için girdi fonksiyonumu belirtir.
Y: X değişkeninden tahmin edilmeye çalışılan değerleri tutar. 
"""

import pandas as pd
import pickle

# Sınıflandırma için kullanılır
from sklearn.ensemble import RandomForestClassifier 
# Modeli eğiştmek için datayı bölmek vs gibi işlemler için kullanılır
from sklearn.model_selection import train_test_split
from sklearn.metrics import classification_report, confusion_matrix, accuracy_score

from myLib.debug import debug

# 1. adım "Getting the data ready"
data = pd.read_csv("data/heart-disease.csv")

debug(1, data.head())

X = data.drop("target", axis=1) # "target" kısmını belirtiyoruz ve axis=1 kısmıda bize sütün siliniceğini belirtir.
y = data["target"]
debug(2, X.head())
debug(2, y.head())

# 2. adım "Choose the right estimator/algorithm for our problems"
clf = RandomForestClassifier(n_estimators=100)
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2) # %20 test verisi olucak
debug(3, clf.get_params())
clf.fit(X_train, y_train)

# 3. adım "Fit the model/algorithm and use it to make predictions on our data" (prediction)
y_preds = clf.predict(X_test)
debug(4, y_preds)

# 4. Evaluating a model
print(f"Egitim Seti Doğruluğu: {clf.score(X_train, y_train) * 100:.2f}%") # Eğitim seti olduğu için 1 yani hepsini bilicektir.
print(f"Kontrol Seti Doğruluğu: {clf.score(X_test, y_test) * 100:.2f}%") # Setin ne derece doğru olduğunu bulmamızı sağlar.
print("--"*30)
print(classification_report(y_test, y_preds))  # Aynı şekilde bize model hakkında bilgiler verir
print("--"*30)

#           Tahmin Edilen
#       Negatif    Pozitif
# Gerçek Negatif   TN         FP
# Gerçek Pozitif   FN         TP
# Bu çıktıda F ile başlayan yanlış tahmin sayısını ifade eder
# örnek olarak gerçekte pozitif olup negatif değer ifade etmek için FN 
print(confusion_matrix(y_test, y_preds))
print(f"Kontrol Seti Doğruluğu: {accuracy_score(y_test, y_preds) * 100:.2f} %")
print("--"*30)

# 5. Experiment to improve (hyperparameter tuning)
for i in range(10, 100, 10):
    clf = RandomForestClassifier(n_estimators=i).fit(X_train, y_train)
    model = RandomForestClassifier(n_estimators=i).fit(X_train, y_train)
    print(f"{i} model => test set: {model.score(X_test, y_test)}", end="\n\n")

pickle.dump(model, open("model/random_forst_model_1.pkl", "wb"))

load_model = pickle.load(open("model/random_forst_model_1.pkl", "rb"))
print(load_model.score(X_test, y_test))