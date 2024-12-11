#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() 
{
    // 초기 배열 입력
    int InitialSize = 3;
    int* arr = (int*)malloc(InitialSize * sizeof(int));

    printf("초기 배열 크기: %d\n", InitialSize);
    printf("입력된 값: ");
    for (int i = 0; i < InitialSize; i++)
    {
        scanf_s("%d", &arr[i]);
    }

    // 초기 배열의 계산
    double InitialSum = 0;
    for (int i = 0; i < InitialSize; i++)
    {
        InitialSum += arr[i];
    }
    double InitialMean = InitialSum / InitialSize;

    double InitialVar = 0;
    for (int i = 0; i < InitialSize; i++) 
    {
        InitialVar += pow(arr[i] - InitialMean, 2); // pow 거듭제곱 연산
    }
    InitialVar /= InitialSize;

    double InitialStdDev = sqrt(InitialVar);

    // 초기 값 출력
    
    printf("초기 합계: %.2f\n", InitialSum);
    printf("초기 평균: %.2f\n", InitialMean);
    printf("초기 분산: %.2f\n", InitialVar);
    printf("초기 표준편차: %.2f\n", InitialStdDev);

    // 추가 배열 입력
    int AddSize = 2;
    int NewSize = InitialSize + AddSize;
    arr = (int*)realloc(arr, NewSize * sizeof(int)); // 재할당

    printf("\n추가 배열 크기: %d\n", AddSize);
    printf("추가값을 입력하세요: ");
    for (int i = InitialSize; i < NewSize; i++) 
    {
        scanf_s("%d", &arr[i]);
    }

    // 전체 배열의 계산
    double sum = 0;
    for (int i = 0; i < NewSize; i++) 
    {
        sum += arr[i];
    }
    double mean = sum / NewSize;

    double variance = 0;
    for (int i = 0; i < NewSize; i++) 
    {
        variance += pow(arr[i] - mean, 2);
    }
    variance /= NewSize;

    double std_dev = sqrt(variance);

    // 결과 출력
    printf("\n입력된 값: ");
    for (int i = 0; i < InitialSize; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n추가된 값: ");
    for (int i = InitialSize; i < NewSize; i++) 
    {
        printf("%d ", arr[i]);
    }
    
    printf("\n새로운 합계: %.2f\n", sum);
    printf("새로운 평균: %.2f\n", mean);
    printf("새로운 분산: %.2f\n", variance);
    printf("새로운 표준편차: %.2f\n", std_dev);

    free(arr);
    
    return 0;
}
