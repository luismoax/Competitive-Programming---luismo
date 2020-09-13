# python

def binPow(bs, exp):
    pw = bs
    aux = 1
    while exp > 0:        
        if exp % 2 == 1:
           aux = aux * pw          
        # pw = bs ^ (2^i)
        pw = pw * pw
        exp = exp // 2    
    return aux

N = 0
N = int(input())

lst = []

# for each possible product of a power of two (until 62) and a power of five (until 26)
for i in range(0, 63):
    for j in range(0, 27):
        twPw = binPow(2, i)
        fvPw = binPow(5, j)
        
        X = twPw * fvPw
        # if X divides N
        if N % X == 0:
            lst.append(X)
              
lst.sort()
print(len(lst))
for item in lst:
    print(item)