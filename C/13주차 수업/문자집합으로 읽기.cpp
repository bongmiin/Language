//abc 무시하기
#include <stdio.h>

int main()
{
	char s[20];
	printf("문자열을 입력하시오: ");
	scanf("%[^abc]", s);
	
	printf("입력된 문자열= %s\n", s);
	
	return 0;
}
// abc만 읽기
#include <stdio.h>

int main()
{
	char s[20];
	printf("문자열을 입력하시오: ");
	scanf("%[abc]", s);
	
	printf("입력된 문자열= %s\n", s);
	
	return 0;
}