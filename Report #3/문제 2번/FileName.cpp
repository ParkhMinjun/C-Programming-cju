#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

unsigned int GenRandNum(unsigned int nRange) {
    unsigned int nRes = 0;
    unsigned int nNum = rand();
    nRes = ((unsigned int)(nNum) % (nRange));
    return nRes;
}

int main() {
    int n = 10;  // 숫자 개수
    int sum = 0;
    double mean = 0.0;
    double sum_squared = 0.0;

    srand(time(NULL));

    // 첫 번째 순회: 합계와 평균 계산
    printf("생성된 난수: ");
    for (int i = 0; i < n; i++) {
        int num = GenRandNum(100) + 1;  // 1~100 사이의 난수
        printf("%d ", num);
        sum += num;
    }
    printf("\n");

    mean = (double)sum / n;

    // 두 번째 순회: 분산 계산을 위한 제곱의 합
    srand(time(NULL));  // 같은 난수 시퀀스 재생성
    for (int i = 0; i < n; i++) {
        int num = GenRandNum(100) + 1;
        sum_squared += pow(num - mean, 2);
    }

    double variance = sum_squared / n;
    double stdDev = sqrt(variance);

    printf("총합: %d\n", sum);
    printf("평균: %.2f\n", mean);
    printf("분산: %.2f\n", variance);
    printf("표준편차: %.2f\n", stdDev);

    return 0;
}