
def query(cumulative : list, le, ri):
    if le == 0:
        return cumulative[ri]
    return cumulative[ri] - cumulative[le - 1]

N = 0
Q = 0

N = int(input())

arr = [0 for i in range(N)]
cumul = [0 for i in range(N)]

str_arr = input().split()



for i in range(0, N):
    arr[i] = int(str_arr[i])
    cumul[i] = arr[i]
    if i > 0:
        cumul[i] = cumul[i] + cumul[i - 1] 

Q = int(input())

while Q > 0:
    str_arr = input().split()

    le = int(str_arr[0])
    ri = int(str_arr[1])

    answ = query(cumul, le, ri)

    print(answ)

    Q = Q - 1