## 7주차 수업

### 함수 중복과 static 멤버
<br><br>
### 함수 중복
- 동일한 이름의 함수가 공존
	- 다형성
	- C언어에서는 불가능
- function overloading
- 함수 중복이 가능한 범위
	- 보통 함수들 사이
	- 클래스의 맴버 함수들 사이
	- 상속 관계에 있는 기본 클래스와 파생 클래스의 멤버 함수들 사이

- 함수 중복 성공 조건
	- 중복된 함수들의 이름 동일
	- 중복된 함수들의 매개 변수 타입이 다르거나 개수가 달라야 함
	- 라턴 타입은 함수 중복과 무관

- 함수 중복 편리함
	- 동일한 이름을 사용하면 함수 이름을 구분하여 기억할 필요 없고, 함수 호출을 잘못하는 실수를 줄일 수 있음	
> big 함수 중복 
```cpp
#include<iostream>
using namespace std;

int big(int a, int b)
{
	if (a > b) return a;
	else return b;
}
int big(int a[], int size)
{
	int res = a[0];
	for (int i = 0; i < size; i++)
		if (res < a[i]) res = a[i];
	return res;
}

int main()
{
	int array[5] = { 1, 9, -2, 8, 6 };
	cout << big(2, 3) << endl;
	cout << big(array, 5) << endl;
}
```
> sum() 함수 중복 연습
```cpp
#include<iostream>
using namespace std;

int sum(int a, int b)
{
	int s = 0;
	for (int i = a; i <= b; i++)
		s += i;
	return s;
}

int sum(int a)
{
	int s = 0;
	for (int i = 0; i <= a; i++)
		s += i;
	return s;
}
int main()
{
	cout << sum(3, 5) << endl;
	cout << sum(3) << endl;
	cout << sum(100) << endl;
}
```

### 생성자 함수 중복 가능
- 생성자 함수 중복 목적
	- 객체 생성 시, 매개 변수를 통해 다양한 형태의 초깃값 전달

### 소멸자 함수 중복 불가
- 소멸자는 매개 변수를 가지지 않음
<br><br>
## 디폴트 매개 변수

- 매개 변수에 값이 넘어오지 않는 경우, 디폴트 값을 받도록 선언된 매개 변수
	- **매개변수 = 디폴트값**으로 선언

### 디폴트 매개 변수에 관한 제약 조건
- 디폴트 매개 변수는 보통 매개 변수 앞에 선언될 수 없음
	- 디폴트 매개 변수는 끝쪽에 몰려 선언되어야 함
> 디폴트 매개 변수를 가진 함수 선언 및 호출
```cpp
#include<iostream>
#include<string>
using namespace std;

void star(int a = 5);
void msg(int id, string text = "");

void star(int a)
{
	for (int i = 0; i < a; i++) cout << '*';
	cout << endl;
}

void msg(int id, string text)
{
	cout << id << ' ' << text << endl;
}

int main()
{
	star();
	star(10);

	msg(10);
	msg(10, "Hello");
}
```
> 디폴트 매개 변수를 가진 함수 만들기 
```cpp
#include<iostream>
#include<string>
using namespace std;

void star(int a = 5);
void msg(int id, string text = "");

void f(char c = ' ', int line = 1);

void f(char c, int line)
{
	for (int i = 0; i < line; i++)
	{
		for (int j = 0; j < 10; j++)
			cout << c;
		cout << endl;
	}
}

int main()
{
	f();
	f('%');
	f('@', 5);
}
```
### 함수 중복 간소화
- 디폴트 매개 변수의 장점
- 중복 함수들과 디폴트 매개 변수를 가진 함수를 함께 사용 불가
> 생성자 함수의 중복 간소화
```cpp
#include<iostream>
using namespace std;

class MyVector {
	int* p;
	int size;
public:
	MyVector(int n = 100)
	{
		p = new int[n];
		size = n;
	}
	~MyVector() { delete[] p; }
};

int main()
{
	MyVector* v1, * v2;
	v1 = new MyVector();
	v2 = new MyVector(1024);

	delete v1;
	delete v2;
}
```

### 함수 중복의 모호성
- 매개 변수의 형 변환으로 인한 중복 함수 호출의 모호성
- 참조 매개 변수로 인한 함수 중복의 모호성
- 디폴트 매개 변수로 인한 함수 중복의 모호성
<br><br>

## static 멤버와 non-static 멤버
- static
	- 변수와 함수에 대한 기억 부류의 한 종류
		- **생명 주기 - 프로그램 시작 시 생성 ~ 프로그램 종료 시 소멸**
- 클래스의 멤버
	- static 멤버
		- 클래스당 하나만 생성
		- 클래스의 모든 객체들의 공유하는 멤버
	- non-static 멤버

### static 멤버 사용 
- 클래스명과 범위 지정 연산자 :: 로 접근
	- static 멤버는 클래스마다 오직 한 개만 생성되기 때문
- non-static 멤버는 클래스 이름으로 접근 불가

### static 활용
- static의 주요 활용
	- 전역 변수나 전역 함수를 클래스에 캡슐화
		- 전역 변수나 전역 함수를 가능한 사용하지 않도록   
		  전역 변수나 전역 함수를 static으로 선언하여 클래스 맴버로 선언
	- 객체 사이에 공유 변수를 만들고자 할 때
		- static 멤버를 선언하여 모든 객체들이 공유
> static 멤버를 가진 Math 클래스 작성
```cpp
#include<iostream>
using namespace std;

class Math
{
public:
	static int abs(int a) { return a > 0 ? a : -a; }
	static int max(int a, int b) { return (a > b) ? a : b; }
	static int min(int a, int b) { return (a > b) ? b : a; }

};

int main()
{
	cout << Math::abs(-5) << endl;
	cout << Math::max(10, 8) << endl;
	cout << Math::min(-3, -8) << endl;
}
```

### static 멤버 함수는 static 멤버만 접근 가능
- static 멤버 함수가 접근 가능한 함수
	- static 멤버 함수
	- static 멤버 변수
	- 함수 내의 지역 변수
- static 멤버 함수는 non-static 멤버에 접근 불가

### static 멤버함수는 this 사용 불가
> static 함수를 공유의 목적으로 사용
```cpp
#include<iostream>
using namespace std;

class Circle {
private:
	static int numOFCircles;
	int radius;
public:
	Circle(int r = 1);
	~Circle() { numOFCircles--; }
	double getArea() { return 3.14 * radius * radius; }
	static int getNumOfCircles() { return numOFCircles; }

};
Circle::Circle(int r)
{
	radius = r;
	numOFCircles++;
}
int Circle::numOFCircles = 0;

int main()
{
	Circle* p = new Circle[10];
	cout << "생존하고 있는 원의 개수 = " << Circle::getNumOfCircles() << endl;

	delete[] p;
	cout << "생존하고 있는 원의 개수 = " << Circle::getNumOfCircles() << endl;

	Circle a;
	cout << "생존하고 있는 원의 개수 = " << Circle::getNumOfCircles() << endl;

	Circle b;
	cout << "생존하고 있는 원의 개수 = " << Circle::getNumOfCircles() << endl;
}
```
