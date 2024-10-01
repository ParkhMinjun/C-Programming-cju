#define _CRT_SECURE_NO_WARNINGS //scanf 오류 해결
#include <stdio.h> // 입출력 헤더 포함

int main(void) // main 함수-프로그램 시작
{
	double nDeg; // 실수형 선언 float은 오류 발생 아마 저장 범위 초과

	printf("Input data (deg):"); // 각도 입력 안내 메시지 출력
	scanf("%lf",&nDeg); // 원하는 각도 입력

	nDeg = nDeg - 360 * ((int)(nDeg / 360)); // 360도 이상이면 360으로 나눈후 정규화식 표현, (int)는 실수형으로 저장된 값을 정수형으로 바꾸는 형변환 연산자
	                                         // 예)450 입력 -> 450/360=1.25 -> 정수형 1 -> 1*360=360 -> 450-360=90

	nDeg=nDeg>180 ? nDeg-360 : nDeg; // 180도 초과일때 음수값 변환을 위한 조건연산자 ? 사용 - 만약 nDeg>180 참이 되면 nDeg-360 저장,거짓이면 nDeg 값 그대로 저장됨

	printf("Degree: %.2lf\n",nDeg); // 최종 저장된 값 소수점 형태로 출력, %.2lf로 소수점 둘째 자리까지 출력 

	return 0;
}