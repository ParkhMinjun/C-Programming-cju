#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h> 

int main(void)
{
	int i, a, n; // 정수형 변수 선언

	printf("구구단을 출력 (2~9)단: ");  // 구구단 출력 메시지
	scanf("%d", &a);                    // 원하는 구구단 정수 입력

	printf("%d단\n", a);               // 입력된 구구단 출력 메시지
	for (i = 1; i <= 9; i++)           // 1~9까지 반복
	{
		printf("%d * %d = %d\n", a, i, a * i);   // 입력정수 a*i(1~9) 출력
	}

     // 2~9단을 한 번에 출력
    printf("\n2~9단 전체 출력:\n");   // 전체 출력 메시지
    for (n = 2; n <= 9; n++)          // 2~9까지 반복
	{
        printf("%d단:\n", n);        // 2~9단 출력
        for (i = 1; i <= 9; i++)    // 1~9까지 반복
		{
            printf("%d * %d = %d\n", n, i, n * i);   // (2~9)*(1~9) 출력 
        }
    }

	return 0;
}