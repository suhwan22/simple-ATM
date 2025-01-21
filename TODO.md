# simple ATM Controller Project Checklist

## To-Do List

- [ ] **ATM 시나리오 작성**
  - 사용자 흐름과 시나리오를 문서화하기 (e.g., 카드 삽입 → PIN 입력 → 계좌 선택 → 입출금 및 잔액 조회).

- [ ] **ATM Controller 인터페이스 설계 및 구현**
  - 아래 기능을 포함한 인터페이스 설계:
    - [ ] `insertCard()`
    - [ ] `enterPIN()`
    - [ ] `selectAccount()`
    - [ ] `seeBalance()`
    - [ ] `deposit()`
    - [ ] `withdraw()`

- [ ] **ATM 인터페이스를 상속하는 Concrete Class 생성**
  - [ ] ATM 기능의 기본 구현을 제공하는 `SimpleATM` 클래스 만들기.

- [ ] **사용자 계좌 정보를 관리하는 `Account` 인터페이스 설계**

- [ ] **Account 인터페이스를 구현하는 Concrete Class 생성**
  - [ ] 계좌 정보를 저장 및 관리하는 클래스 구현 (e.g., `UserAccount`).

- [ ] **Exception Handling** PIN 오류, 출금 한도 초과, 잔액 부족 등을 처리하는 로직 추가.

- [ ] **Unit Tests 작성**
