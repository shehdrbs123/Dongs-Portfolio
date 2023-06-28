# 백준 5397번 키로거
- 출저 : https://www.acmicpc.net/problem/5397

<br>
- 핵심 
  - deque를 이용, left, right로 분할하여 cursor를 가운데 있도록 위치
  - 두 deque를 이용해 구현하면 됨
- 이유
  - 단순 list만으로는 시간적 조건을 충족 불가
  - list의 insert, remove의 시간소요를 감당 불가
<br>

- 풀이 결과 : https://www.acmicpc.net/status?from_mine=1&problem_id=5397&user_id=shehdrbs123