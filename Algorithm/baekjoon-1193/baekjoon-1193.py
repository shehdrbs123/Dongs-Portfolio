num = int(input())
n = 1
pos = 0
while True :
    if pos+n < num :
        pos += n
        n += 1        
    else :
        break

num -= pos
if n%2 == 0 :
    print(num,end='')
    print('/',end='')
    print(n-num+1)
else :
    print(n-num+1,end='')
    print('/',end='')
    print(num)