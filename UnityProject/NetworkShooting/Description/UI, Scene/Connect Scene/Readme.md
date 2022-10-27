## Connect Scene(Lobby)
<br>

| <H3><b>UI Panel Flow Chart</b></H3>|
|:---:|
|![미리보기](../_Image/Connect%20Scene%20UIFlowChart.png)|
- 다음은 Scene 내 Panel의 Flow 차트를 설명한 이미지 입니다.
- Connect Scene Button Script/ CommonButton Script는 UI 최상단 오브젝트 컴포넌트로 등록
- Connect Scene Button Script ([코드보기](https://github.com/shehdrbs123/Dongs-Portfolio/blob/main/UnityProject/NetworkShooting/Description/UI%2C%20Scene/Connect%20Scene/_Scripts/ConnectSceneButtonScript.cs))
  - Scene Panel의 관리, 변경 (한번에 한 개의 패널만 존재)
  - 입력 필드를 읽어 서버 생성 혹은 네트워크 연결
- Common Button Script ([코드보기](https://github.com/shehdrbs123/Dongs-Portfolio/blob/main/UnityProject/NetworkShooting/Description/UI%2C%20Scene/Connect%20Scene/_Scripts/CommonButtonScript.cs))
  - Scene 변경
  - 프로그램 종료
  
<br>

## 바로가기
 - [Main Panel](#connect-scene-main)
 - [Host Panel](#connect-scene-host-panel)
 - [Client Panel](#connect-scene-client-panel)
 - [Waitroom Panel](#connect-scene-waitroom-panel)

## [관련 전체 코드 보기](https://github.com/shehdrbs123/Dongs-Portfolio/tree/main/UnityProject/NetworkShooting/Description/UI%2C%20Scene/Connect%20Scene/_Scripts)

## [이전 창으로 돌아가기](https://github.com/shehdrbs123/Dongs-Portfolio/tree/main/UnityProject/NetworkShooting/Description/UI%2C%20Scene)

<br>

## Connect Scene Main

 |<H3><b>실제화면</b></H3>| <H3><b>Button 구현 도식도</b></H3>|
 |:---:|:---:|
 |![미리보기](../_Image/Connect%20Scene%20Main.png)|![미리보기](../_Image/Connect%20Scene%20MainPanel%20%EC%84%A4%EA%B3%84%20%EB%82%B4%EC%9A%A9.png)|

## 구현내용 
- Panel 변경
  - ConnectSceneButtonScript.UIChangeTo() 함수로 변경
  - 각 버튼 OnClick 이벤트에 Connect Scene Button script 내 함수 등록
  - Panel변경시 한 개의 Panel만 뜨도록 설계
  - HostButton
    - ConnectSceneButtonScript.OnClickToHostPanel() 연결됨
    - UIChangeTo 함수로 Host Panel로 변경
  - ConnectButton
    - ConnectSceneButtonScript OnClickToConnectionPanel() 연결됨
    - UIChangeTo 함수로 Client Panel로 변경
  - [ConnectSceneButtonScript 코드 보기](https://github.com/shehdrbs123/Dongs-Portfolio/blob/main/UnityProject/NetworkShooting/Description/UI%2C%20Scene/Connect%20Scene/_Scripts/ConnectSceneButtonScript.cs)
- Scene 변경
  - ExitButton : Main Scene으로 변경 요청
  - CommonButtonScript switchScene 함수로 MainScene으로 씬변경
    - SceneManagement.SceneManager.LoadScene(string)을 이용
  - [CommonButtonScript 코드 보기](https://github.com/shehdrbs123/Dongs-Portfolio/blob/main/UnityProject/NetworkShooting/Description/UI%2C%20Scene/Connect%20Scene/_Scripts/CommonButtonScript.cs)

## [위로가기](#connect-scenelobby)

<br>

## Connect Scene Host Panel

 |<H3><b>실제화면</b></H3>| <H3><b>Button 구현 도식도</b></H3>|
 |:---:|:---:|
 |![미리보기](../_Image/Connect%20Scene%20Host.png)|![미리보기](../_Image/Connect%20Scene%20Host%20Panel%20설계%20내용.png)|

 ## 구현 내용 
 - CreateButton
   - ConnectSceneButtonScript.OnClickCreateHost() 연결됨
   - NetworkLobbyManager로 InputField의 Port 입력값을 전달
   - NetworkLobbyManager.StartHost()로 호스트 서버 생성
   - 호스트 서버 생성 확인 후 waitroom Panel 변경
 - ExitButton
   - ConnectSceneButtonScript.OnClickExitToMain() 연결됨
   - UIChangeTo 함수로 MainPanel로 변경
 - [ConnectSceneButtonScript 코드 보기](https://github.com/shehdrbs123/Dongs-Portfolio/blob/main/UnityProject/NetworkShooting/Description/UI%2C%20Scene/Connect%20Scene/_Scripts/ConnectSceneButtonScript.cs)


## [위로가기](#connect-scenelobby)

<br>

## Connect Scene Client Panel

|<H3><b>실제화면</b></H3>| <H3><b>Button 구현 도식도</b></H3>|
 |:---:|:---:|
 | ![미리보기](../_Image/Connect%20Scene%20Client.png)|![미리보기](../_Image/Connect%20Scene%20Connect%20Panel%20설계%20내용.png)|

 ## 구현내용  
 - ConnectButton
   - ConnectSceneButtonScript.OnClickCreateInHost() 연결됨
   - NetworkLobbyManager로 InputField의 IP, Port 입력값을 전달
   - StartClient()로 호스트 서버 생성
   - 호스트 서버 생성 확인 후 waitroom Panel 변경
 - ExitButton
   - ConnectSceneButtonScript.OnClickExitToMain()연결됨
   - UIChangeTo 함수로 MainPanel로 변경
 - [ConnectSceneButtonScript 코드 보기](https://github.com/shehdrbs123/Dongs-Portfolio/blob/main/UnityProject/NetworkShooting/Description/UI%2C%20Scene/Connect%20Scene/_Scripts/ConnectSceneButtonScript.cs)

## [위로가기](#connect-scenelobby)

<br>

## Connect Scene Waitroom Panel

|<H3><b>실제화면</b></H3>|<H3><b>Button 구현 도식도</b></H3>|
|:---:|:---:|
|![미리보기](../_Image/waitroom%20client%20%EC%A0%91%EC%86%8D%2C%20%EB%8F%99%EA%B8%B0%ED%99%94.png)|![미리보기](../_Image/Waitroom%20Button%20%EA%B0%84%EB%8B%A8%20%EB%82%B4%EC%9A%A9.png)|

## 구현 내용
- ReadyButton OnClick 이벤트는 NetworkLobbyPlayer 생성 시 등록
  - 로컬플레이어의 Ready상태를 변경해야하므로 동적 연결
  - LobbyPlayer.OnReadyClicked()를 연결
  - LobbyPlayer.SendReadyToBeginMessage(), SendNotReadyToBeginMeesage()로 Ready 상태 서버에 전달
  - 서버는 Ready한 클라이언트 수를 확인해 자동으로 InGameScene 자동 전환
- ExitButton
  - ConnectSceneButtonScript.OnClickExitToMain() 연결됨
  - 서버 연결 종료 delegate callback함수 실행
    - 서버가 연결될 당시 ConnectSceneButtonScript에서 종료 함수를 delegate에 연결함
    - NetworkLobbyManager.StopHost(), StopClient() 중 하나 연결
  - UIChangeTo 함수로 MainPanel로 변경
<br>

## 세부 구현 내용

|<H3><b>네트워크 접속 요청 후 처리과정</b></H3>|
|:---:|
|![이미지](../_Image/Waitroom%20%EC%A0%91%EC%86%8D%20%ED%9B%84%20%EC%84%A4%EC%A0%95%EA%B3%BC%EC%A0%95.png)|
- Waitroom Panel Setting 과정
  -  NetworkLobbyManager가 네트워크에 연결되면, 자동적으로 LobbyPlayer를 생성
  -  LobbyPlayer의 OnClientEnterLobby()이벤트 발생
  -  LobbyPlayer는 LobbyPlayerList에 등록요청 및 Text 컴포넌트를 받아옴
     -  LobbyPlayerList
        -  LobbyPlayer의 UI를 총괄하는 스크립트
        -  UI내 Player 정보가 적히는 오브젝트의 부모에 추가
        -  각 LobbyPlayer의 UI상 위치를 지정해줌
  -  NetworkLobbyManager에 등록된 자신의 이름 확인
  -  받아온 Text Component에 자신의 이름과 현재 Ready상태를 입력
  -  서버에 접속된 순서대로 LobbyPlayer가 생성/반복됨


|<H3><b>Ready 후 Text(Ready) 변경 과정</b></H3>|
|:---:|
|![이미지](../_Image/Waitroom%20Ready%20후%20Text%20변경과정.png)|
-  Button 추가 설명
   - ReadyButton
     - LobbyPlayer내에 LocalPlayer임을 알려주는 플래그 존재, 해당 여부로 버튼 이벤트 등록을 결정
     - 이후 ReadyButton을 누르면 연결된 LobbyPlayer.OnReadyClicked()가 실행 
       - SendReadyToBeginMessage() or SendNotReadyToBeginMessage()으로 서버에 Ready값 전달
       - OnClientReady() 이벤트가 발생, 네트워크 내 값을 일치화 시킴


## [위로가기](#connect-scenelobby)

## [이전 창으로 돌아가기](https://github.com/shehdrbs123/Dongs-Portfolio/tree/main/UnityProject/NetworkShooting/Description/UI%2C%20Scene)