repeatNum = int(input())
stack = list()
result = list()
i=1
for a in range(1, repeatNum+1):
    targetNum = int(input()) 
    while i <= targetNum :
        stack.append(i)
        result.append('+')
        i += 1
    if targetNum == stack[-1]:
        result.append('-')
        stack.pop()
    else :
        print("NO")
        exit(0)

print('\n'.join(result))
      
      
