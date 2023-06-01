inputs = list(map(int,input().split()))

ascending = True
descending = True

def test() :
    gap = inputs[0] - inputs[1]
    i=1
    while i < len(inputs) :
        if(gap != inputs[i-1] - inputs[i]) :
            print("mixed")
            return
        i += 1
       
    if gap < 1 :
        print("ascending")
    else : 
        print("descending")
        
def CourseAnswer() :
    for i in range(1,8) :
        if inputs[i-1] < inputs[i] :
            descending = False
        elif inputs[i-1] > inputs[i] :
            ascending = False
    
    if(ascending) :
        print("ascending")
    elif(descending) :
        print("descending")
    else :
        print("mixed")
            
        
test()

