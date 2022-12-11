#include<iostream>
using namespace std;

class Point { //한 점을 표현하는 클래스
	int x, y;
public:
	Point(int x = 0, int y = 0) {
		this->x = x;
		this->y = y;
	}
	friend istream& operator >> (istream& ins, Point& a);
	friend ostream& operator << (ostream& stream, Point a);
};

istream& operator >> (istream& ins, Point& a) {
	cout << "x 좌표>>";
	ins >> a.x;
	cout << "y 좌표>>";
	ins >> a.y;
	return ins;
}

ostream& operator << (ostream& stream, Point a) {
	stream << "(" << a.x << "," << a.y << ")";
	return stream;
}

int main() {
	Point p;
	cin >> p; // >> 연산자 호출하여 x좌표와 y 좌표를 키보드로 읽어 객체 p 완성
	cout << p; // << 연산자를 호출하여 객체 p 출력
}