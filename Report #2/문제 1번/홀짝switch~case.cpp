#define _CRT_SECURE_NO_WARNINGS //scanf 오류 해결
#include <stdio.h>

int main(void)  // 함수 시작
{
	int nA;  // 정수형 선언 

	printf("정수를 입력하세요: ");  // 입력 안내메시지
	scanf("%d", &nA); // 원하는 정수 입력

	switch (nA % 2)   // switch문의 조건식 선언 입력받은 정수를 2로 나눈 나머지
	{
		{
	case 0:   // 조건식이 0일 경우
		printf("%d는(은) 짝수입니다.", nA);  // 짝수 출력 메시지
		break;         // 빠져나오기
		}

		{
	case 1:      // 조건식이 1일 경우
		printf("%d는(은) 홀수입니다.", nA);  // 홀수 출력 메시지
		break;         // 빠져나오기
		}
		{
	case -1:        // 조건식이 -1일경우
		printf("%d는(은) 홀수입니다.", nA);  // 홀수 출력 메시지
		break;        // 빠져나오기
		}

		{
	default:   // 해당경우 없을시
		break;     // 빠져나오기
		}
	}

	return 0;
}