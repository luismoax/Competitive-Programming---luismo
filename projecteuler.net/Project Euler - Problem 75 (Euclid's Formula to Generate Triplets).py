# Project Euler - Problem 75
# Solution was heavily influenced by
# https://euler.stephan-brumme.com/75/
# Use of Euclid's Formula to generate Pythagorean Triplets
# a = m*m - n*n, b = 2*m*n, c = m*m + n*n where gcd(n, m) = 1 and
# n and m are not both odd

import sys
import math
import time

startTime = time.time()

# Original Limit
L = 1500000

# Limit of iterations (can be deduced from the fact that:
# c = n*n + m*m <= L)
lm = int(math.ceil(math.sqrt( L//2 )))

# map
mp = {}

for m in range(2, lm):
    for n in range(1, m):
        if math.gcd(m, n) == 1 and (m + n) % 2 == 1:
            a = m * m - n * n
            b = 2 * m * n
            c = m * m + n*n        
            k = 1        
            while k * (a + b + c) <= L:
                
                if mp.keys().__contains__(k * (a + b + c)):
                    mp[k * (a + b + c)] += 1
                else:
                    mp[k * (a + b + c)] = 1            
                k+= 1

# Finding answer          
answ = 0
for item in mp.keys():
    if mp[item] == 1:
        answ += 1    

print(answ)

print ("Total Time:" + str(time.time() - startTime))