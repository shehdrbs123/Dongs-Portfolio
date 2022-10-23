# UI, Scene Design

## 개요
 - UI, Scene 구현에 관한 문서입니다.
<br>
<br>

## 바로가기
 - [Main Scene](#main-scene)
 - [Connect Scene](connect-scene(lobby))
 - [Ingame Scene](#main-scene)
<br>
<br>

---
<br>

## Main Scene
<br>

 ![미리보기](_Image/main%20Scene.png)

<br>

## 구현 내용

  ![미리보기](_Image/MainScene%20%EC%84%A4%EA%B3%84%20%EB%82%B4%EC%9A%A9.png)

  - CommonButtonScript를 최상위 UI 오브젝트에 추가
  - Unity GUI Button의 Hierachy 내 Button 컴포넌트의 OnClick 이벤트에 common button Script 함수 연결
  - Start Button 
    - CommonButtonScript 내 씬 이동 함수로 Connect Scene(다음씬)으로 이동
  - Exit Button
    - CommonButtonScript 내 종료함수로 게임 종료




---
<br>

## Connect Scene(Lobby)
<br>

### Panel Flow Chart

![미리보기](_Image/Connect%20Scene%20UIFlowChart.png) 

## 구현내용
- Scene 변경
  - Connect -> Main : CommonButtonScript switchScene 함수로 씬변경
- Panel 변경
  - Connect Scene Button Script의 UIChangeTo 함수로 변경
- Connect Scene Button Script는 UI 최상단 오브젝트 컴포넌트로 등록
- 각 버튼 OnClick 이벤트에 Connect Scene Button script 내 함수 등록
- Panel변경시 한 개의 Panel만 뜨도록 설계

<br>
<br>

## Connect Scene Main


 ![미리보기](_Image/Connect%20Scene%20Main.png)


## 구현내용 

 ![미리보기](_Image/Connect%20Scene%20MainPanel%20%EC%84%A4%EA%B3%84%20%EB%82%B4%EC%9A%A9.png)


<br>
<br>

## Connect Scene Host Panel


 ![미리보기](_Image/Connect%20Scene%20Host.png)
 
 
## 구현내용 

 ![미리보기](_Image/Connect%20Scene%20MainPanel%20%EC%84%A4%EA%B3%84%20%EB%82%B4%EC%9A%A9.png)


<br>
<br>

## Connect Scene Client Panel


 ![미리보기](_Image/Connect%20Scene%20Client.png)

## Connect Scene Waitroom Panel


 ![미리보기](_Image/Connect%20Scene%20Waitroom.png)

 
<br>
<br>

---

## Ingame Scene

## Ingame
 ![미리보기](_Image/Ingame%20Scene.png)

 ## Ingame - Pause Panel
 ![미리보기](_Image/Ingame%20-%20Pause.png)

