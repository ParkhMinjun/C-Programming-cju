#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 배열 크기 지정
#define ARRAY_SIZE 10

// 랜덤 배열 생성 함수
void GenRandArray(double* pDArr, int nArrSize) 
{
    srand(time(NULL)); // 현재 시간을 시드값 지정
    for (int i = 0; i < nArrSize; i++) 
    {
        pDArr[i] = ((double)rand() / RAND_MAX) * 200.0 - 100.0;  // -100.0 ~ 100.0, RAND_MAX로 나누어 0~1사이의 실수로 scale, *200고 -100으로 범위 생성
    }
}

// 수동 입력 함수
void InputArray(double* pDArr, int nArrSize) 
{
    printf("10개의 숫자를 입력하세요 (-100.0 ~ 100.0):\n");
    for (int i = 0; i < nArrSize; i++) 
    {
        printf("숫자 %d: ", i + 1);
        scanf_s("%lf", pDArr + i);  // 포인터 연산으로 각 위치에 값 저장
    }
}

// 배열 정렬 함수
void CalcSortArray(double* pDArr, int nArrSize, int ascending)  // ascedning-정렬방향 1:오름차순, 0:내림차순
{
    for (int i = 0; i < nArrSize - 1; i++) //배열 전체 반복, n-1번 후 종료
    {
        for (int j = 0; j < nArrSize - 1 - i; j++) // -i로 이미 정렬된 부분은 제외해 반복
        {
            if (ascending) 
            {
                if (*(pDArr + j) > *(pDArr + j + 1)) // 오름차순일때 큰값을 뒤로 -현재값이 다음값보다 크면 교환
                {
                    // temp로 값 교환
                    double temp = *(pDArr + j);  // 임시저장  
                    *(pDArr + j) = *(pDArr + j + 1);   // 두번째 값 첫번째로 이동
                    *(pDArr + j + 1) = temp; // 임시값 두번째로 이동
                }
            }
            else 
            {
                if (*(pDArr + j) < *(pDArr + j + 1)) //내림차순일때 작은값을 뒤로-현재값이 다음값보다 작으면 교환
                {
                    double temp = *(pDArr + j);
                    *(pDArr + j) = *(pDArr + j + 1);
                    *(pDArr + j + 1) = temp;
                }
            }
        }
    }
}

// 배열 출력 함수
void PrintArray(double* pDArr, int nArrSize) 
{
    for (int i = 0; i < nArrSize; i++) 
    {
        printf("[%d](%u, %.4lf)\n", i, (pDArr + i), *(pDArr + i));
    }
}

int main(void) 
{
    double dArr[ARRAY_SIZE] = {};
    double* pDArr = dArr;
    int choice;

    printf("배열 생성 방식 선택 (1: 랜덤 생성, 2: 수동 입력): ");
    scanf_s("%d", &choice);

    // 랜덤 함수 실행
    if (choice == 1) 
    {
        GenRandArray(pDArr, ARRAY_SIZE);
    }
    // 입력 함수 실행
    else 
    {
        InputArray(pDArr, ARRAY_SIZE);
    }

    printf("\n원본 배열:\n");
    PrintArray(pDArr, ARRAY_SIZE);

    printf("\n오름차순 정렬:\n");
    CalcSortArray(pDArr, ARRAY_SIZE, 1);
    PrintArray(pDArr, ARRAY_SIZE);

    printf("\n내림차순 정렬:\n");
    CalcSortArray(pDArr, ARRAY_SIZE, 0);
    PrintArray(pDArr, ARRAY_SIZE);

    return 0;


}