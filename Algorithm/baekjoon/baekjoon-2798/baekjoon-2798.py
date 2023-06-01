count, target = map(int,input().split(' '))
arNums = list(map(int,input().split(' ')))

result = 0
length = len(arNums)

def findNums(arNums,index,selected,sumed) :
        global result
        if selected == 3 :
            if(target >= sumed and result < sumed) :
                result = sumed
            return
        
        i=1
        while i+index < length :
            findNums(arNums,i+index,selected+1,sumed+arNums[i+index])
            i += 1
            
            
def mySolve() :
    findNums(arNums,0,0,0)
    print(result)
    
def CourseSolve() :
    global result
    for i in range(0, length) :
        for j in range(i+1, length) :
            for k in range(j+1, length) :
                temp = arNums[i] + arNums[j] + arNums[k]
                if temp <= target :
                    result = max(result,temp)
    print(result)


CourseSolve()
    
# python 2천만 1초에 2천만횟수정도를 처리 할 수 있다.
# c++ 1억