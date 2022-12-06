#include <stdio.h>
#include <math.h>

struct point
{
	int x;
	int y;
};

int main()
{
	struct point p1 = { 10, 20 };
	struct point p2 = { 30, 40 };

	p2 = p1;

	if (p1 == p2)
		printf("p1이 p2와 같습니다.");

	if ((p1.x == p2.x) && (p1.y == p2.y))
		printf("p1이 p2와 같습니다");
	
	return 0;
}