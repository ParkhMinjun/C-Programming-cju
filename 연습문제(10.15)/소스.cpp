#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h> 

int main(void)
{
	char o;
	int a, b, res;

	printf("사칙연산 입력(정수):");
	scanf("%d %c %d", &a, &o, &b);

	switch (o)
	{
		{
			case '+': 
			res = a + b;     // + 기호이면 덧셈 후 빠져나오기
			break; 
		}

		{
			case '-': 
			res = a - b;     // - 기호이면 뺄셈 후 빠져나오기
			break;
		}

		{
			case '*': 
			res = a * b;     // * 기호이면 곱셈 후 빠져나오기
			break;
		}

		{
			case '/': 
			res = a / b;    // / 기호이면 나눗셈 후 빠져나오기
			break; 
		}

		{
			default:
			printf("잘못된 수식입력입니다.");    // +,-,*,/ 이외의 기호 입력시 출력
		}
			 
	}

	printf("%d %c %d = %d\n", a, o, b, res);

	return 0;
}