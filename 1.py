import numpy as np
from numpy import *
rows = int(input("输入n的值 "))
matrix = []
for i in range(rows):


    row = list(map(float, input(f"Enter row {i+1} values separated by spaces: ").split()))


    matrix.append(row)
    
try:
    
    B=np.linalg.inv(matrix)
except:
    print("矩阵不存在逆矩阵")
else:
    print(B)
