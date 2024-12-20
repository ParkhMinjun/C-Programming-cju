#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define SIZE 100        // 전체 배열 크기
#define EXTRACT_SIZE 10 // 추출할 개수

// 함수 원형 선언
void GenRanNum(int* arr, int size);
void extractNumbers(int* source, int* dest, int start, int count);
double calculateMean(int* arr, int size);
double calculateVariance(int* arr, int size, double mean);
double calculateStdDev(double variance);

// 난수 생성 함수
void GenRanNum(int* arr, int size)
{
    for (int i = 0; i < size; i++) 
    {
        arr[i] = rand() % 1000 + 1;  // 1~1000 사이의 난수 생성
    }
}

// 특정 범위의 숫자 추출 함수
void extractNumbers(int* source, int* dest, int start, int count) 
{
    for (int i = 0; i < count; i++) 
    {
        dest[i] = source[start + i];  // start 인덱스부터 count개 만큼 추출
    }
}

// 평균 계산 함수
double calculateMean(int* arr, int size) 
{
    double sum = 0;
    for (int i = 0; i < size; i++) 
    {
        sum += arr[i];
    }
    return sum / size;
}

// 분산 계산 함수
double calculateVariance(int* arr, int size, double mean) 
{
    double sum = 0;
    for (int i = 0; i < size; i++) 
    {
        sum += pow(arr[i] - mean, 2);  // (값 - 평균)^2 의 합
    }
    return sum / size;
}

// 표준편차 계산 함수
double calculateStdDev(double variance) 
{
    return sqrt(variance);  // 분산의 제곱근
}

// 메인 함수
int main() 
{
    int numbers[SIZE];          // 전체 난수를 저장할 배열
    int extracted[EXTRACT_SIZE];// 추출된 숫자를 저장할 배열

    // 난수 생성을 위한 시드 설정
    srand(time(NULL));

    // 난수 생성
    GenRanNum(numbers, SIZE);

    // 특정 범위(10~19 인덱스)의 숫자 추출
    extractNumbers(numbers, extracted, 10, EXTRACT_SIZE);

    // 총합 계산
    int sum = 0;
    for (int i = 0; i < EXTRACT_SIZE; i++) 
    {
        sum += extracted[i];
    }

    // 평균, 분산, 표준편차 계산
    double mean = calculateMean(extracted, EXTRACT_SIZE);
    double variance = calculateVariance(extracted, EXTRACT_SIZE, mean);
    double stdDev = calculateStdDev(variance);

    // 결과 출력
    printf("추출된 숫자들: ");
    for (int i = 0; i < EXTRACT_SIZE; i++) 
    {
        printf("%d ", extracted[i]);
    }
    printf("\n\n총합: %d\n", sum);
    printf("분산: %.2f\n", variance);
    printf("표준편차: %.2f\n", stdDev);

    return 0;
}