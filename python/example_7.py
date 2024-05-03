#!/bin/python3

image = [
    [0, 0, 0, 1, 0, 0, 0, 0],
    [0, 1, 1, 1, 1, 1, 0, 0],
    [0, 1, 1, 1, 1, 1, 0, 0],
    [1, 0, 1, 0, 0, 1, 0, 0],
    [1, 0, 1, 1, 0, 1, 0, 0],
    [1, 0, 0, 0, 0, 1, 0, 1],
    [1, 0, 0, 0, 0, 1, 0, 1],
    [1, 1, 0, 0, 1, 1, 1, 1],
    [1, 0, 0, 1, 0, 1, 1, 1]
]

empty = " "
filled = "*"

def show():
    for row in image:
        for pixel in row:
            if pixel == 1:
                print(filled, end='')
            else:
                print(empty, end='')
        print()


show()
