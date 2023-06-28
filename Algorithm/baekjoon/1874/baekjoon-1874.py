repeatNum = int(input())
stack = list()
result = list()
i=1
# 그리디 하게 타겟넘버까지 순서대로 스택을 만드는것임.
# 타겟넘버까지 올라가고, 숫자가 작아질땐 뱉는 형식인대
# 이게 맞지 않는다면, 스택으로는 만들 수 없는 수열인것임.
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

