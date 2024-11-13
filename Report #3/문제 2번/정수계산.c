#include <stdio.h>
#include <stdlib.h>
#include <time.h> // 시간함수
#include <math.h> // 수학함수

unsigned int GenRandNum(unsigned int nRange)  // 양의 정수 생성 함수
{
    unsigned int nRes = 0;
    unsigned int nNum = rand();
    nRes = ((unsigned int)(nNum) % (nRange));
    return nRes;
}

int main() 
{
    int n = 10;  // 숫자 개수 선언
    int sum = 0;
    double mean = 0.0;
    double sum_squared = 0.0;

    srand(time(NULL)); // 난수 생성 time(Null)현재시간 시드값 사용

    // 합계와 평균 계산
    printf("생성된 난수: ");
    for (int i = 0; i < n; i++) // 10개 생성
    {
        int num = GenRandNum(100) + 1;  // 1~100 사이의 난수
        printf("%d ", num);  // 10개 난수 출력
        sum += num; // 합계 계산후 대입
    }
    printf("\n"); // 한칸 뛰우기

    mean = (double)sum / n; // 평균 계산

    // 분산 계산을 위한 제곱의 합
    srand(time(NULL));  // 같은 난수 시퀀스 재생성
    for (int i = 0; i < n; i++) 
    {
        int num = GenRandNum(100) + 1;
        sum_squared += pow(num - mean, 2); // (난수 - 평균)²을 계산-편차의 제곱
    }

    double variance = sum_squared / n; // 분산은 편차 제곱의 평균
    double stdDev = sqrt(variance);  // 표준편차는 분산의 제곱근

    // 값 출력
    printf("총합: %d\n", sum); 
    printf("평균: %.2f\n", mean);
    printf("분산: %.2f\n", variance);
    printf("표준편차: %.2f\n", stdDev);

    return 0;
}