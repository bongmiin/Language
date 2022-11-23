#include <stdio.h>
#include <string.h>

int main()
{	
	char s[] = "language";
	char c = 'g';
	char* p;
	int loc;

	p = strchr(s, c); // 리턴값이 주소
	loc = (int)(p - s); // 주소값의 차를 계산 
	if (p != NULL)
		printf("첫 번째 %c가 %d에서 발견되었음\n", c, loc);
	else
		printf("%c가 발견되지 않았음 \n", c);
	return 0;
}