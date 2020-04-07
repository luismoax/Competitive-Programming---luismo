# Project Euler - Problem 74

import sys
import time

startTime = time.time()

fact = [0 for i in range(0, 10)]
fact[0] = 1
for i in range(1, 10):
    fact[i] = i * fact[i-1]
   
def chainLength(nmb):
    cnt = 1
    mp = {}
    mp[nmb] = 1
    x = sumFactDigis(nmb)
    while mp.__contains__(x) == False:
        cnt += 1
        mp[x] = 1
        x = sumFactDigis(x)
        
    return cnt

def sumFactDigis(nmb):
    ret = 0
    while nmb > 0:
        ret += fact[nmb % 10]
        nmb //= 10
    return ret

answ = 0
for i in range(1, 1000000):
    if chainLength(i) == 60:
        # print(i)
        answ += 1

print(answ)


print ("Total Time:" + str(time.time() - startTime))