#include <stdio.h>
#include<stdlib.h>
#include<string.h>

struct Book {
	int number;
	char title[50];
};

int main()
{
	int i;
	struct Book* p;
	p = (struct Book*)malloc(2 * sizeof(struct Book));
	if (p == NULL)
		return -1;

	p[0].number = 1;
	strcpy(p[0].title, "C Programming");

	p[1].number = 2;
	strcpy(p[1].title, "Data Structure");

	for (i = 0; i < 2; i++) {
		printf("%d번 책 %s \n", p[i].number, p[i].title);
	}

	free(p);
	return 0;
}