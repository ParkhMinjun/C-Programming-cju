#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>

int main(void)  // 함수 시작
{
	int nA;  // 정수형 선언 

	printf("정수를 입력하세요: ");  // 입력 안내메시지
	scanf("%d", &nA); // 원하는 정수 입력

	if (nA % 2 == 0)         // 입력 정수를 2로 나눈 나머지가 0일 경우
	{
		printf("%d는(은) 짝수입니다.", nA);  // 짝수 출력 메시지
	}
	else if (nA % 2 == 1 || nA % 2 == -1)  // 입력 정수를 2로 나눈 나머지가 1 또는 -1일 경우, 음의 정수 고려 논리연산자 ||(OR) 사용
	{
		printf("%d는(은) 홀수입니다.", nA); // 홀수 출력 메시지
	}

	return 0;
}