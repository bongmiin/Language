### 문자와 문자열

- 컴퓨터에서는 각각의 문자에 숫자코드를 붙여서 표시한다
- 아스키코드: 표준적인 8비트 문자코드
	- 0에서 127까지의 숫자를 이용하여 문자 표현
- 유니코드: 표준적인 16비트 문자코드
	- 전세계의 모든 문자를 일관되게 표현하고 다룰 수 있도록 설계
	
1. 0번 NUL (null)
2. 0A LF (Line feed, new line)
3. 0D CR (carrige return)

> 화면에 askii 출력

### 문자열 표현 방법

- 문자열 : 문자들이 여러 개 모인 것
	- "A"
	- "Hello, World!"
- 문자열 변수
	- 변경가능한 문자열을 저장할 수 있는 변수
	- **문자열은 char형 배열로 저장**
	
### NULL 문자
- 문자열의 끝을 나타낸다.
- 문자열은 어디서 종료되는지 알수가 없으므로 표시를 해주어야 한다

1. 10진수를 16으로 나눔
2. 16진수 --> 4비트의 2진수 

### 문자열의 출력
```cpp
char str[] - "abc";
printf("%s", str);
```

> 문자 복사하는 예제

### 문자열 상수
```cpp
const char *p = "Hello, world!";
```
- const로 선언 시 그 값을 다른 값으로 변경 불가

### 문자 입출력 라이브러리

|입출력 함수|설명|
|------|--------|
|int getchar()|
|void putchar(int c)|
|int getch()|
|void putch(int c)|
|scanf|
|printf|

> getchar(), putchar()

1. 모든 문자는 일단 버퍼로 간다.
2. 엔터키가 입력되면 모두 프로그램으로 간다.

### 버퍼링

> _getch(), _putch() 

- 버퍼를 사용하지 않는다, 에코도 없음

### _getch, _getche, getchar

| |헤더파일|버퍼사용여부|에코여부|응답성|문자수정여부|
|------|----|------|-------|------|------|
|getchar()|<stdio.h>|사용함|에코|줄단위|가능|
|_getch()|<conio.h>|사용하지 않음|에코하지 않음|문자단위|불가능|
|_getche()|<conio.h>|사용하지 않음|에코|문자단위|불가능|

### 문자열 입출력 라이브러리 함수

> gets_s(), puts()

### 문자처리 라이브러리 함수
- is로 시작하는 다양한 문자 검사, 변환 함수가 있다
	- ctype.h 헤더 파일 사용

> islower,toupper	

### 문자열 처리 라이브러리

- **외우기**

> strcpy, strcat

> strcmp() 함수

> 문자 검색 strchr

### 문자열을 수치로 변환하는 전용함수

- atoi, atof
	- stdlib.h에 원형 정의

|함수|설명|
|------|---------|
|int atoi( const char *\str)|str을 int형으로 변환한다.|
|atoi|str을 long형으로 변환한다.|
|atof|str을 double형으로 변환한다.|