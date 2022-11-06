## 5주차 강의

### C++ 구조체
- 상속, 멤버, 접근 지정 등 모든 것이 클래스와 동일
- 클래스와 유일하게 다른 점
	- 구조체의 디폴트 접근 지정 -public
	- 클래스의 디폴트 접근 지겅 -private
- C언어와의 호환성 때문

### 배열과 포인터

```cpp
int n[10];
int *p;
p = n; // p = &n[0]; 과 동일
*p = 100; // n[0] = 100; 과 동일
*(p + 5) = 8; // n[5] = 8; 과 동일

// 포인터의 산술 연산
p = p + 7; // p는 p[7]의 주소를 가지게 됨
*p = 99; // n[7] == 99; 와 동일
```
### 객체 포인터
- 객체에 대한 포인터
	- C 언어의 포인터와 동일
	- 객체의 주소 값을 가지는 변수
- 포인터로 멤버를 접근할 때
	- 객체포인터 -> 멤버	
> 객체 포인터 선언 및 활용
```cpp
#include <iostream>
using namespace std;

class Circle {
	int radius;
public:
	Circle() { radius = 1; }
	Circle(int r) { radius = r;}
	double getArea();
};

double Circle::getArea() {
	return 3.14*radius*radius;
}	

int main () {
	Circle donut;
	Cirlce pizza(30);

	//객체 이름으로 멤버 접근
	cout << dount.getArea() << endl;

	// 객체 포인터로 멤버 접근
	Circle *p;
	p = &dount;
	cout << p->getArea() << endl;
	cout << (*p)->getArea() << endl;

	p = &pizza;
	cout << p->getArea() << endl;
	cout << (*p)->getArea() << endl;
}
```

### 객체 배열, 생성 및 소멸
- 객체 배열 선언 가능 
	- 기본 타입 배열 선언과 형식 동일
		- int n[3]; : 정수형 배열 선언
		- **Circle c[3]; : Circle 타입의 배열 선언**
- 객체 배열 선언
	1. 객체 배열을 위한 공간 할당
	2. 배열의 각 원소 객체마다 생성자 실행
		- c[0]의 생성자, c[1]의 생성자, c[2]의 생성자 실행
		- **매개 변수 없는 생성자 호출**
	- 매개 변수 있는 생성자를 호출할 수 없음
		- Circle circleArray[3]; : 오류
- 배열 소멸
	- 배열의 각 객체마다 소멸자 호출, 생성의 반대순으로 소멸
		- c[2]의 소멸자, c[1]의 소멸자, c[0]의 소멸자 실행					
### 객체 배열 초기화
- 배열의 각 원소 객체당 생성자 지정하는 방법
	- Circle circleArray[3] = { Circle(10), Circle(20), Circle() };
	- circleArray[0] 객체가 생성될 때, 생성자 Circle(10) 호출
	- circleArray[1] 객체가 생성될 때, 생성자 Circle(20) 호출
	- circleArray[2] 객체가 생성될 때, 생성자 Circle() 호출

### 2차원 배열
---------------
![2차원 배열](../img/two-dimension_array)
------------------
>2 차원 배열 선언 및 활용
```cpp
#include <iostream>
using namespace std;

class Circle {
	int radius;
public:
	Circle() { radius = 1; }
	Circle(int r) { radius = r;}
	double getArea();
};

double Circle::getArea() {
	return 3.14*radius*radius;
}
int main() {
	Circle circles[2][3];

	circle[0][0].setRadius(1);
	circle[0][1].setRadius(2);
	circle[0][2].setRadius(3);
	circle[1][0].setRadius(4);
	circle[1][1].setRadius(5);
	circle[1][2].setRadius(6);

	for(int i = 0; i < 2; i++)
		for(int j = 0; j < 3; j++) {
			cout << "Circle [" << i << "," << j << "] 의 면적은 ";
			cout << circles[i][j].getArea() << endl;
		}
}
```

### 동적 메모리 할당 및 반환

|정적 할당|동적 할당|
|----|---------|
|변수 선언을 통해 필요한 메모리 할당|필요한 영이 예측되지 않는 경우, 프로그램 작성 시 할당 받을 수 없음|
|많은 양의 메모리는 배열 선언을 통해 할당|실행 중에 힙 메모리에서 할당<br>힙(heap)은 운영체제가 프로세스의 실행을 시작시킬 때 동적 할당 공간으로 준 메모리 공간|

