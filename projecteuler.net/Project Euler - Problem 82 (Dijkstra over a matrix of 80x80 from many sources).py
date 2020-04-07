# Project Euler - Problem 82

import time

startTime = time.time()

# file with data
file = open('c:\\Users\\LUISMO\\lmo.in', 'r')

lim = 80
infinite = 100000000000
# matrix
mt = [ [0 for i in range(100)] for j in range(100) ]

# reading matrix
for i in range(lim):
    data = file.readline().split()
    for j in range(lim):
        mt[i][j] = int(data[j])

# movement arrays
xs = [0, 0, 1, -1]
ys = [1, -1, 0, 0]

# ISS
di = [ [infinite for i in range(100)] for j in range(100) ]
mark = [ [0 for i in range(100)] for j in range(100) ]
# start (from many sources)
for i in range(80):
    di[i][0] = mt[i][0]
taken = 80;

while taken < lim*lim:
    # find min
    mn = infinite
    idxR = -1
    idxC = -1
    for i in range(lim):
        for j in range(lim):
            if mark[i][j] == 0 and di[i][j] < mn:
                mn = di[i][j]
                idxR = i
                idxC = j
    mark[idxR][idxC] = 1
    taken = taken + 1
    # for each adjacent -> relax
    for i in range(4):
        xnext = idxR + xs[i]
        ynext = idxC + ys[i]
        # if not marked and can be relaxed
        if mark[xnext][ynext] == 0:
            if di[ idxR ][ idxC ] + mt[xnext][ynext] < di[xnext][ynext]:
                di[xnext][ynext] = di[idxR][ idxC] + mt[xnext][ynext]
#print solution

mn = infinite
for i in range(80):
    mn = min(mn, di[i][79])

print(mn)
# print total time of execution
print("Total Time:" + str(time.time() - startTime))

