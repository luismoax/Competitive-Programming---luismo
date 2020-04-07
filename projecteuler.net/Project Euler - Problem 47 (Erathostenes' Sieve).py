# Project Euler - Problem 47

import time
# get the start time

start_time = time.time()
# Erathostenes Sieve
lim = 1000000
numberOfPrimes = [0 for i in range(lim)]
sieve = [0 for i in range(lim)]
def buildSieve():
    for i in range(2, lim, 2):
        sieve[i] = 2
        numberOfPrimes[i] += 1
    
    for i in range(3, lim, 2):
        if sieve[i] == 0:
            for j in range(i, lim, i):
                sieve[j] = i;
                numberOfPrimes[j] += 1

buildSieve()

for i in range(2, lim, 1):
    if numberOfPrimes[i] == numberOfPrimes[i-1] and numberOfPrimes[i] == numberOfPrimes[i-2] and numberOfPrimes[i] == numberOfPrimes[i-3] and numberOfPrimes[i] == 4:
        print(str(i) + ' ' + str(i - 1) + ' ' + str(i-2) + ' ' + str(i-3))
        break

print('Total Time:' + str(time.time() - start_time))
