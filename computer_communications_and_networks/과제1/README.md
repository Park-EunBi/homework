## 21년 컴퓨터 통신과 네트워크 과제 1  

### 과제 내용  
Random Binary Exponential Backoff 기법을 파이썬 코드로 구현   

### 과제 조건  
* backoff 메인 기능을 함수 형태로 작성   
    * 함수의 입력은 n  
    * 함수의 출력은 backoff 시간  
    * 함수 내에서 m의 값, m의 값을 기준으로 한 범위 값,   
    * 범위 내에서 random하게 선택된 k 값 출력  
    * 범위는 [0 ~ 2^m-1]  
* while 문 안에서 backoff 함수 호출  
* while 문의 횟수가 10회가 넘을 경우 프로그램 종료   