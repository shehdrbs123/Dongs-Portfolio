## Connect Scene(Lobby)
<br>

| <H3><b>UI Panel Flow Chart</b></H3>|
|:---:|
|![미리보기](../_Image/Connect%20Scene%20UIFlowChart.png)|
- 다음은 씬 내 패널의 Flow 차트를 설명한 이미지 입니다.
- Connect Scene Button Script/ CommonButton Script는 UI 최상단 오브젝트 컴포넌트로 등록
- Connect Scene Button Script 
  - 씬 패널 관리, 변경 (한번에 한 개의 패널만 존재)
  - 입력 필드를 읽어 서버 생성 혹은 네트워크 연결
- Common Button Script
  - Scene 변경
  - 프로그램 종료
  
<br>

## 바로가기
### Connect Scene
 - [Main Panel](#connect-scene-main)
 - [Host Panel](#connect-scene-host-panel)
 - [Client Panel](#connect-scene-client-panel)
 - [Waitroom Panel](#connect-scene-waitroom-panel)

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
    - ConnectSceneButtonScript.OnClickHostInHCSelect() 연결됨
    - UIChangeTo 함수로 Host Panel로 변경
  - ConnectButton
    - ConnectSceneButtonScript.OnClickHostInHCSelect() 연결됨
    - UIChangeTo 함수로 Client Panel로 변경
- Scene 변경
  - ExitButton : Main Scene으로 변경 요청
  - CommonButtonScript switchScene 함수로 MainScene으로 씬변경
    - SceneManagement.SceneManager.LoadScene(string)을 이용


## [돌아가기](#connect-scenelobby)

<br>

## Connect Scene Host Panel

 |<H3><b>실제화면</b></H3>| <H3><b>Button 구현 도식도</b></H3>|
 |:---:|:---:|
 |![미리보기](../_Image/Connect%20Scene%20Host.png)|![미리보기](../_Image/Connect%20Scene%20Host%20Panel%20설계%20내용.png)|

 ## 구현 내용 
 - CreateButton
   - ConnectSceneButtonScript.OnClickCreateInHost() 연결됨
   - NetworkLobbyManager로 InputField의 Port 입력값을 전달
   - StartHost()로 호스트 서버 생성
   - 호스트 서버 생성 확인 후 waitroom Panel 변경
 - ExitButton
   - ConnectSceneButtonScript.OnClickCreateInHost() 연결됨
   - UIChangeTo 함수로 MainPanel로 변경


## [돌아가기](#connect-scenelobby)

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
   - ConnectSceneButtonScript.OnClickCreateInHost() 연결됨
   - UIChangeTo 함수로 MainPanel로 변경

## [돌아가기](#connect-scenelobby)

<br>

## Connect Scene Waitroom Panel



<table>
  <tr align=center>
    <td><H3><b>실제화면</b></H3></</td>
    <td><H3><b>네트워크의 접속, Waitroom Panel 전환 요청 이후 setting 과정</b></H3></td>
  </tr>
  <tr align=center >
    <td><img src=" ../_Image/Connect%20Scene%20Waitroom.png"></td>
    <td colspan=><img src=" ../_Image/Waitroom%20%EC%A0%91%EC%86%8D%20%ED%9B%84%20%EC%84%A4%EC%A0%95%EA%B3%BC%EC%A0%95.png"></td>
  </tr>
  <tr align=center>
    <td colspan="2"><H3><b>Ready 후 Text(Ready) 변경 과정</b></H3></td>
  </tr>
  <tr align=center>
    <td colspan="2"><img src="../_Image/Waitroom%20Ready%20후%20Text%20변경과정.png"></td>
  </tr>
  <tr align=center>
    <td colspan="2"><H3><b>Button 구현 도식도</b></H3></td>
  </tr>
  <tr align=center>
    <td colspan="2"><img src="../_Image/Waitroom%20Button%20설계%20내용.png"></td>
  </tr>

</table>

## 구현 내용
- Waitroom Panel Setting 과정
  -  NetworkLobbyManager가 네트워크에 연결되면, 자동적으로 LobbyPlayer를 생성
  -  LobbyPlayer의 OnClientEnterLobby()이벤트 발생

## [돌아가기](#connect-scenelobby)