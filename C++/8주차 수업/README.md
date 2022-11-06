## 8주차 수업

### Cpp 프렌드

- 클래스의 멤버 함수가 아닌 외부 함수
	- 전역함수
	- 다른 클래스의 멤버 함수

- 프랜드 선언의 필요성
	- 클래스의 멤버로 선언하기에는 무리가 있고, 클래스의 모든 멤버를 자유롭게 접근할 수 있는 일부 외부 함수 작성 시

|항목|프랜드 함수|
|---|----|
|존재|클래스 외부에 작성된 함수, 멤버가 아님|
|자격|클래스의 멤버 자격 부여, 클래스의 모든 멤버에 대해 접근 가능|
|선언|클래스 내에 friend 키워드로 선언|
|개수|프랜드 함수 개수에 제한 없음|

### 프랜드로 초대하는 3개지 유형

1. 전역 함수: 클래스 외부에 선언된 전역 함수
```cpp
class Rect{
	friend bool equals(Rect r, Rect s);
}
```
2. 다른 클래스의 멤버 함수: 다른 클래스의 특정 멤버 함수
```cpp
class Rect {
	friend bool RectManager::equals(Rect r, Rect s);
};
```
3. 다른 클래스 전체: 다른 클래스의 모든 멤버 함수

> 프랜드 함수 만들기
```cpp
#include<iostream>
using namespace std;

class Rect;
bool equals(Rect r, Rect s);

class Rect {
	int width, height;
public:
	Rect(int width, int height) { this->width = width; this->height = height; }
	friend bool equals(Rect r, Rect s); //프랜드 함수 선언
};

bool equals(Rect r, Rect s) {
	if (r.width == s.width && r.height == s.height) return true;
	else return false;
}

int main()
{
	Rect a(3., 4), b(4, 5);
	if (equals(a, b)) cout << "equal" << endl;
	else cout << "not equal" << endl;
}
```
> 다른 클래스의 멤버 함수를 프렌드로 선언
```cpp
#include<iostream>
using namespace std;

class Rect;

class RectManager { // RectManager 클래스 선언
public:
	bool equals(Rect r, Rect s);
};

class Rect { // Rect 클래스 선언
	int width, height;
public:
	Rect(int width, int height) { this->width = width; this->height = height; }
	friend bool RectManager::equals(Rect r, Rect s); // 프렌드 함수 선언
};

bool RectManager::equals(Rect r, Rect s) { // RectManager::equals() 구현
	if (r.width == s.width && r.height == s.height) return true;
	else return false;
}

int main() {
	Rect a(3, 4), b(3, 4);
	RectManager man;

	if (man.equals(a, b)) cout << "equal" << endl;
	else cout << "not equal" << endl;
}
```
> 다른 클래스 전체를 프렌드로 선언
```cpp
#include<iostream>
using namespace std;

class Rect;

class RectManager { // RectManager 클래스 선언
public:
	bool equals(Rect r, Rect s);
	void copy(Rect& dest, Rect& src);
};

class Rect { // Rect 클래스 선언
	int width, height;
public:
	Rect(int width, int height) { this->width = width; this->height = height; }
	friend RectManager; // RectManager 클래스의 모든 함수를 프렌드 함수로 선언
};

bool RectManager::equals(Rect r, Rect s) { // r과 s가 같으면 true 리턴
	if (r.width == s.width && r.height == s.height) return true;
	else return false;
}

void RectManager::copy(Rect& dest, Rect& src) { // src를 dest에 복사
	dest.width = src.width;	dest.height = src.height;
}

int main() {
	Rect a(3, 4), b(5, 6);
	RectManager man;

	man.copy(b, a); // a를 b에 복사한다.
	if (man.equals(a, b)) cout << "equal" << endl;
	else cout << "not equal" << endl;
}
```

### 연산자 중복

- Cpp 언어에 본래부터 있던 연산자에 새로운 의미 정의
- 높은 프로그램 가독성

### 연산자 중복의 사례

- 정수 더하기

