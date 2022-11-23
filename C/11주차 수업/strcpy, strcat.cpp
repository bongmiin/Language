#include <stdio.h>
#include <string.h>

int main()
{
	char string[80];

	strcpy_s( string, "Hello world from ");
	strcat_s(string, "strcpy ");
	strcat_s(string, "and ");
	strcat_s(string, "strcat! ");
	printf_s("string = %s\n", string);

	return 0;
}