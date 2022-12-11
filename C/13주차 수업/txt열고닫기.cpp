#include <stdio.h>

int main()
{
	FILE* ffp = NULL;

	ffp = fopen("sample.txt", "w");

	if (ffp == NULL)
		printf("파일 열기 실패");
	else
		printf("파일 열기 성공");

	fclose(ffp);

	return 0;
}