# Project Euler - Problem 49

import sys
import time

startTime = time.time()

lim = 10000
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

primes = []
for i in range(1001, 9999, 1):
    if(sieve[i] == i):
        primes.append(i)
        
for i in range(len(primes)):
    for j in range(i + 1, len(primes)):
        if(anagramNumbers(primes[i], primes[j])):
            for k in range(j + 1, len(primes)):
                if(anagramNumbers(primes[j], primes[k])):
                    if(primes[j] - primes[i] == primes[k] - primes[j]):
                        print(str(primes[i]) + str(primes[j]) + str(primes[k]))


print ("Total Time:" + str(time.time() - startTime))