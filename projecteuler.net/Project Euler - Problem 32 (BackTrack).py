# Project Euler - Problem 32

import time
import string

startTime = time.time()

thisset = {0} # set
# backtrack
sz = 9
mark = [0 for i in range(sz)]

def BackTrack(idx, s):
    
    # print(cc)
    if(idx == sz):        
        # divide 
        for i in range(sz - 2):
            for j in range(i + 1, sz - i - 1):
                s1 = s[0: i + 1]
                s2 = s[i + 1: j + 1]
                s3 = s[j + 1: sz]
                if int(s1) * int(s2) == int(s3):
                    thisset.add(int(s3))
        return
    
    for i in range(sz):
        if mark[i] == 0:
            mark[i] = 1
            BackTrack(idx + 1, s + str(i+1))
            mark[i] = 0               
   
BackTrack(0, '')
answ = 0
for item in thisset:
    answ += item
    
print (answ)
print("Total Time:" + str(time.time() - startTime))