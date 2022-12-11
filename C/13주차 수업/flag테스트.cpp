#include <stdio.h>

int main()
{
	printf("%10d\n", 123456); //10칸 오른쪽 정렬
	printf(" %-10d\n", 123456); //왼쪽 정렬
	printf(" %010d\n", 123456); //0으로 채우기
	printf("% d\n", 123456); //양수일 때는 공백
	printf("% d\n", -123456); //음수일 때는 -표시
	printf("%#10x\n", 123456); //16진수 0x 8진수 0

	return 0;
}