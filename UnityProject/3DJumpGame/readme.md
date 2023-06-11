# Slippery Man 
<center>

 ![미리보기](../Jump.gif)

</center>
<!--
### [프로그램 다운로드(데모버전)]()
- 데모 버전 준비중
-->

## 개요 
- 플랫포머 점프 게임으로 맵의 다양한 장애물을 돌파하여 최종점에 오르면 되는게임
- 플랫폼 : windows, android(예정)
- 개발 기간 : 2021.9. ~ 2022.3.
<br><br>

## 플레이 스크린샷

<table>
<tr>
  <td width="20%">
    <Image src="PlayScreenShot/ArrowHitBack.jpg">
  </td>
  <td width="20%">
    <Image src="PlayScreenShot/AirUp.jpg">
  </td>
</tr>
<tr>
  <td>
    <Image src="PlayScreenShot/BindingPanelAndYAndNo.jpg">
  </td>
  <td>
    <Image src="PlayScreenShot/LadderMove.jpg">
  </td>
</tr>
</table>

## 개발 내용
- 주요 개발 내용
  - JsonUtility를 통한 저장/로드 시스템, WriteAsync를 이용하여 최적화
  - 그래픽, 사운드, 키 바인딩 UI 및 기능 구현
  - 재질별 Footstep 사운드 재생, Mixer활용 등 사운드 처리
  - 카메라 이동, 지형물 투명화 처리
  - 플레이어 움직임, 오브젝트 상호작용 등 설계
  - 특수 장애물 설계/구현 ( 화살, 진자운동 발판, 밀어내기 발판)
  - Timeline 시스템을 활용한 엔딩 시네마틱 영상 제작
  - SteamAPI(Facepunch 라이브러리) 연동
- 기타 
  - 인게임 시네마틱 영상 제작
  - 플레이어 애니메이션

## 성과
- Unity GUI, 게임오브젝트, 애니메이터 설계 등 유니티 역량 향상
- 파일 저장을 위한 JsonUtility 사용 경험
- 프레임 최적화를 위한 비동기 프로그래밍 사용 경험
- Steamworks 라이브러리 사용경험 (Facepunch.Steamworks)
- Cinemachine 사용 경험

## 구현 설명
- [저장 시스템](./SaveSystemDetailFortfolio/)

<!-- ## 데모버전 플레이
- [링크]() -->
