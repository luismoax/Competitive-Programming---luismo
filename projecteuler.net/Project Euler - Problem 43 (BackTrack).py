# Project Euler - Problem 43

import time

startTime = time.time()
vec = []
#
len = 10
primes = [2, 3, 5, 7, 11, 13, 17] 
mark = [0 for i in range(10)]

# back track
def backtrack(idx, s):
    if idx == len:
        if check(s):  
            x = int(s)
            # print(x)
            vec.append(x)            
        return
    
    for i in range(len):
        if mark[i] == 0:
            mark[i] = 1
            backtrack(idx + 1, s + str(i))
            mark[i] = 0
            
def check(s):
    for i in range(7):
        if int( s[i+1] + s[i+2] + s[i+3] ) % primes[i] != 0:
            return False
    return True    

#execute backtrack
backtrack(0, '')

answ = 0
for item in vec:
    answ += item
# # print answer    
print (answ)

print ("Total Time:", time.time() - startTime)
