# Project Euler - Problem 19

import sys
import math
import time
import datetime

startTime = time.time()

answ = 0
# # days per month
daysPerMonth = [0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]

year = 1900
month = 1
leap = 0
day = 1 # it was tuesday on 1901/01/01

# go month by month checking the first day
while year <= 2000:
    if month == 1:
        year += 1
        
    if day == 6:
        answ += 1
    
    day = (day + daysPerMonth[month]) % 7
    # in case of a leap year
    if year % 4 == 0 and month == 2:
        day = (day + daysPerMonth[month] + 1) % 7
    
    month += 1
    if(month == 13):
        month = 1
        

print(answ)

print ("Total Time:" + str(time.time() - startTime))