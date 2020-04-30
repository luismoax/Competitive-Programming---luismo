# Project Euler - Problem 40

import sys
import math
import time
import datetime

startTime = time.time()

champernowne = ""

for i in range(1, 200001):
    champernowne += str(i)
    
champernowne = '0' + champernowne;

answ = 1
answ *= int(champernowne[1])
answ *= int(champernowne[10])
answ *= int(champernowne[100])
answ *= int(champernowne[1000])
answ *= int(champernowne[10000])
answ *= int(champernowne[100000])
answ *= int(champernowne[1000000])

print(answ)

print ("Total Time:" + str(time.time() - startTime))