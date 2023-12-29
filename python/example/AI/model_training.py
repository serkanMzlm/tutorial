#!/usr/bin/python3

#Makine öğrenimi modelinin eğitildiği Python dosyası
from sklearn.ensemble import RandomForestClassifier

# random_state 0 olmasının sebebi ön tanımlı değeleri kullanmaktır.
clf = RandomForestClassifier(random_state = 0) 
x = [[1, 2, 3], [10, 11, 12], [100, 200, 300]]
y = [0, 1, 2]
clf.fit(x, y)

print(clf.predict(x))
print(clf.predict([[1,1,1], [150,200,200]]))