def solve(n) :
    if n <= 0 :
        return 0
    elif n == 1:
        return 1
    elif n == 2:
        return 2
    
    l = [0 for i in range(n+1)]    
    l[0] = 0
    l[1] = 1
    l[2] = 2
    
    for i in range(3,n+1):
        l[i] = l[i-1] + l[i-2]
    return l[n]%10007

data = int(input())
print(solve(data))