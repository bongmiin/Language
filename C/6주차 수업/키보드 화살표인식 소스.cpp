#include<stdio.h>
#include<conio.h>

int main()
{
	int key;
	printf("Start!!!\n");
	while (1)
	{
		key = _getch();

		if (key == 224)
		{
			key = _getch();

			switch (key)
			{
			case 72:
				printf("Up");
				break;
			case 75:
				printf("Left");
				break;
			case 77:
				printf("Right");
				break;
			case 80:
				printf("Down");
				break;
			default:
				printf("Etc");
				break;

			}
		}
	}
	return 0;
}
