## 6주차 수업

### 함수의 인자 전달 리뷰
- **값에 의한 호출**
	- 함수가 호출되면 매개 변수가 스택에 생성됨
	- 호출하는 코드에서 값을 넘겨줌
	- 호출하는 코드에서 넘어온 값이 매개 변수에 복사됨

- **주소의 의한 호출 (pointer)**
	- 함수의 매개 변수는 포인터 타입
	- 호출하는 코드에서는 명시적으로 주소를 넘겨줌
	- 호출하는 코드에서 넘어온 값이 매개 변수에 저장됨

### 값에 의한 호출로 객체 전달
- 함수를 호출하는 쪽에서 객체 전달
	- 객체 이름만 사용

- 함수의 매개 변수 객체 생성
	- 매개 변수 객체의 공간이 스택에 할당
	- 호출하는 쪽의 객체가 매개 변수 객체에 그대로 복사됨
	- *매개 변수 객체의 생성자는 호출되지 않음*

- 함수 종료
> 값에 의한 호출 시에 생성자
```cpp
#include<iostream>
using namespace std;

class Circle {
private:
	int radius;
public:
	Circle();
	Circle(int r);
	~Circle();
	double getArea() { return 3.14 * radius * radius; }
	int getRadius() { return radius; }
	void setRadius(int radius) { this->radius = radius; }
	};

	Circle::Circle() {
		radius = 1;
		cout << "생성자 실행 radius = " << radius << endl;
	}

	Circle::Circle(int radius) {
		this->radius = radius;
		cout << "생성자 실행 radius = " << radius << endl;
	}

	Circle::~Circle() {
		cout << "소멸자 실행 radius = " << radius << endl;
	}
	void increase(Circle c) {
		int r = c.getRadius();
		c.setRadius(r + 1);
	}
	int main() {
		Circle waffle(30);
		increase(waffle);
		cout << waffle.getRadius() << endl;
	}
```
### 객체 치환 및 객체 리턴
- 객체 치환
	- 동일한 클래스 타입의 객체끼리 치환 가능
	- 객체의 모든 데이터가 비트 단위로 복사
	- 치환된 두 객체는 독립적인 공간 유지

- 객체 리턴
	- 객체의 복사본 리턴 
> 객체 리턴
```cpp
#include<iostream>
using namespace std;

class Circle {
	int radius;
public:
	Circle() { radius = 1; }
	Circle(int radius) { this->radius = radius; }
	void setRadius(int radius) { this->radius = radius; }
	double getArea() { return 3.14 * radius * radius; }
};

Circle getCircle() {
	Circle tmp(30);
	return tmp;
}

int main() {
	Circle c;
	cout << c.getArea() << endl;

	c = getCircle();
	cout << c.getArea() << endl;
}
```

### 참조와 함수
- 참조란 가리킨다는 뜻으로 이미 존재하는 객체나 변수에 대한 별명
	- 참조 변수
	- 참조에 의한 호출
	- 참조 리턴

### 참조 변수 선언
- 참조자 &의 도입
- 이미 존재하는 변수에 대한 다른 이름을 선언
	- 참조 변수는 이름만 생기며
	- 참조 변수에 새로운 공간을 할당하지 않는다.
	- 초기화로 지정된 기존 변수를 공유한다.
	```cpp
	int n = 2;
	int &refn = n;

	Circle circle;
	Circle &refc = circle;
	```
> 기본 타입 변수에 대한 참조
```cpp
#include<iostream>
using namespace std;

int main() {
	cout << "i" << '\t' << "n" << '\t' << "refn" << endl;
	int i = 1;
	int n = 2;
	int& refn = n; //참조 변수 refn 선언
	n = 4;
	refn++; // refn=5, n=5
	cout << i << '\t' << n << '\t' << refn << endl;

	refn = i; //refn=1, n=1
	refn++; // refn=2, n=2
	cout << i << '\t' << n << '\t' << refn << endl;

	int* p = &refn; // p는 n의 주소를 가짐
	*p = 20; // refn=20, n=20
	cout << i << '\t' << n << '\t' << refn << endl;
}
```
> 객체에 대한 참조
```cpp
#include<iostream>
using namespace std;

bool average(int a[], int size, int& avg)
{
	if (size <= 0)
		return false;
	int sum = 0;
	for (int i = 0; i < size; i++)
		sum += a[i];
	avg = sum / size;
	return true;
}

int main()
{
	int x[] = { 0,1,2,3,4,5 };
	int avg;
	if (average(x, 6, avg)) cout << "평균은 " << avg << endl;
	else cout << "매개 변수 오류" << endl;

	if (average(x, -2, avg)) cout << "평균은 " << avg << endl;
	else cout << "매개 변수 오류" << endl;
}
```

### 참조에 의한 호출
- 참조를 가장 많이 활용하는 사례
- call by reference
- 함수 형식
	- 함수의 매개 변수를 참조 타입으로 선언
	 - 참조 매개 변수 라고 부름
	 - 참조 매개 변수의 이름만 생기고 공간이 생기지 않음
	 - 참조 매개 변수는 실인자 변수 공간 공유
	 - 장조 매개 변수에 대한 조작은 실인자 변수 조작 효과
