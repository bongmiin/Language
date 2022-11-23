#include <stdio.h>
#include<conio.h>

int main()
{
	int ch;
	while ((ch = _getch()) != 'q')
		_putch(ch);

	return 0;
}