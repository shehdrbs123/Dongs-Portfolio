# 네트워킹


<center>


## Network Workflow
![이미지](_Image/Network%20Workflow.png)

출처 :https://docs.unity3d.com/kr/2019.4/Manual/class-NetworkBehaviour.html

</center>

- 위는 기본적인 Unity Network의 기본 network workflow 입니다
- 클라이언트 개발자가 Low-level의 네트워킹 시스템을 직접 구현하지 않고 네트워킹 게임 개발이 가능한 라이브러리 입니다.
- 복잡한 기능을 원할경우 NetworkTranport API를 재구현하는 방법으로 외부의 네트워킹과도 연동이 됩니다.

<br>

## 바로가기

 - [주로 사용한 Components 간단설명](#주로-사용한-componenets-간단설명)
 - [NetworkLobbyManager](#networklobbymanager-1)
 - [LobbyPlayer, GamePlayer](#lobbyplayer-gameplayer)
 - [TableSetter](#tablesetter)


<br>

## [이전 창으로 돌아가기](https://github.com/shehdrbs123/Dongs-Portfolio/tree/main/UnityProject/NetworkShooting)

<br>

## NetworkComponents

<center>

 |<H3><b>Network Components 구조도</b></H3>|
 |:---:|
 |![미리보기](_Image/Network%20소개%20이미지.png)|

</center>

## 주로 사용한 Componenets 간단설명

### NetworkLobbyManager
  - 대기방이 있는 멀티네트워크 구조에서 쓰이는 Unet의 컴포넌트 중 하나
  - Networking 연결, 연결 시 작동하는 이벤트 가상 함수로 게임 Network 동기화 수행
  - NetworkLobbyPlayer, GamePlayer 두 객체를 Player 객체로 사용 
    - 로비상황에서는 LobbyPlayer 
    - Game상황에서는 GamePlayer
    - OnLobbyServerSceneLoadedForPlayer() 에서 오브젝트 간 데이터를 공유

### NetworkBehaviour
  - Network Identity 컴포넌트 필수
  - 커스텀 컴포넌트를 생성할 때 사용
  - Commands, ClientRPCs, SyncEvents, SyncVars 의 기능 사용을 통해 변수를 동기화

### NetworkIdentity
  - 네트워크 상에서 유니크한 존재로 표시해주는 컴포넌트
  - 네트워크 통신이 필요한 오브젝트는 무조건 필요

### NetworkLobbyPlayer
  - 유저 접속 시 NetworkLobbyManager의해 자동생성되는 네트워크 플레이어 단위
  - OnClientEnterLobby(), OnClientExitLobby(), OnClientReady(bool readyState)의 가상함수를 
   <br>재구현 하여 사용

### NetworkClient
  - Client To Server 로의 네트워크 연결 관리, 확인
  - Client<-> Server 간에 메시지를 송수신 가능

### NetworkServer
  - 주로 NetworkServer임을 확인하거나 네트워크 내 오브젝트를 Spawn할 때 사용
  - 서버의 작동상태를 확인을 통해 서버 내에서만 실행될 명령을 제한 가능
  - 클라이언트의 연결을 관리, 스폰, 게임의 전반적인 플레이 진행에 이용

### NetworkTransform
  - 네트워크 상 오브젝트 위치값을 공유하게 해주는 컴포넌트
  - Threshold, sendrate 등 네트워크 전송 부하에 관한 설정이 가능


## [위로가기](#네트워킹)

<br>

## NetworkLobbyManager
|<H3><b>추가 기능에 대한 모식도</b></H3>|
 |:---:|
 |![미리보기](_Image/NetworkLobbyManager%20%EC%B6%94%EA%B0%80%ED%95%9C%20%EA%B8%B0%EB%8A%A5.png)|

## 구현 내용
- 네트워크 연결이나 연결 시의 가상함수를 구현하여 네트워크와 관련된 기능을 사용하는 컴포넌트
- NetworkLobbyManager는 NetworkManager의 기능을 확장한 오브젝트로 Lobby의 기능도 포함
  - NetworkManager에서의 StartHost(), StartClient() 와 같은 네트워크 연결 함수 지원.
  - 접속과 관련한 이벤트 가상함수
    - OnLobbyServerSceneChanged
      - Scene이 변경되었을 때 발생하는 이벤트
      - 본 게임에서는 Connect Scene에서의 Panel 선택에 사용
        - 서버가 켜져있을 경우 waitroom panel 선택, 아닐경우 ConnectScene Main
    - OnLobbyServerSceneChangedForPlayer(LobbyPlayer, GamePlayer)
      - 컴포넌트에 등록된 LobbyScene-> GameScene 이동이 확인 될 경우 발생하는 이벤트
      - LobbyPlayer-> GamePlayer의 데이터 이동에 사용
      - 이름과 슬롯 위치를 공유

- 싱글턴 패턴으로 사용 필요한 위치에서 기능 or 데이터(읽기전용) 사용
  - ConnectScene에서 NetworkLobbyManager에 UI(Panel) 연결
  - 버튼 입력 시 접속요청
  - 이름 공유
  - 접속 종료 요청
  - 네트워크 연결 여부 확인

## [위로가기](#네트워킹)

<br>

## LobbyPlayer, GamePlayer

|<H3><b>LobbyPlayer 설계 구조</b></H3>|
|:---:|
|![미리보기](_Image/NetworkLobbyPlayer%20%EA%B5%AC%ED%98%84%20%EB%8F%84%EC%8B%9D%EB%8F%84.png)|

|<H3><b>GamePlayer 설계 구조</b></H3>|
|:---:|
|![미리보기](_Image/Network%20GamePlayer%20%EA%B5%AC%ED%98%84%20%EB%8F%84%EC%8B%9D.png)|


## 구현 내용
- NetworkLobbyPlayer
  - 플레이어가 접속했을 때 로비에서 플레이어 정보를 가지고 있는 오브젝트
  - NetworkLobbyManager와 짝꿍이 되어 사용
  - 외부의 접속이 확인되면(호스트 포함) NetworkLobbyManager에서 LobbyPlayer를 생성
  - LobbyPlayer는 생성과 동시에 OnClientEnterLobby() 이벤트 실행
  - LobbyPlayerList에 등록, List로 부터 PlayerInfo slot을 지정받음
  - 추가로 지정된 위치의 Text component의 text를 변경, 이름, Ready 상태 등록
  - [SyncVar] 속성으로 어느 클라이언트 든 데이터변경 발생 시 서버에서 동기화 요청을 수행


- GamePlayer
  - NetworkLobbyManager가 Ingame에 진입 시 자동으로 생성하는 Playable Object
  - 유저가 직접 플레이할 Prefab을 등록
  - LocalUser의 경우 Camera, MoveButton, HP Gauge의 컴포넌트 정보를 찾아 보유
  - OtherUser의 경우 UserUI의 정보를 찾아 보유
    - GamePlayer의 데이터가 변동하게되면 각 UI에 변동정보를 반영
    - [SyncVar] 속성으로 데이터 동기화 같이 수행

## [위로가기](#네트워킹)

<br>

## TableSetter

|<H3><b>TableSetter 설계 구조</b></H3>|
|:---:|
|![미리보기](_Image/Network%20TableSetter.png)|


## 구현 내용
- 이름 그대로 IngameScene에서 게임환경을 구성해주는 오브젝트
- TableSetter는 IngameScene 진입 시 네트워크 유저 수에 따라 아래 이미지에 맞추어 Spanwer와 Boundary를 Spawn함
- Spawn 과정
  - 먼저 서버에서 오브젝트를 Instantiate 시킨다.
  - NetworkServer.Spawn(Instantiate 시킨 인스턴스)로 네트워크에 공유한다.
- 네트워킹 트릭<br>
![이미지](_Image/Network%20field%20설정%20트릭.png)
  - 게임플레이는 실제 모든 네트워킹 공간에서 자신이 지정된 위치에서만 활동 가능
  - 본래 기획에서는 다양한 스킬 등을 활용해 위치를 넘나드는 구조였으나 싶었으나 기간의 부족으로 구현 x
  - GamePlayer는 전달받은 슬롯 위치를 이용해 카메라와 위치를 지정하여 사용하게됨
- 고정위치로 지정되어 슬롯넘버 * slot * 15로 default 위치가 지정됨.


## [위로가기](#네트워킹)

## [이전 창으로 돌아가기](https://github.com/shehdrbs123/Dongs-Portfolio/tree/main/UnityProject/NetworkShooting)