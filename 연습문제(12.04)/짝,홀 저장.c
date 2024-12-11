#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 10

// 랜덤 배열 생성 함수
void GenRandArray(int* pArr, int nArrSize) 
{
    srand(time(NULL));
    for (int i = 0; i < nArrSize; i++) 
    {
        // 0~100 사이의 정수 랜덤 생성
        *(pArr + i) = rand() % 101;
    }
}

// 짝수/홀수 분리 함수
// 반환값: 짝수 개수와 홀수 개수를 포인터로 전달
void CalcEvenOddArray(int* pInputArr, int* pEvenArr, int* pOddArr, int nArrSize, int* pEvenCount, int* pOddCount) 
{
    *pEvenCount = 0;
    *pOddCount = 0;

    // 짝수/홀수 분리하여 저장
    for (int i = 0; i < nArrSize; i++) 
    {
        if (*(pInputArr + i) % 2 == 0) //짝수
        {
            *(pEvenArr + *pEvenCount) = *(pInputArr + i);
            (*pEvenCount)++;
        }
        else // 홀수
        {
            *(pOddArr + *pOddCount) = *(pInputArr + i);
            (*pOddCount)++;
        }
    }
}

// 배열 출력 함수
void PrintArray(int* pArr, int nArrSize, const char* array) 
{
    printf("\n%s: ", array);
    printf("[개수: %d]\n", nArrSize);
    for (int i = 0; i < nArrSize; i++) 
    {
        printf("[%d](%u, %d)\n", i, (pArr + i), *(pArr + i));
    }
}

int main(void) 
{
    int inputArr[ARRAY_SIZE] = {};
    int evenArr[ARRAY_SIZE] = {};
    int oddArr[ARRAY_SIZE] = {};
    int evenCount = 0, oddCount = 0;

    int* pInputArr = inputArr;
    int* pEvenArr = evenArr;
    int* pOddArr = oddArr;

    // 랜덤 배열 생성
    GenRandArray(pInputArr, ARRAY_SIZE);
    PrintArray(pInputArr, ARRAY_SIZE, "원본 배열");

    // 짝수/홀수 분리
    CalcEvenOddArray(pInputArr, pEvenArr, pOddArr, ARRAY_SIZE, &evenCount, &oddCount);

    // 실제 개수만큼만 출력
    PrintArray(pEvenArr, evenCount, "짝수 배열");
    PrintArray(pOddArr, oddCount, "홀수 배열");

    return 0;
}