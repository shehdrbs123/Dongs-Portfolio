# 네트워킹


<center>


## Network Workflow
![이미지](_Image/Network%20Workflow.png)

출처 :https://docs.unity3d.com/kr/2019.4/Manual/class-NetworkBehaviour.html

</center>

- 

## 바로가기
### Connect Scene
 - [Used NetworkComponents]()
 - [NetworkLobbyManager]()
 - [Player]()



## [이전 창으로 돌아가기](https://github.com/shehdrbs123/Dongs-Portfolio/tree/main/UnityProject/NetworkShooting/Description/UI%2C%20Scene)

<br>

## Used NetworkComponents

 |<H3><b>Network Components 구조도</b></H3>|
 |:---:|
 |![미리보기](_Image/Network%20소개%20이미지.png)|

 ## 주로 사용한 Componenets들
### NetworkIdentity
  - 네트워크 상에서 유니크한 존재로 표시해주는 컴포넌트
  - 네트워크 통신이 필요한 오브젝트는 무조건 필요


### NetworkBehaviour
  - Network Identity 컴포넌트 필수
  - 커스텀 컴포넌트를 생성할 때 사용
  - Commands, ClientRPCs, SyncEvents, SyncVars 의 기능을 통해 변수를 동기화


### NetworkLobbyManager
  - 대기방이 있는 멀티네트워크 구조에서 쓰이는 Unet의 컴포넌트 중 하나
  - Networking 연결, 연결 시 작동하는 추상 메서드 존재
  - NetworkLobbyPlayer, GamePlayer 두 객체를 사용 
    - 로비상황에서는 LobbyPlayer 
    - Game상황에서는 GamePlayer
    - OnLobbyServerSceneLoadedForPlayer() 에서 오브젝트 간 데이터를 공유
      - 모든 Player가 Ready가 되면 실행되는 이벤트 메서드


### NetworkLobbyPlayer
  - 유저 접속 시 NetworkLobbyManager의해 자동생성되는 네트워크 플레이어 단위
  - UI와의 연동을 위해 OnClientEnterLobby(), OnClientExitLobby(), OnClientReady(bool readyState)를 사용함

### NetworkClient
  - Client To Server 로의 네트워크 연결 관리 
  - Client<-> Server 간에 메시지를 송수신 가능

### NetworkServer
  - 서버의 작동상태를 확인을 통해 서버 내에서만 실행될 명령을 제한 가능
  - 클라이언트의 연결을 관리, 스폰, 게임의 전반적인 플레이 진행에 이용

### NetworkTransform
  - 네트워크 상 오브젝트 중 위치값을 공유하게 해주는 컴포넌트
  - Threshold, sendrate 등 네트워크 전송 부하에 관한 설정이 가능


## [위로가기](#네트워킹)


## NetworkComponents


## Player





