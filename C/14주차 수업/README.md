## 전처리 및 다중 소스 파일

### 전처리기 
- 컴파일하기에 앞서서 소스 파일을 처리하는 컴파일러의 한 부분

## (표) 전처리기 요약 

- #define: 단순 메크로 정의
```cpp
#define PI 3.141592653
```
### 함수 매크로
- 매크로가 함수처럼 매개 변수를 가지는 것
```cpp
#define SQUARE(x) ((x) * (x))
```
> SQUARE 예제

> \#연산자 연습

> 비트조작메크로

> ifdef


## ifndef, undef 

- #ifndef
	- 어떤 매크로가 정의되어 있지 않으면 컴파일에 포함된다
	
- #undef
	- 매크로의 정의를 취소한다
	
### 다중 소스 파일

- 단일 소스 파일
	- 파일의 크기가 너무 커진다
	- 소스 파일을 재사용하기가 어려움
	
- 다중 소스 파일
	- 서로 관련된 코드만을 모아서 하나의 소스 파일로 할 수 있음
	
> 다중소스파일 

### 비트 필드 구조체
- 멤버가 비트 단위로 나누어져 있는 구조체
```cpp
struct 태그이름{
	자료형 멤버이름1: 비트수;
	자료형 멤버이름2: 비트수;
	...
};
```

### 동적 할당 메모리의 개념
- syntax

```cpp
int *p;
p = (int *)malloc(100 * sizeof(int));
```
> malloc와free

> 구조체 malloc

> 2차원 메모리 malloc

### calloc(), realloc()

- realloc() 함수는 할당하였던 메모리 블록의 크기를 변경
```cpp
int *p;
p = (int* )malloc(5* suzeof(int));
p = realloc(p, sizeof(int));
```

> realloc 예제

- **calloc은 메모리를 0으로 초기화해줌**

### 연결 리스트