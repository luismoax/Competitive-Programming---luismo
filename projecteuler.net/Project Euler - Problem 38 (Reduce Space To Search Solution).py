# Project Euler - Problem 38

import sys
import math
import time

startTime = time.time()


def check(nmb):
    arr = [0 for i in range(0, 11)]
    
    while nmb > 0:
        arr[nmb % 10] += 1
        nmb //= 10
        
    for i in range(1, 10):
        if arr[i] != 1:
            return False
    return True

answ = ''
for i in range(9000, 10000):
    s = ''
    for j in range(1, 10):
        s += str(i * j)
        if len(s) > 9:
            break
        if len(s) == 9:            
            flag = check(int(s))            
            if(flag):
                answ = s
                
print(answ)

print ("Total Time:" + str(time.time() - startTime))