# Project Euler - Problem 27 Quadratic primes

import sys
import math
import time

startTime = time.time()

lim = 1000001

# >> Erathostenes' Sieve
sieve = [0 for i in range(lim)]

def buildSieve():
    sieve[0] = sieve[1] = -1
    primes = []
    primes.append(2) 
    for i in range(2, lim, 2):
        sieve[i] = 2
    
    for i in range(3, lim, 2):
        if sieve[i] == 0:
            primes.append(i)
            for j in range(i, lim, i):
                sieve[j] = i
    return primes
# << Erathostenes' Sieve

# >> run
def F(a, b):
    cnt = 0
    for n in range(0, 1000):
        k = n * n + n * a + b
        if(sieve[k] == k):
            cnt += 1
        else: 
            break 
    return cnt
# << run

# get all primes
primes = buildSieve()

# lenght of the longest chain
mxLen = 0
# answer
answ = 0

for a in range(0, 1000):
    for b in primes:
        if b > 1000:
            break
        cnt1 = F(a, b)
        cnt2 = F(-a, b)
        cnt3 = F(a, -b)
        cnt4 = F(-a, -b)
        # if cnt1 >= 40:
        #     print(str(a) + '  ' + str(b) + ' = ' + str(cnt1) )
        # if cnt2 >= 40:
        #     print(str(-a) + '  ' + str(b) + ' = ' + str(cnt2) )
        # if cnt3 >= 40:
        #     print(str(a) + '  ' + str(-b) + ' = ' + str(cnt3) )
        # if cnt4 >= 40:
        #     print(str(-a) + '  ' + str(-b) + ' = ' + str(cnt4) )
        if cnt1 > mxLen:
            answ = a * b
            mxLen = cnt1
        if cnt2 > mxLen:
            answ = -a * b
            mxLen = cnt2
        if cnt2 > mxLen:
            answ = a * -b
            mxLen = cnt3
        if cnt2 > mxLen:
            answ = -a * -b
            mxLen = cnt4
        
# print answer
print("Answer: ", end="")
print(answ)

print ("Total Time:" + str(time.time() - startTime))