import sys;

input = sys.stdin.readline

input()
compare = set(map(int,input().split(' ')))   
input()
data = map(int,input().split(' '))

for m in data :
    if m in compare :
        print(1)
    else :
        print(0)
        
