## Ingame Scene(Lobby)
<br>

 |<H3><b>Button Class 구조</b></H3>|
 |:---:|
 |![미리보기](../_Image/Ingame%20Scene%20UI%20%EC%83%81%EC%86%8D%EA%B5%AC%EC%A1%B0.png)|
- 상속 구조에 대한 설명
  - ParentButton
    - GamePlayer를 이용하는 버튼들을 추상화
    - 버튼의 다른 기능 없이 클릭 기능만을 쓰기위해 IPointerUp, Down Handler를 구현
    - GamePlayer가 생성 될 때 button에 자신의 오브젝트값을 전달
  - 구현 클래스의 버튼기능은 OnPointerDown, OnPointerUp 에구현되어있음

## 바로가기
 - [MoveButton](#movebutton)
 - [Gauge](#gauge)
 - [UserUI Button](#userui-button)
 - [Pause Panel](#pause-panel)

## [관련 전체 코드 보기](https://github.com/shehdrbs123/Dongs-Portfolio/tree/main/UnityProject/NetworkShooting/Description/UI%2C%20Scene/InGameScene/_Scripts)

## [이전 창으로 돌아가기](https://github.com/shehdrbs123/Dongs-Portfolio/tree/main/UnityProject/NetworkShooting/Description/UI%2C%20Scene)

<br>

## MoveButton

 |<H3><b>실제화면</b></H3>| <H3><b>Button 구현 도식도</b></H3>|
 |:---:|:---:|
 |![미리보기](../_Image/Ingame%20Scene%20Move%20Button.png)|![미리보기](../_Image/Ingame%20Move%20Button.png)|

## 구현내용 
- MoveButton
  - 보이지 않는 양쪽의 버튼이 존재
  - 왼쪽버튼을 누르면 왼쪽으로 이동, 오른쪽 버튼을 누르면 오른쪽 이동
  - ParentButton 상속으로 GamePlayer 참조, 이동방향값을 전달
  - 로컬플레이어의 GamePlayer가 버튼에 연결되어 MoveButton으로 좌우 이동 값 전달
  


## [위로가기](#ingame-scenelobby)

<br>

## Gauge

 |<H3><b>실제화면</b></H3>| <H3><b>UI 도식도</b></H3>|
 |:---:|:---:|
 |![미리보기](../_Image/Ingame%20Scene%20Gauge.png)|![미리보기](../_Image/Ingame%20Gauge.png)|


## 구현내용
- HP Gauge
  - Local gamePlayer와 연동, HP Data에 따라 자동으로 데이터가 반영됨
  - 두 개의 이미지를 두고 한 개의 이미지 RectTransform.sizeDelta 값을 줄이는 방식으로 동작 
- Boss Warning Gauge
  - 네트워크 상 모든 EnemyObject가 파괴 될 때 수치가 상승 (<span style="color:#dd6666">빨간색</span>Bar로 표시됨)
  - TableSetter에서 Crisis Gauge 값과 UI를 관리, 해당 값을 UI에 반영
  - HP Gauge와 마찬가지로 RectTransform.sizeDelta 값을 줄이는 방식으로 UI동작
  
## [위로가기](#ingame-scenelobby)

<br>

## UserUI Button

 |<H3><b>실제화면</b></H3>| <H3><b>Button 구현 도식도</b></H3>|
 |:---:|:---:|
 |![미리보기](../_Image/Ingame%20Scene%20Indicate%20Button.png)|![미리보기](../_Image/Ingame%20Scene%20UserUI%20Button%20%EA%B5%AC%EC%A1%B0%EB%8F%84.png)|


## 구현내용
- UserUI Button
  - 게임씬 진입 당시 GamePlayer 오브젝트 중 다른 유저의 정보가 등록되는 UI, 이름과 HP를 표시
  - 마찬가지로 RectTransform.sizeDelta 값을 줄이는 방식으로 UI 동작
  - 해당 정보는 네트워크를 통해서 실시간 동기화 됨.

## [위로가기](#ingame-scenelobby)

<br>

## Pause Panel

 |<H3><b>실제화면</b></H3>| <H3><b>Button 구현 도식도</b></H3>|
 |:---:|:---:|
 |![미리보기](../_Image/Ingame%20-%20Pause.png)|![이미지](../_Image/Ingame%20Scene%20Pause%20Button.png)|

## 구현내용
- Pause Button
  - Button 컴포넌트의  OnClick 이벤트에 IngameButtonScript.OnPressPause() 등록
  - 오브젝트 active 상태를 true로 바꾸어 Panel을 On 한다
- Continue Button
  - Button 컴포넌트의  OnClick 이벤트에 IngameButtonScript.OnPressContinue() 등록
  - 오브젝트 active 상태를 false로 바꾸어 Panel을 off 한다.
- Exit Button
  - Button 컴포넌트의  OnClick 이벤트에 IngameButtonScript.OnPressExitButton() 등록
  - NetworkLobbyManager에 종료요청을 한다
  - 종료요청을 받으면 자동으로 LobbyScene(Connect Scene), main panel 화면으로 전환된다.  
## [위로가기](#ingame-scenelobby)

<br>

## [이전 창으로 돌아가기](https://github.com/shehdrbs123/Dongs-Portfolio/tree/main/UnityProject/NetworkShooting/Description/UI%2C%20Scene)