> 참조에 의한 호출로 Circle 객체에 참조 전달
```cpp
#include<iostream>
using namespace std;

class Circle
{
private:
	int radius;
public:
	Circle();
	Circle(int r);
	~Circle();
	double getArea() { return 3.14 * radius * radius; }
	int getRadius() { return radius; }
	void setRadius(int radius) { this->radius = radius; }
};

Circle::Circle()
{
	radius = 1;
	cout << "생성자 실행 radius = " << radius << endl;
}

Circle::Circle(int radius)
{
	this->radius = radius;
	cout << "생성자 실행 radius = " << radius << endl;
}

Circle::~Circle()
{
	cout << "소멸자 실행 radius = " << radius << endl;
}

void increaseCircle(Circle& c)
{
	int r = c.getRadius();
	c.setRadius(r + 1);
}

int main()
{
	Circle waffle(30);
	increaseCircle(waffle);
	cout << waffle.getRadius() << endl;
}
```
### 참조 리턴
- C++의 함수 리턴
	- 함수는 값 외에 참조 리턴 가능
	- **참조 리턴**
	 - 변수 등과 같이 현존하는 공간에 대한 참조 리턴
	  - **변수의 값을 리턴하는 것이 아님**
	  **값을 리턴하는 함수 VS. 참조를 리턴하는 함수**
> 간단한 참조 리턴 사례
```cpp
#include<iostream>
using namespace std;

bool average(int a[], int size, int& avg)
{
	if (size <= 0)
		return false;
	int sum = 0;
	for (int i = 0; i < size; i++)
		sum += a[i];
	avg = sum / size;
	return true;
}

int main()
{
	int x[] = { 0,1,2,3,4,5 };
	int avg;
	if (average(x, 6, avg)) cout << "평균은 " << avg << endl;
	else cout << "매개 변수 오류" << endl;

	if (average(x, -2, avg)) cout << "평균은 " << avg << endl;
	else cout << "매개 변수 오류" << endl;
}
```

### 얕은 복사와 깊은 복사
- 얕은 복사
	- 객체 복사 시, 객체의 멤버를 1:1로 복사
	- 객체의 멤버 변수에 동적 메모리가 할당된 경우
	 - 사본은 원본 객체가 할당 받은 메모리를 공유하는 문제 발생

- 깊은 복사
	- 객체 복사 시, 객체의 맴버를 1:1로 복사
	- 객체의 멤버 변수에 동적 메모리가 할당된 경우
	 - 사본은 원본이 가진 메모리 크기 만큼 별도로 동적 할당
	- 완전한 형태의 복사

### 복사 생성자
- 객체의 복사 생성시 호출되는 특별한 생성자
- 특징
	- 한 클래스에 **오직 한 개만** 선언 가능
	- 복사 생성자는 보통 생성자와 클래스 내에 중복 선언가능
	- 클래스에 대한 **참조 매개 변수**를 가지는 독특한 생성자
> Circle의 복사 생성자와 객체 복사
```cpp
#include<iostream>
using namespace std;

class Circle
{
private:
	int radius;
public:
	Circle(const Circle& c); //복사 생성자 선언
	Circle(int radius) { this->radius = radius; }
	double getArea() { return 3.14 * radius * radius; }
};

Circle::Circle(const Circle& c) //복사 생성자 구현
{
	this->radius = c.radius;
	cout << "복사 생성자 실행 radius = " << radius << endl;
}

int main()
{
	Circle src(30); // src 객체의 보통 생성자 호출
	Circle dest(src); // dest 객체의 복사 생성자 호출

	cout << "원본의 면적 = " << src.getArea() << endl;
	cout << "사본의 면적 = " << dest.getArea() << endl;
}
```

### 디폴트 복사 생성자
- 복사 생성자가 선언되어 있지 않는 클래스
	- 컴파일러는 자동으로 디폴트 복사 생성자 삽입
> 깊은 복사 생성자를 가진 정상적인 Person 클래스
```cpp
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include<iostream>
using namespace std;

class Person
{
	char* name;
	int id;
public:
	Person(int id, const char* name);
	Person(const Person& person);
	~Person();
	void changeName(const char* name);
	void show() { cout << id << ',' << name << endl; }
};

Person::Person(int id, const char* name)
{
	this->id = id;
	int len = strlen(name);
	this->name = new char[len + 1];
	strcpy(this->name, name);
}

Person::Person(const Person& person)
{
	this->id = person.id;
	int len = strlen(person.name);
	this->name = new char[len + 1];
	strcpy(this->name, person.name);
	cout << "복사 생성자 실행. 원본 객체의 이름 " << this->name << endl;
}

Person::~Person()
{
	if (name)
		delete[] name;
}

void Person::changeName(const char* name)
{
	if (strlen(name) > strlen(this->name))
		return;
	strcpy(this->name, name);
}

int main()
{
	Person father(1, "Kitae");
	Person daughter(father);

	cout << "daughter 객체 생성 직후 --------" << endl;
	father.show();
	daughter.show();

	daughter.changeName("Grace");
	cout << "daughter 이름을 Grace로 변경한 후 ----" << endl;
	father.show();
	daughter.show();

	return 0;
}
```
> 참조 매개 변수로 평균 리턴하기
```cpp
#include<iostream>
using namespace std;

bool average(int a[], int size, int& avg)
{
	if (size <= 0)
		return false;
	int sum = 0;
	for (int i = 0; i < size; i++)
		sum += a[i];
	avg = sum / size;
	return true;
}

int main()
{
	int x[] = { 0,1,2,3,4,5 };
	int avg;
	if (average(x, 6, avg)) cout << "평균은 " << avg << endl;
	else cout << "매개 변수 오류" << endl;

	if (average(x, -2, avg)) cout << "평균은 " << avg << endl;
	else cout << "매개 변수 오류" << endl;
}
```
