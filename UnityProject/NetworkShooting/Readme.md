# 4인 네트워크 슈팅 게임
<center>

 ![미리보기](../NetworkShooting.gif)
   <br>
    PC 2대, 안드로이드 1대의 네트워킹 게임모습을 편집한 장면입니다.
    <br>
    혼자 플레이영상을 찍어 한대만 플레이 되었습니다.
</center>

### [프로그램 다운로드](http://naver.me/xkqmTGfV)

<br>


## 개요 
- 안드로이드 4인 비행슈팅 게임
  - 멀티플랫폼 가능(PC <-> Android)
- UNet(Unity Network) 기반 네트워크
- 개발 기간 : 2019.9 ~ 12 (3개월)

<!--
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
-->

## 개발 내용
- Unity GUI를 이용,Lobby, Game UI 설계 
- 유니티 네트워크 (UNet)를 이용한 Host형 네트워크 구현
- 플레이어 오브젝트, 공격 오브젝트 구현
- 적 오브젝트 설계 및 구현
  - 적기 2기 (각각 1개 패턴)
  - 보스 1기 ( 4개의 패턴 )
- 세부내용은 [링크](./Description/)를 눌러주세요

## 성과
- 시스템 구조에 다양한 디자인 패턴을 적용 / 구현
- 유니티 API 사용능력 자기화
- 데이터 동기화, 서버/클라이언트 구조 확인 등 네트워크 게임 설계/구현 기반지식 획득
- IP, Port를 통한 접근으로 네트워크 스위치(포트포워드) 지식 습득
- 졸업프로젝트 통과
