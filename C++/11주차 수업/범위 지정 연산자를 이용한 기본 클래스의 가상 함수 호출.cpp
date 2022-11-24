#include<iostream>
using namespace std;

class Shape {
public:
	virtual void draw() {
		cout << "--Shape--";
	}
};

class Circle : public Shape {
public:
	virtual void draw() {
		Shape::draw(); //기본 클래스의 draw() 호출
		cout << "Circle" << endl;
	}
};

int main()
{
	Circle circle;
	Shape* pShape = &circle;

	pShape->draw(); // 동적 바인딩 발생. draw()가 virtual이므로
	pShape->Shape::draw(); // 정적 바인딩 발생. 범위 지정 연산자로 인해
}