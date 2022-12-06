#include <stdio.h>

struct date {
	int year;
	int month;
	int day;
};

struct student
{
	int number;
	char name[20];
	double grade;
	struct date* dob;
};

int main()
{
	struct date d = { 2000, 9, 10 };
	struct student s = {20224151, "김봉민", 4.4};
	s.dob = &d;
	
	printf("학번=%d, 이름=%s, 학점=%f\n", s.number, s.name, s.grade);
	printf("생년월일: %d년 %d월 %d일\n", s.dob->year, s.dob->month, s.dob->day);

	return 0;
}