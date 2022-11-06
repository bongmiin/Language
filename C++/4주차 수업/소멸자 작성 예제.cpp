class Circle {
public:
	int radius;

	Circle();
	Circle(int r);
	~Circle();
	double getArea();
};

Circle::Circle() {
	radius = 1;
}

Circle::Circle(int r) {
	radius = r;
}

Circle::~Circle() {
	cout << "반지름" << radius << "원 소멸" << endl;
}

double Circle::getArea() {
	return 3.14*radius*radius;
}