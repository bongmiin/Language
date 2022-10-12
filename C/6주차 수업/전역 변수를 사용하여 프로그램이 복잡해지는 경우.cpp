#include<stdio.h>
void f();

int i;
int main()
{
	for (i = 0; i < 5; i++)
	{
		f();
		printf("f() 함수 탈출 i =%d\n", i);
	}
	printf("모든 함수 종료 i =%d\n", i);
	return 0;
}

void f()
{
	for (i = 0; i < 10; i++)
	{
		printf("#");
	}
	printf("\n");
	printf(" f()루프 종료 i =%d\n", i);
	
}