- 문자열 합치기

- 색 섞기
```cpp
Color a(BLUE), b(RED),c;
c = a + b; // c = VIOLET
```
- 배열 합치기
```cpp
SortedArray a(2,5,9), b(3,7,10), c;
c = a + b; // c = {2, 3, 5, 7, 9, 10}
```
### 연산자 중복의 특징

- Cpp에 본래 있는 연산자만 중복 가능
- 피 연산자 타입이 다른 새로운 연산 정의
- 연산자는 함수 형태로 구현 - 연산자 함수
- 반드시 클래스와 관계를 가짐
- 피연산자의 개수를 바꿀 수 없음
- 연산의 우선 순의 변경 안됨
- 모든 연산자가 중복 가능하지 않음

- 중복 가능한 연산자
|+|-|\*|

- 중복 불가능한 연산자

### 연산자 함수

- 연산자 함수 구현 방법 2가지
1. 클래스의 멤버 함수로 구현
2. **외부 함수로 구현하고 클래스에 프렌드 함수로 선언**
- operator 키워드와 함께 선언
- 리턴타입 operator 연산자(매개변수리스트);

### 이항 연산자 중복

- \+ 연산자

> 두 개의 파워 객체를 더하는 + 연산자 작성
```cpp
#include<iostream>
using namespace std;

class Power {
	int kick;
	int punch;
public:
	Power(int kick = 0, int punch = 0) {
		this->kick = kick; this->punch = punch;
	}
	void show();
	Power operator + (Power op2); // + 연산자 함수 선언
};

void Power::show() {
	cout << "Kick =" << kick << ',' << "Punch = " << punch << endl;
}
Power Power::operator+(Power op2) {
	Power tmp; // 임시 객체 생성
	tmp.kick = this->kick + op2.kick; // kick 더하기
	tmp.punch = this->punch + op2.punch; // punch 더하기
	return tmp; // 더한 결과 리턴
}

int main() {
	Power a(3, 5), b(4, 6), c;
	c = a + b; // 파워 객체 + 연산
	a.show();
	b.show();
	c.show();
}
```

- == 연산자

> 두 개의 Power 객체를 비교하는 == 연산자 작성
```cpp
#include<iostream>
using namespace std;

class Power {
	int kick;
	int punch;
public:
	Power(int kick = 0, int punch = 0) {
		this->kick = kick; this->punch = punch;
	}
	void show();
	bool operator == (Power op2); // == 연산자 함수 선언
	
};

void Power::show() {
	cout << "Kick =" << kick << ',' << "Punch = " << punch << endl;
}

bool Power::operator==(Power op2) {
	if (kick == op2.kick && punch == op2.punch) return true;
	else return false;
}
int main() {
	Power a(3, 5), b(3, 5); // 2개의 동일한 파워 객체 생성
	a.show();
	b.show();
	if (a == b) cout << "두 파워가 같다." << endl;
	else cout << "두 파워가 같지 않다." << endl;
	
}
```

### 단항 연산자 중복

- 피연산자가 하나 뿐인 연산자
	- 연산자의 중복 방식은 이항 연산자의 경우와 거의 유사함

- 단항 연산자 종류
	- 전위 연산자
		- !op, \~op, ++op
	- 후위 연산자
		- op++, op--

