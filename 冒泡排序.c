#include <stdio.h>

int main()
{
	int a[10];
	int t;
	printf("input 10 number :\n");
	for (int i = 0; i < 10; i++)
	{
		scanf_s("%d", &a[i]);
	}
	for (int j = 0; j < 9; j++)
	{
		for (int i = 0; i < 9-j; i++)
		{
			if (a[i] > a[i + 1])
			{
				t = a[i];
				a[i] = a[i + 1];
				a[i + 1] = t;
			}
		}
	}
	printf("the sorted number :\n");
	for (int i = 0; i < 10; i++)
	{
		printf("%-4d", a[i]);
	}
	printf("\n");

}