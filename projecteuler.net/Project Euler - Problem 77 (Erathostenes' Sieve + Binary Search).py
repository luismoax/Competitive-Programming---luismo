# Project Euler - Problem 77

import sys
import time

startTime = time.time()

lim = 1000
sieve = [0 for i in range(lim)]
phi = [0 for i in range(lim)]
primes = []
# Erathostenes Sieve
def buildSieve():
    primes.append(2)
    for i in range(2, lim, 2):
        sieve[i] = 2
    
    for i in range(3, lim, 2):
        if sieve[i] == 0:
            primes.append(i)
            for j in range(i, lim, i):
                sieve[j] = i
                

lmo = len(primes)
dp = [[0 for i in range(lmo)] for j in range(lmo)] 
mark = [ [0 for i in range(lmo)] for j in range(lmo)] 

def primeSummations(idx, nmb):
    if(nmb == 0):
        return 1
    
    if(idx < 0):
        return 0
    
    s1 = 0
    if(nmb - primes[idx] >= 0):
        s1 = primeSummations(idx, nmb - primes[idx])
    s2 = primeSummations(idx - 1, nmb)
    
    return s1 + s2

buildSieve()

le = 2
ri = 100

# upper bound
while le != ri:
    mid = (le + ri) // 2
    k = primeSummations(len(primes) - 1, mid)    
    if k > 5000:
        ri = mid
    else: le = mid + 1 


print(le)
print(primeSummations(len(primes) - 1, le))


print ("Total Time:" + str(time.time() - startTime))