> 전위 ++연산자 작성
```cpp
#include<iostream>
using namespace std;

class Power {
	int kick;
	int punch;
public:
	Power(int kick = 0, int punch = 0) {
		this->kick = kick; this->punch = punch;
	}
	void show();
	Power& operator++ (); // 전위 ++ 연산자 함수 선언
};

void Power::show() {
	cout << "Kick =" << kick << ',' << "Punch = " << punch << endl;
}

Power& Power::operator++() {
	kick++;
	punch++;
	return *this; // 변경된 객체 자신(객체 a)의 참조 리턴
}

int main() {
	Power a(3, 5), b;
	a.show();
	b.show();
	b = ++a; // 전위 ++ 연산자 사용
	a.show();
	b.show();
}
```
> 후위 ++ 연산자 작성
```cpp
#include<iostream>
using namespace std;

class Power {
	int kick;
	int punch;
public:
	Power(int kick = 0, int punch = 0) {
		this->kick = kick; this->punch = punch;
	}
	void show();
	Power operator++ (int x); // 후위 ++ 연산자 함수 선언
};

void Power::show() {
	cout << "Kick =" << kick << ',' << "Punch = " << punch << endl;
}

Power Power::operator++(int x) {
	Power tmp = *this; // 증가 이전의 객체 상태를 저장
	kick++;
	punch++;
	return tmp; // 증가 이전 객체 상태 리턴
}

int main() {
	Power a(3, 5), b;
	a.show();
	b.show();
	b = a++; // 후위 ++ 연산자 사용
	a.show(); // a의 파워는 1 증가됨
	b.show(); // b는 a가 증가되기 이전 상태를 가짐
}
```
> 2+a를 위한 + 연산자 함수를 프렌드로 작성
```cpp
#include<iostream>
using namespace std;

class Power {
	int kick;
	int punch;
public:
	Power(int kick = 0, int punch = 0) {
		this->kick = kick; this->punch = punch;
	}
	void show();
	friend Power operator+(int op1, Power op2); // 프렌드 선언
};

void Power::show() {
	cout << "Kick =" << kick << ',' << "Punch = " << punch << endl;
}

Power operator+(int op1, Power op2) {
	Power tmp; // 임시 객체 생성
	tmp.kick = op1 + op2.kick; // kick 더하기
	tmp.punch = op1 + op2.punch; // punch 더하기
	return tmp; // 임시 객체 리턴
}

int main() {
	Power a(3, 5), b;
	a.show();
	b.show();
	b = 2 + a; // 파워 객체 더하기 연산
	a.show(); 
	b.show(); 
}
```
> a+b를 위한 연산자 함수를 프렌드로 작성
```cpp
#include<iostream>
using namespace std;

class Power {
	int kick;
	int punch;
public:
	Power(int kick = 0, int punch = 0) {
		this->kick = kick; this->punch = punch;
	}
	void show();
	friend Power operator+(Power op1, Power op2); // 프렌드 선언
};

void Power::show() {
	cout << "Kick =" << kick << ',' << "Punch = " << punch << endl;
}

Power operator+(Power op1, Power op2) {
	Power tmp; // 임시 객체 생성
	tmp.kick = op1.kick + op2.kick; // kick 더하기
	tmp.punch = op1.punch + op2.punch; // punch 더하기
	return tmp; // 임시 객체 리턴
}

int main() {
	Power a(3, 5), b(4, 6), c;
	c = a + b; // 파워 객체 더하기 연산
	a.show();
	b.show(); 
	c.show(); 
}
```
> ++연산자 함수를 프렌드로 작성
```cpp
#include<iostream>
using namespace std;

class Power {
	int kick;
	int punch;
public:
	Power(int kick = 0, int punch = 0) {
		this->kick = kick; this->punch = punch;
	}
	void show();
	friend Power& operator++(Power& op); // 전위 ++ 연산자 함수 프렌드 선언
	friend Power operator++(Power& op, int x); // 후위 ++ 연산자 함수 프렌드 선언
};

void Power::show() {
	cout << "Kick =" << kick << ',' << "Punch = " << punch << endl;
}

Power& operator++(Power& op) { // 전위 ++ 연산자 함수 구현
	op.kick++;
	op.punch++;
	return op; // 연산 결과 리턴
}

Power operator++(Power& op, int x) { // 후위 ++ 연산자 함수 구현
	Power tmp = op; // 변경하기 전의 op 상태 저장
	op.kick++;
	op.punch++;
	return tmp; // 변경 이전의 op 리턴
}
int main() {
	Power a(3, 5), b;
	b = ++a; // 전위 ++ 연산자
	a.show(); b.show(); 
	
	b = a++; // 후위 ++ 연산자
	a.show(); b.show();
}
```
