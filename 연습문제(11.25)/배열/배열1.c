#include<stdio.h>

int main(void)
{
	int A[3] = { 1,2,3 }; // A 배열 선언 1,2,3
	int B[10];            // B 배열 선언
	int i;

	for (i = 0; i < 10; i++)   // B 배열 채우기 위해 개수 반복
	{
		B[i] = A[i % 3];  // A 배열 0~2 가지기 위해 나머지 연산자 % 사용
	}

	for (i = 0; i < 10; i++)  // 10번 출력 위해 반복
	{
		printf("%3d",B[i]);  // B 배열 출력
	}
	return 0;
}