# Project Euler - Problem 53

import time

startTime = time.time()

# pascal triangle
pascal = [ [0 for i in range(101)] for i in range(101)]
# generate pascal triangel
def buildPascal():
    pascal[0][0] = 1
    for i in range(1, 101):
        pascal[i][i] = pascal[i][0] = 1
        for j in range(1, i):
            pascal[i][j] = pascal[i-1][j] + pascal[i-1][j - 1]
            

buildPascal()
# count
answ = 0
for i in range(101):
    for j in range(101):
        if pascal[i][j] > 1000000:
            answ += 1
# print answer
print(answ)    
print("Total Time:" + str(time.time() - startTime))