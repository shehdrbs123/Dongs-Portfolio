import sys
from collections import deque

def Union(p1, p2) :
    x = find(p1)
    y = find(p2)
    if(x != y) :
        parent[y] = x
        sumValue = countTable[x] + countTable[y]
        countTable[x] = sumValue
        countTable[y] = sumValue

        # 네트워크 수 초기화
        find(p1)
    
def find(p) :
    tempParent = parent.get(p)
    if tempParent == None :
        parent[p] = p
        countTable[p] = 1
        tempParent = p
        
    if p == tempParent :
        return p
    else :
        root = find(tempParent)
        parent[p] = root
        countTable[p] = countTable[root]
        return root    


input = sys.stdin.readline
count = int(input())            
result = list();
for i in range(count) :
    parent = dict()
    countTable = dict()
    listCount = int(input())
    for j in range(listCount) :
        p1, p2 = input().strip().split()
        Union(p1,p2)
        data = countTable[p1]
        print(data)