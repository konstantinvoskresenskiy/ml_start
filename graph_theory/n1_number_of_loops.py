import matplotlib.pyplot as plt
import networkx as nx
import numpy as np

schet=0
index=0
n = int(input("Введите размер графа: "))
matrix = np.zeros((n, n), dtype=int)

print("Введите элементы матрицы смежности:")

for i in range(n):
    for j in range(n):
        matrix[i][j] = int(input(f"Элемент [{i}][{j}]: "))

print("Матрица смежности:")
print(matrix)
print("Индексы петель:")

for i in range(n):
    for j in range(n):
        if (i==j) and (matrix[i][j]==1):
            schet+=1
            index=i
            print(index)
        
if (schet==0):
    print("NO LOOPS")
