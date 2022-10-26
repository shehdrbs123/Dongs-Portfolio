# Player

|<H3><b>GamePlayer 클래스 구조</b></H3>|
|:---:|
 |![미리보기](../_Image/../Player/_Image/GamePlayer%20클래스%20구조.png)|


## 바로가기 
- [MoveObject](#moveobject)
- [GamePlayer](#gameplayer)

## MoveObject
## 구현내용
- 이동, 총알발사, 스폰에 관한 함수와 변수를 들고 있는 부모클래스
- GamePlayer, EnemyObject의 기본이 되는 클래스
- 이동은 기본적으로 Rigidbody2D에 외부에서 지정한 값으로 마찰력없이 이동
- CmdFire() 함수로 기본적인 발사를 지원(네트워크 spawn 기능 포함)
- [Command] 속성을 통해서 서버에서만 실행되는 함수이다.

## [위로가기](#player)



<br>

## GamePlayer

## 구현내용
- IngameScene에 들어왔을 때 NetworkLobbyManager에 의해 자동 생성
- 역할 
   1. IngameScene 진입 시 UI, 카메라 설정 등 게임환경 세팅
   2. MoveButton의 이동값을 받아 이동 구현
   3. 상속 구조 MoveObject 이용, 특정 시간마다 Bullet 발사

- IngameScene 진입 시 UI, 카메라 설정 등 게임환경 세팅

- Update()
  - MoveButton으로 받은 방향 값을 기준으로 Transform.traslate()을 하여 기체 이동
  - 딜레이타임 <= 기다린 시간 이라면, MoveObject.CmdFire()를 통해 총알을 발사함

## [위로가기](#player)
<br>


## [코드 보기](https://github.com/shehdrbs123/Dongs-Portfolio/tree/2de9f9fe8667c63bb6b2c0fd216942032eaaaf80/UnityProject/NetworkShooting/Description/Player/_Scripts)

## [이전 창으로 돌아가기](https://github.com/shehdrbs123/Dongs-Portfolio/tree/main/UnityProject/NetworkShooting)