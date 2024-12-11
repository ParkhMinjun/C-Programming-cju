#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 10

// 랜덤 배열 생성 함수
// pDArr: 배열 포인터, nArrSize: 배열 크기
void GenRandArray(double* pDArr, int nArrSize) 
{
    srand(time(NULL));
    for (int i = 0; i < nArrSize; i++) 
    {
        // rand()를 사용하여 정수 또는 실수 랜덤 선택
        if (rand() % 2) 
        {
            // 정수 생성 (-100 ~ 100)
            pDArr[i] = (double)(rand() % 201 - 100);
        }
        else 
        {
            // 실수 생성 (-100.0 ~ 100.0)
            pDArr[i] = ((double)rand() / RAND_MAX) * 200.0 - 100.0;
        }
    }
}

// 배열 역순 변환 함수
// pDArr: 원본 배열 포인터, nArrSize: 배열 크기
void CalcInverseArray(double* pDArr, int nArrSize) 
{
    double temp;
    // 배열의 절반만큼만 반복하여 양끝 값을 교환
    for (int i = 0; i < nArrSize / 2; i++) 
    {
        temp = *(pDArr + i);
        *(pDArr + i) = *(pDArr + (nArrSize - 1 - i));
        *(pDArr + (nArrSize - 1 - i)) = temp;
    }
}

// 배열 출력 함수
// pDArr: 출력할 배열 포인터, nArrSize: 배열 크기, description: 출력 설명
void PrintArray(double* pDArr, int nArrSize, const char* description) 
{
    printf("\n%s:\n", description);
    for (int i = 0; i < nArrSize; i++) 
    {
        // 인덱스, 메모리 주소, 값 출력
        printf("[%d](%u, %.4lf)\n", i, (pDArr + i), *(pDArr + i));
    }
}

int main(void) 
{
    // 배열 선언 및 포인터 설정
    double dArr[ARRAY_SIZE] = {};
    double* pDArr = dArr;

    // 랜덤 배열 생성
    GenRandArray(pDArr, ARRAY_SIZE);
    PrintArray(pDArr, ARRAY_SIZE, "원본 배열");

    // 배열 역순 변환
    CalcInverseArray(pDArr, ARRAY_SIZE);
    PrintArray(pDArr, ARRAY_SIZE, "역순 배열");

    return 0;
}