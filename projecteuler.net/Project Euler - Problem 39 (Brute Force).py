# Project Euler - Problem 39 - Integer right triangles 
# Idea: Brute Force

import time
startTime = time.time()

#
lim = 1001
answ = 0
mx = 0
for per in range(3, lim):
    cnt = 0
    for a in range(1, per // 3):        
        b = a;
        while (per - a - b > b):
            c = per - a - b
            if (a*a + b*b == c*c):
                # print(str(per) + ' ' + str(a) + ' ' + str(b) + ' ' + str(c))
                cnt += 1
            b += 1
    if(cnt > mx):
        mx = cnt
        answ = per
        
# print(mx)
print(answ)

print("Total Time:" + str(time.time() - startTime))