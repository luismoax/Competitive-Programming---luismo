# Project Euler - Problem 69

import sys
import time

startTime = time.time()

lim = 1000001
sieve = [0 for i in range(lim)]
phi = [0 for i in range(lim)]

# Erathostenes Sieve
def buildSieve():
    for i in range(2, lim, 2):
        sieve[i] = 2
    
    for i in range(3, lim, 2):
        if sieve[i] == 0:
            for j in range(i, lim, i):
                sieve[j] = i
                
# Euler's Totien Function
def buildTotient():
    buildSieve()
    for i in range(2, lim):
        phi[i] = EulerTotient(i)
        
# finds the prime divisors of x            
def primeDivisors(x):
    mp = {}
    while x > 1:
        mp[sieve[x]] = 1
        x //= sieve[x]
    lst = []
    for item in mp:
        lst.append(item)
    return lst;

# finds Phi(x) for a certain number
def EulerTotient(x):
    primDiv = primeDivisors(x)        
    answ = 0
    sz = len(primDiv)    
    for i in range(0, (1<<sz)):
        prod = 1
        cnt = 0
        for j in range(0, sz):
            if ((1<<j) & i) > 0:
                prod *= primDiv[j]
                cnt += 1
            
        if cnt % 2 == 1:
            answ -= x // prod
        else: answ += x // prod
    return answ

buildTotient()

mx = 0
best = -1

for i in range(2, lim):
    k = i / phi[i]
    if k >= mx:
        mx = k
        best = i

print(best)


print ("Total Time:" + str(time.time() - startTime))