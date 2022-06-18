# Problem: G. White-Black Balanced Subtrees
# Link: https://codeforces.com/contest/1676/problem/G


# file_name = 'd:\lmo.in'
# file = open(file_name)

# Recusrssion handle
import sys,threading
sys.setrecursionlimit(5*(10**5))
threading.stack_size(10**8)


def DFSBalanced(idx, visited, adj, blacks, whites):
    visited[idx] = 1

    if(color[idx] == 1):
        blacks[idx] = 1
    else: 
        whites[idx] = 1

    ret = 0

    for i in range(0, len(adj[idx])):
        nxt = adj[idx][i]
        if(visited[nxt] == 0):
            k = DFSBalanced(nxt, visited, adj, blacks, whites)
            ret = ret + k
            blacks[idx] = blacks[idx] + blacks[nxt]
            whites[idx] = whites[idx] + whites[nxt]        
    
    if whites[idx] == blacks[idx]:
        ret = ret + 1

    return ret

t = int(input())

while t > 0:
    n = int(input())

    # adj
    adj = [[] for i in range(0, n)]

    # reading parents
    pi = [-1 for i in range(0, n)] 
    pi[0] = -1   
    parents = input().split(" ")
    for i in range(0, n - 1):
        pi[i] = int(parents[i]) - 1
        adj[pi[i]].append(i + 1)

    # reading colors
    color = [-1 for i in range(0, n)]
    strip = input()    
    for i in range(0, n):
        if(strip[i] == 'B'):
            color[i] = 1

    visited = [0 for i in range(0, n)]
    whites = [0 for i in range(0, n)]
    blacks = [0 for i in range(0, n)]

    answ = DFSBalanced(0, visited, adj, blacks, whites)
    # print answer
    print(answ)

    t = t - 1
