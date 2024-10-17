#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>

int main(void)  // 함수 시작
{
	int nA, nB;  //  두 정수 선언

	printf("두 개의 정수를 입력하세요:");  // 입력 안내 메시지
	scanf("%d %d", &nA, &nB);    // 두 정수 입력

	if (nA % nB == 0)       //  첫번째 정수를 두번째 정수로 나눈후 나머지가 0일경우 배수 관계이다.
	{
		printf("%d는(은) %d의 배수이다.", nA, nB); // 배수 안내 메시지 출력
	}
	else      // 나머지가 0이 아닐경우
	{
		printf("%d는(은) %d의 배수가 아니다.", nA, nB);  // 두 정수는 배수가 아니다.
	}

	return 0;
}

	