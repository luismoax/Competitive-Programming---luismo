# Project Euler - Problem 70

import sys
import time

startTime = time.time()

lim = 10000000
sieve = [0 for i in range(lim)]
phi = [0 for i in range(lim)]

# Euler's Totien Function
def buildTotient():
    for i in range(lim):
        phi[i] = EulerTotient(i)

# Erathostenes Sieve
def buildSieve():
    for i in range(2, lim, 2):
        sieve[i] = 2
    
    for i in range(3, lim, 2):
        if sieve[i] == 0:
            for j in range(i, lim, i):
                sieve[j] = i
        
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

# finds if two integers are anagrams
def anagramNumbers(a , b):
    m = {}
    while (a > 0):
        if m.__contains__(a % 10) == False:
            m[a%10] = 1
        else: m[a % 10] = int(m[a % 10]) + 1
        a //= 10
    while (b > 0):
        if m.__contains__(b % 10) == False:
            m[b%10] = -1
        m[b % 10] = int(m[b % 10]) - 1
        b //= 10
    
    for item in m:
        if m[item] != 0:
            return False    
    return True
        
# main from here   
buildSieve()
buildTotient()

mn = 10000000
answ = -1
for i in range(2, lim):    
    if anagramNumbers(i, phi[i]):
        if i / phi[i] < mn:
            mn = i / phi[i]
            answ = i
            
# print the answer
print(answ)

print ("Total Time:" + str(time.time() - startTime))