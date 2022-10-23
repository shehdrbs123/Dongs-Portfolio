dls# Connect Scene

## 개요
- Connect Scene의 구현/설계 구조에 대한 문서입니다.

<br>
<br>

## Connect Scene(Lobby)
<br>

### <b>UI Panel Flow Chart</b>

![미리보기](../_Image/Connect%20Scene%20UIFlowChart.png) 

## 구현내용
- Scene 변경
  - Connect -> Main : CommonButtonScript switchScene 함수로 MainScene으로 씬변경
- Panel 변경
  - Connect Scene Button Script의 UIChangeTo 함수로 변경
- Connect Scene Button Script는 UI 최상단 오브젝트 컴포넌트로 등록
- 각 버튼 OnClick 이벤트에 Connect Scene Button script 내 함수 등록
- Panel변경시 한 개의 Panel만 뜨도록 설계

<br>
<br>

## Connect Scene Main


 ![미리보기](../_Image/Connect%20Scene%20Main.png)


## 구현내용 

 ![미리보기](../_Image/Connect%20Scene%20MainPanel%20%EC%84%A4%EA%B3%84%20%EB%82%B4%EC%9A%A9.png)


<br>
<br>

## Connect Scene Host Panel


 ![미리보기](../_Image/Connect%20Scene%20Host.png)
 
 
## 구현내용 

![미리보기](../_Image/Connect%20Scene%20Host%20Panel%20설계%20내용.png)

<br>
<br>

## Connect Scene Client Panel

 ![미리보기](../_Image/Connect%20Scene%20Client.png)

 ## 구현내용 

![미리보기](../_Image/Connect%20Scene%20Connect%20Panel%20설계%20내용.png)

## Connect Scene Waitroom Panel


 ![미리보기](../_Image/Connect%20Scene%20Waitroom.png)