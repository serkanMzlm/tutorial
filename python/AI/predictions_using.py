#!/usr/bin/python3

import pandas as pd
import numpy as np
from sklearn.ensemble import RandomForestClassifier 
from sklearn.model_selection import train_test_split
from sklearn.metrics import accuracy_score

from myLib.debug import debug

data = pd.read_csv("data/heart-disease.csv")
debug(1, len(data))

X = data.drop("target", axis=1)
y = data["target"]

X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2)
model = RandomForestClassifier()
model.fit(X_train, y_train)

score = model.score(X_test, y_test)

# Arka planda yaptığı
y_preds = model.predict(X_test) # Giriş verilerine göre çıktı üretir.
score_2 = np.mean(y_preds == y_test)
# ya da 
score_3 = accuracy_score(y_test, y_preds)

# Olasılık olarak gruplamada değerleri döndürür. Örnek olarak 0.89, 0.11
predict_proba_data = model.predict_proba(X_test[:5])
predict_data = model.predict(X_test[:5])

print(f"""score: {score:.2f}%
      \nscore_2: {score_2:.2f}%
      \nscore_3: {score_3:.2f}%""")

print(f"predict_proba_data: {predict_proba_data}",
      f"predict_data: {predict_data}", sep='\n')