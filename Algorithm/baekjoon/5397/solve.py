# 키로거 https://www.acmicpc.net/problem/5397

from collections import deque

import sys
input = sys.stdin.readline

for i in range(int(input())) :
    data = input()
    left = deque()
    right = deque()
    
    for a in data :
        if a == '<' :
            if left :
                right.appendleft(left.pop())
        elif a == '>' :
            if right :
                left.append(right.popleft())
        elif a == '-':
            if left :
                left.pop()
        elif a != '\n' :
            left.append(a)
    print(''.join(left) + ''.join(right))