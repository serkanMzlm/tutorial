#! /usr/bin/python3

from keras import layers
from keras import models
from keras.datasets import mnist

(x_train, y_train), (x_test, y_test) = mnist.load_data()

network = models.Sequential()
network.add(layers.Dense(512, activation='relu', input_shape=(28 * 28,)))
network.add(layers.Dense(10, activation='softmax'))
network.compile(optimizer='rmsprop', loss='sparse_categorical_crossentropy', metrics=['accuracy'])

x_train = x_train.reshape((60000, 28*28))
x_test = x_test.reshape((10000, 28*28))

x_train = x_train.astype('float32') / 255
x_test = x_test.astype('float32') / 255

network.fit(x_train, y_train, epochs=5, batch_size=128)

print(network.evaluate(x_test, y_test))

