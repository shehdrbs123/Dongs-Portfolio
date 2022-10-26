# Player
<center>

|<H3><b>GamePlayer 클래스 구조</b></H3>|
|:---:|
 |![미리보기](../_Image/../Player/_Image/GamePlayer%20클래스%20구조.png)|

</center>


## 구현내용
- GamePlayer는 IngameScene에 들어왔을 때 NetworkLobbyManager에 의해 자동 생성
- 역할 
 1. IngameScene 진입 시 UI, 카메라 설정 등 게임환경 세팅
 2. MoveButton의 이동값을 받아 이동 구현
 3. 상속 구조 MoveObject 이용, 특정 시간마다 Bullet 발사



