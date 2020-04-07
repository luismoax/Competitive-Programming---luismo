# Project Euler - Problem 23

import time

startTime = time.time()
# problem's limit
lim = 28123
abundant = []
# find all abundant numbers and add them to the list
for i in range(lim + 1):
    sm = 0
    j = 1
    while j * j <= i:
        if i % j == 0:
            sm += j
            if(j != i / j):
                sm+= i / j
        j+= 1
    sm -= i
    if sm > i:
        abundant.append(i)
    # if the current abundan added to the lowest is greater
    # than the limit
    if i + 12 > lim:
        break
    
hh = [0 for i in range(lim + 1)]
# mark all numbers below the limit that can be added using abundant numbers
for i in range(0, len(abundant)):
    for j in range(0, len(abundant)):
        if abundant[i] + abundant[j] <= lim:
            hh[abundant[i] + abundant[j]] = 1

answ = 0    
for i in range(1, len(hh)):
    if hh[i] == 0:
        answ += i

print(answ)

print("Total Time:" + str(time.time() - startTime))