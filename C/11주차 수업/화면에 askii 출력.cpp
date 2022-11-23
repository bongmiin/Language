#include <stdio.h>

int main()
{
	int i;

	for (i = 33; i < 128; i++)
	{
		printf("%04d = %c ", i, i);
		if (i % 8 == 0)
			printf("\n");
	}
	return 0;
}