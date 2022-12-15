#include <stdio.h>
#include<stdlib.h>

int main()
{
	int* list;
	list = (int*)malloc(3 * sizeof(int)); //동적 메모리 할당
	if(list == NULL) { //반환값이 NULL인지 검사
		return 1;
	}
	list[0] = 10;
	list[1] = 20;
	list[2] = 30;
	printf("%d %d %d",list[0], list[1], list[2]);
	free(list); //동적 메모리 할당 해제

	return 0;
}