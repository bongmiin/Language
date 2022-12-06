#include <stdio.h>


struct vector getVectorSum(struct vector* a, struct vector* b);
struct vector {
	float x;
	float y;
};


int main()
{
	struct vector a = { 2.0, 3.0 };
	struct vector b = { 5.0, 6.0 };
	struct vector sum, *p, *q;
	p = &a;
	q = &b;
	sum = getVectorSum(p, q);
	printf("벡터의 합은 (%f, %f)입니다.\n", sum.x, sum.y);
	return 0;
}

struct vector getVectorSum(struct vector* a, struct vector* b)
{
	struct vector result;

	result.x = a->x + b->x;
	result.y = a->y + b->y;

	return result;
};