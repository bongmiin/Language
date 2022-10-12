#include<stdio.h>

extern unsigned random_i();
extern double random_f();

extern int MOD;

int main()
{
	int i;

	MOD = 10;
	for (i = 0; i < 10; i++)
		printf("%d", random_i());

	
	return 0;
}

