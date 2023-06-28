#프린터 큐

import sys
input = sys.stdin.readline
def mySolve() :
    testCase = int(input())
    
    for a in range(testCase) :
        docuNum, pick = map(int,input().split(' ')) # 문서 개수와, 체크할 위치 선택
        arDocu = [(i,j) for i,j in zip(list(map(int,input().split(' '))),range(docuNum))] # (우선순위, 문서 위치) 리스트를 만듬
        printCount=0 # 프린트 카운트를 통해 pick == 문서위치 일경우 출력을 위해
        
        while len(arDocu) > 0 :
            maxValue = max(arDocu, key = lambda x:x[0]) # 문서 중 우선순위가 가장 빠른 위치를 얻어옴
            if(maxValue != arDocu[0]) : # 0번째가 아니라면 큐를 뒤로 보내야함
                maxIndex = arDocu.index(maxValue)
                arDocu = arDocu[maxIndex:] + arDocu[:maxIndex] # 우선순위 위치까지 내용을 뒤로 보냄
            printCount += 1
            
            if(arDocu[0][1] == pick) : # 큐 맨앞의 문서위치와 pick 비교해서, 같을 경우 출력하고, 다음 케이스를 받아옴
                print(printCount)
                break
            
            del arDocu[0]
            
            
def CourseSolve() :
    testCase = int(input())

    for a in range(testCase) :
        docuNum, pick = map(int,input().split(' ')) # 문서 개수와, 체크할 위치 선택
        arDocu = list(map(int,input().split(' ')))
        arDocu = [(value,idx) for idx,value in enumerate(arDocu)]
        printCount=0
        
        while len(arDocu) > 0 :
            if arDocu[0][0] != max(arDocu, key = lambda x:x[0])[0] :
                arDocu.append(arDocu.pop(0))
            else :
                printCount += 1
                if arDocu[0][1] == pick :
                    print(printCount)
                    break
                arDocu.pop(0)

CourseSolve()
            