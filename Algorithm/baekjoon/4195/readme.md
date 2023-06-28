# 백준 4195번 친구 네트워크
- 출저 : https://www.acmicpc.net/problem/4195

<br>

## 핵심 
  - Union-Find 합집합 알고리즘을 이용
  - Dict를 통해 Union-Find의 루트를 관리
  - 또 다른 Dict를 이용, 현재 네트워크에서의 친구 수를 저장
  - Union시에 같은 집합에 있는지 체크 필수 -> 안그러면 중복됨.


## Union-Find
- Find 
  => 지속적으로 루트를 찾아가며, 자신과 루트가 같은 노드를 찾아 반환
  이때 route Comprehension이 가능
  - route Comprehension
    재귀적으로 찾아 들어가므로, 나올 때 반환되는 root를 자신의 root로 변경
    이를 통해 root로의 접근 시간을 O(n)에서 O(1)과 같이 변경가능
- Union 
  - 두 노드의 root를 찾고, root간의 특정 조건에 의해 한 루트를 자식으로 편입

<br>

- 풀이 결과 : https://www.acmicpc.net/status?from_mine=1&problem_id=4195&user_id=shehdrbs123