- C++의 동적 메모리 할당/반환
|new 연산자|delete 연산자|
|-------|--------------|
|기본 타입 메모리 할당, 배열 할당, 객체 할당, 객체 배열 할당|new로 할당 받은 메모리 반환|
|객체의 동적 생성 - 힙 메모리로부터 객체를 위한 메모리 할당 요청|객체의 동적 소멸 - 소멸자 호출 뒤 객체를 힙에 반환|
|객체 할당 시 생성자 호출||

### new와 delete 연산자
- C++의 기본 연산자
- new/delete 연산자의 사용 형식
	- 데이터타입 \*포인터 변수 = new 데이터타입;<br>delete 포인터 변수;
- new/delete의 사용
```cpp
// 메모리 동적 할당
int *pInt = new int;
char *pChar = new char;
Circle *pCircle = new Circle(); // Circle 클래스 타입의 메모리 동적 할당

// 할당 받은 공간 반환
delete pInt;
delete pChar;
delete pCircle;	 			
```

### delete 사용 시 주의 사항
- 적절치 못한 포인터로 delete하면 실행 시간 오류 발생
	1. 동적으로 할당 받지 않은 메모리 반환 - 오류
	2. 동일한 메모리 두 번 반환 - 오류

> 정수형 배열의 동적 할당 및 반환
```cpp
int main() {
	cout << "입력할 정수의 개수는?";
	int n;
	cin >> n;
	if(n <= 0) return 0;
	int *p = new int[n]; //n 개의 정수 배열 동적 할당
	if(!p) {
		cout << "메모리를 할당할 수 없습니다.";
		return 0;
	}

	for(int i = 0; i < n; i++) {
		cout << i+1 << "번째 정수: ";
		cin >> p[i]; 
	}

	int sum = 0;
	for(int i = 0; i < n; i++)
		sum += p[i];
	cout << "평균 = " << sum/n << endl;

	delete [] p; // 배열 메모리 반환
}	
```

### 동적 할당 메모리 초기화 및 delete 시 유의 사항

1. 배열은 동적 할당 시 초기화 불가능
2. 배열 [] 생략 시 비정상적인 반환

### 객체의 동적 생성 및 반환

- 클래스 이름 \*포인터 변수 = new 클래스이름;
- 클래스 이름 \*포인터변수 = new 클래스이름(생성자매개변수리스트);
- delete **포인터변수**;

### 객체 배열의 동적 생성 및 반환

- 클래스이름 \*포인터변수 = new 클래스이름 [배열 크기];
- delete [] 포인터변수; -> 포인터 변수가 가리키는 객체 배열을 반환

----------------------
### this 포인터
- 포인터, 객체 자신 포인터
- 클래스의 멤버 함수 내에서만 사용
- 개발자가 선언하는 변수가 아니고, 컴파일러가 선언한 변수
	- 멤버 함수에 컴파일러에 의해 묵시적으로 삽입 선언되는 매개 변수

### this가 필요한 경우
1. 매개변수의 이름과 멤버 변수의 이름이 같은 경우
2. 멤버 함수가 객체 자신의 주소를 리턴할 때
	- 연산자 중복 시에 매우 필요

### this의 제약 사항
- 멤버 함수가 아닌 함수에서 this 사용 불가
	- 객체와의 관련성이 없기 때문
- static 멤버 함수에서 this 사용 불가
	- 객체가 생기기 전에 static 함수 호출이 있을 수 있기 때문에	

### string 클래스를 이용한 문자열

- C++ 문자열
	- C-스트링
	- C++ string 클래스의 객체
- string 클래스
	- C++ 표준 라이브러리, <string> 헤더 파일에 선언
	- 가변 크기의 문자열	
	- 다양한 문자열 연산을 실행하는 연산자와 멤버 함수 포함
	- 문자열, 스트링, 문자열 객체, string 객체 등으로 혼용

### string 객체 생성 및 입출력
- 문자열 생성
- 문자열 출력
	- cout과 << 연산자
- 문자열 입력
	- cin과 >> 연산자
- 문자열 숫자 변환
	- stoi()함수 이용
- **new/delete를 이용하여 문자열을 동적 생성/반환 가능** 	

> 문자열을 입력 받고 회전시키기
```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
	string s;

	cout << "문자열을 입력하세요(한글 안됨)" << endl;
	getline(cin, s, '\n'); //문자열 입력
	int len = s.length(); //문자열의 길이

	for(int i = 0; i < len; i++) {
		string first = s.substr(0, 1); // 맨 앞의 문자 1개를 문자열로 분리
		stirng sub = s.substr(1, len-1); // 나머지 문자들을 문자열로 분리
		s = sub + first; // 두 문자열을 연결하여 새로운 문자열로 만듦
		cout << s << endl;
	}
}
```