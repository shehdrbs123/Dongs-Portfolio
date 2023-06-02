# Dong's Fortfolio

## 목차
- [3D Jump Game](#3d-jump-game)
- [네트워크 4인 슈팅 게임](#네트워크-4인-슈팅-게임-in-android-and-pc)
- [Doodle Jump 모작](#doodle-점프-모작)
  
---


## [3D Jump Game](https://github.com/shehdrbs123/Dongs-Portfolio/tree/main/UnityProject/Slippery%20Man)

[![미리보기](UnityProject/Jump.gif)](https://github.com/shehdrbs123/Dongs-Portfolio/tree/main/UnityProject/Slippery%20Man)
### 개요 
- 플랫포머 점프 게임으로 맵의 다양한 장애물을 돌파하여 최종점에 오르면 되는게임
- 플랫폼 : Windows
- 개발 인원 : 2명
- 개발 기간 : 2021.9. ~ 2022.3.
<br><br>

### 개발 내용
- 주요 개발 내용
  - 플레이어 움직임, 오브젝트 상호작용
  - JsonUtility를 통한 저장/로드 시스템, Unity Job System을 이용하여 최적화
  - UGUI를 이용한 UI 구현
    - 그래픽, 사운드, KeyBinding 구현
  - 재질별 Footstep 사운드 재생, Mixer활용 등 사운드 처리
  - 카메라 이동, 지형물 투명화 처리
  - Timeline 시스템을 활용한 엔딩 시네마틱 영상 제작
  - Steamworks 연동 (Facepunch 라이브러리 이용)
- 기타 
  - 인게임 시네마틱 영상 제작
  - 플레이어 애니메이션

### 성과
- 출시 시장플랫폼인 Steamworks 기본적인 이해
- 유니티 충돌 시스템에 대한 재고 및 개선방안에 대한 고민을 하게된 계기가 됨
- 파일 저장을 위한 JsonUtility 사용 경험
- 프레임 최적화를 위한 Task 비동기 프로그래밍 사용 경험

<!-- 유니티의 UnityEditor 라이브러리 사용 경험 -->

<br>

---

<br>

## [네트워크 4인 슈팅 게임( in Android and PC )](https://github.com/shehdrbs123/Dongs-Portfolio/tree/main/UnityProject/NetworkShooting)

[![미리보기](UnityProject/NetworkShooting.gif)](https://github.com/shehdrbs123/Dongs-Portfolio/tree/main/UnityProject/NetworkShooting)

<!--## [포트폴리오 영상 링크](https://youtu.be/9qI8dbMiV2M)-->

### 개요 
- 안드로이드 4인 비행슈팅 게임
  - 멀티플랫폼 가능(PC <-> Android)
- UNet(Unity Network) 기반 네트워크
- 개발 기간 : 2019.9 ~ 12 (3개월)

### 개발 내용
- Unity GUI를 이용, UI 설계
- Unity HLAPI 네트워크 시스템 이용한 네트워크 구현
- 플레이어 움직임, 상호작용 구현
- 적 오브젝트 설계 및 구현
  - 적기 2기 (각각 1개 패턴)
  - 보스 1기 ( 4개의 패턴 )
  
### 개발 세부
 - [UI / Scene](https://github.com/shehdrbs123/Dongs-Portfolio/tree/main/UnityProject/NetworkShooting/Description/UI%2C%20Scene)
 - [네트워킹](https://github.com/shehdrbs123/Dongs-Portfolio/tree/main/UnityProject/NetworkShooting/Description/Networking)
 - [Player](https://github.com/shehdrbs123/Dongs-Portfolio/tree/main/UnityProject/NetworkShooting/Description/Player)
 - [Enemy](https://github.com/shehdrbs123/Dongs-Portfolio/tree/main/UnityProject/NetworkShooting/Description/Enemy)
 - [Bullet](https://github.com/shehdrbs123/Dongs-Portfolio/tree/main/UnityProject/NetworkShooting/Description/Bullet)

### 성과
- 시스템 구조에 다양한 디자인 패턴을 적용 / 구현
- 유니티 API 사용능력 자기화
- 데이터 동기화, 서버/클라이언트 구조 확인 등 네트워크 게임 설계/구현 기반지식 획득
- IP, Port를 통한 접근으로 네트워크 스위치(포트포워드) 지식 습득
- 졸업프로젝트 통과

### 프로그램 다운로드 링크
- [다운로드(PC)](/shehdrbs123/Dongs-Portfolio/raw/main/UnityProject/NetworkShooting/SpWar(PC).zip)
- [다운로드(Android)](/shehdrbs123/Dongs-Portfolio/raw/UnityProject/NetworkShooting/SpWar(%EC%95%88%EB%93%9C%EB%A1%9C%EC%9D%B4%EB%93%9C).zip)

<a href="/shehdrbs123/Dongs-Portfolio/raw/main/UnityProject/NetworkShooting/SpWar(PC).zip" data-testid="raw-button" data-size="small" data-no-visuals="true" class="types__StyledButton-sc-ws60qy-0 FKJZl" download="true"><span data-component="buttonContent" class="Box-sc-g0xbh4-0 kkrdEu"><span data-component="text">Raw</span></span></a>


<br>

---

<br>

## [Doodle 점프 모작](https://github.com/shehdrbs123/Dongs-Portfolio/tree/main/JavaProject/Jumping%20Higher)
  
  [![미리보기](JavaProject/Jumping.gif)](https://github.com/shehdrbs123/Dongs-Portfolio/tree/main/JavaProject/Jumping%20Higher)

### 개요
- 플랫폼 : PC
- 개발 도구 : JAVA 8 (17버전 동작 확인), Eclipse
- 개발 기간 : 2014. 11 ~ 12

### 개발 내용 
  - Swing, AWT를 이용한 GUI 구현
  - 상속을 이용해 4개의 발판 구현, 씬을 로드하여 사용할 발판 선택 가능
  - 입력, 그리기, 충돌 분리하고 멀티스레딩을 활용하여 반응성 향상
  - 시간 레코드 기능 구현
  - 추락 시 게임 종료, 메인 이동 구현

### 성과
  - 게임 그래픽 시연과정에 대한 이해 (Double buffering)
  - 멀티스레딩 프로그래밍 적용
  - 코드 구조화에 대한 고민과 적용


<br>

---

<br>

## 그외 진행했던 프로젝트
### [Java WordStudy Helper](./JavaProject/EnglishStudy/)