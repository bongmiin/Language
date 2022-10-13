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