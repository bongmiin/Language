#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 6

int main()
{
	int freq[SIZE] = { 0 };
	int i;
	srand((unsigned)time(NULL));
	for (i = 0; i < 10000; i++)
	{
		++freq[rand() % 6];
	}
	printf("======================\n");
	printf("면		빈도\n");
	printf("======================\n");

	for (i = 0; i < SIZE; i++)
	{
		printf("%3d		%3d \n", i + 1, freq[i]);
	}
	return 0;
}