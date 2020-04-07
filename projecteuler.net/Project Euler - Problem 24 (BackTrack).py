# Project Euler - Problem 24

import time

startTime = time.time()

cc = 0
sz = 10
mark = [0 for i in range(sz)]

def BackTrack(idx, s):
    global cc
    # print(cc)
    if(idx == sz):        
        cc += 1
        if cc == 1000000:
            print(s)       
        return

    for i in range(sz):
        if mark[i] == 0 and cc < 1000000:
            mark[i] = 1
            BackTrack(idx + 1, s + str(i))
            mark[i] = 0
      
BackTrack(0, '')

print("Total Time:" + str(time.time() - startTime))