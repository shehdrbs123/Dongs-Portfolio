# 백준 11726 2xn 타일링
- 출저 : https://www.acmicpc.net/problem/11726
- 문제 내용
  - 2×n 크기의 직사각형을 1×2, 2×1 타일로 채우는 방법의 수를 구하는 프로그램을 작성하시오.

<br>

- 풀이 핵심 개념
  - 숫자 규칙 찾기
  - 0, 1, 2를 제외한 나머지의 개수들은 f(n-1) + f(n-2)를 결과값으로 갖는 규칙을 가지고 있다.

<br>

- 풀이 결과 : https://www.acmicpc.net/status?from_mine=1&problem_id=11726&user_id=shehdrbs123