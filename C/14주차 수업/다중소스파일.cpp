// source.cpp
#include <stdio.h>
#include "power.h"

int main()
{
	int x, y;

	printf("x의 값을 입력하시오: ");
	scanf("%d", &x);

	printf("y의 값을 입력하시오: ");
	scanf("%d", &y);
	printf("%d와 %d의 제곱값은 %f\n", x, y, power(x, y));

	return 0;
}

// power.cpp
#include "power.h"
double power(int x, int y)
{
	double result = 1.0;
	int i;

	for (i = 0; i < y; i++)
		result *= x;

	return result;
}

// power.h
#ifndef POWER_H
#define POWER_H

double power(int x, int y);
#endif