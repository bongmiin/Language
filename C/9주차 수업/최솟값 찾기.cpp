#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 10

int main()
{
	int price[SIZE] = { 0 };
	int i, minimum;
	printf("----------------------------------\n");
	printf("1  2  3  4  5  6  7  8  9  10\n");
	printf("----------------------------------\n");
	srand((unsigned)time(NULL));
	for (i = 0; i < SIZE; i++)
	{
		price[i] = (rand() % 100);
		printf("%-3d", price[i]);
	}
	printf("\n\n");
	minimum = price[0];
	for (i = 1; i < SIZE; i++)
	{
		price[i] < minimum ? minimum = price[i] : 1;
	}
	printf("최솟값은 %d입니다.", minimum);
	return 0;

}