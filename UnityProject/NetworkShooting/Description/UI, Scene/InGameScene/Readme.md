## Ingame Scene(Lobby)
<br>

 |<H3><b>Button Class 구조</b></H3>|
 |:---:|
 |![미리보기](../_Image/Ingame%20Scene%20UI%20%EC%83%81%EC%86%8D%EA%B5%AC%EC%A1%B0.png)|
- 상속 구조에 대한 설명
  - ParentButton
    - GamePlayer로 부터 데이터를 받는 버튼을 추상화
    - 버튼의 다른 기능 없이 클릭 기능만을 쓰기위해 IPointerUp, Down Handler를 구현
    - GamePlayer가 생성 될 때 button에 자신의 오브젝트값을 전달
  - 구현 클래스의 버튼기능은 구현되어있음

## 바로가기
### Ingame Scene
 - [MoveButton](#movebutton)
 - [Gauge](#gauge)
 - [UserUI Button](#userui-button)
 - [Pause Panel](#pause-panel)

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
  


## [위로가기](#ingame-scenelobby)

<br>

## Gauge

 |<H3><b>실제화면</b></H3>| <H3><b>UI 도식도</b></H3>|
 |:---:|:---:|
 |![미리보기](../_Image/Ingame%20Scene%20Gauge.png)|![미리보기](../_Image/Ingame%20Gauge.png)|


## 구현내용
- HP Gauge
- Boss Warning Gauge
  
## [위로가기](#ingame-scenelobby)

<br>

## UserUI Button

 |<H3><b>실제화면</b></H3>| <H3><b>Button 구현 도식도</b></H3>|
 |:---:|:---:|
 |![미리보기](../_Image/Ingame%20Scene%20Indicate%20Button.png)|![미리보기](../_Image/Ingame%20Scene%20UserUI%20Button%20%EA%B5%AC%EC%A1%B0%EB%8F%84.png)|


## 구현내용
- UserUI Button
  - name, HP 공유

## [위로가기](#ingame-scenelobby)

<br>

## Pause Panel

 |<H3><b>실제화면</b></H3>| <H3><b>Button 구현 도식도</b></H3>|
 |:---:|:---:|
 |![미리보기](../_Image/Ingame%20-%20Pause.png)|![이미지](../_Image/Ingame%20Scene%20Pause%20Button.png)|

## 구현내용
- Continue Button
- Exit Button
## [위로가기](#ingame-scenelobby)

<br>

## [이전 창으로 돌아가기](https://github.com/shehdrbs123/Dongs-Portfolio/tree/main/UnityProject/NetworkShooting/Description/UI%2C%20Scene)