#define _CRT_SECURE_NO_WARNINGS //
#include <stdio.h> //

int main(void)
{
	char o;
	int a, b, res;

	printf("사칙연산 입력(정수):");
	scanf("%d %c %d", &a, &o, &b);

	if (o == '+')
	{
		printf("%d %c %d=%d\n", a, o, b, a + b);
	}
	else if (o == '-')
	{
		printf("%d %c %d=%d\n", a, o, b, a - b);
	}
	else if (o == '*')
	{
		printf("%d %c %d = %d\n", a, o, b, a * b);
	}
	else if (o == '/')
	{
		printf("%d %c %d=%d\n", a, o, b, a / b);
	}

	return 0;
}