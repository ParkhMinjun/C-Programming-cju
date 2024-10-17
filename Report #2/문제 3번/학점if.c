#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>

int main(void)  // 함수 시작
{
	float fN;  // 실수형 선언
	
	printf("실수(0~100)를 입력하세요:");  // 실수 입력 안내 메시지, 메시지로 범위 지정
	scanf("%f", &fN);  // 원하는 실수 입력

	if (fN<=100 && fN >= 90)  // 90점 이상 100점 이하일 경우
	{
		printf("%.1f점은 %c학점입니다.", fN, 'A');  // A 학점입니다 출력
	}
	else if (fN >= 80)  // 80점 이상일 경우
	{
		printf("%.1f점은 %c학점입니다.", fN, 'B');   // B 학점입니다 출력
	}
	else if (fN >= 70)  // 70점 이상일 경우
	{
		printf("%.1f점은 %c학점입니다.", fN, 'C');   // C 학점입니다 출력
	}
	else if (fN >= 60) // 60점 이상일 경우
	{
		printf("%.1f점은 %c학점입니다.", fN, 'D');   // D 학점입니다 출력
	}
	else  // 60점 미만일 경우
	{
		printf("%.1f점은 %c학점입니다.", fN, 'F');   // F 학점입니다 출력
	}

	return 0;
}