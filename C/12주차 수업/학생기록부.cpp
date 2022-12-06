#include <stdio.h>
#include <string.h>

struct student
{
	int number;
	char name[10];
	double grade;
};

int main()
{
	struct student s;

	printf("학번을 입력하세요: ");
	scanf_s("%d",&s.number);

	printf("이름을 입력하세요: ");
	scanf_s("%s", s.name, 10);

	printf("학점을 입력하세요(실수): ");
	scanf_s("%lf",&s.grade);

	printf("학번: %d,\n", s.number);
	printf("이름: %s,\n", s.name);
	printf("학점: %f,\n", s.grade);

	return 0;
}