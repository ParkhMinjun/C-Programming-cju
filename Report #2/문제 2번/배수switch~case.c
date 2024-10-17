#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>

int main(void)  // 함수 시작
{
	int nA, nB;  // 두 정수 선언

	printf("두 개의 정수를 입력하세요:");   // 입력 안내 메시지 
	scanf("%d %d", &nA, &nB);      // 두 정수 입력

	switch (nA % nB)    // 첫번째 정수를 두번째 정수로 나눈후 나머지 값 조건 부여
	{
		{
			case 0:    // 나머지가 0일경우 배수이다.
			printf("%d는(은) %d의 배수이다.", nA, nB);   // 두 정수 배수 메시지 출력
			break;     //  case 실행 후 빠져나오기
		}

		{
			default:     // 0이 아닌 정수가 나올 경우
			printf("%d는(은) %d의 배수가 아니다.", nA, nB); // 두 정수는 배수가 아니다.
			break;  // 실행 후 빠져나오기(마지막 행 defalut는 break 없어도 실행 가능하다)
		}
	}

	return 0;
}