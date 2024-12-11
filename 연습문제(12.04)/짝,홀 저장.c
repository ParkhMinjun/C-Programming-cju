#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 10

// ���� �迭 ���� �Լ�
void GenRandArray(int* pArr, int nArrSize) 
{
    srand(time(NULL));
    for (int i = 0; i < nArrSize; i++) 
    {
        // 0~100 ������ ���� ���� ����
        *(pArr + i) = rand() % 101;
    }
}

// ¦��/Ȧ�� �и� �Լ�
// ��ȯ��: ¦�� ������ Ȧ�� ������ �����ͷ� ����
void CalcEvenOddArray(int* pInputArr, int* pEvenArr, int* pOddArr, int nArrSize, int* pEvenCount, int* pOddCount) 
{
    *pEvenCount = 0;
    *pOddCount = 0;

    // ¦��/Ȧ�� �и��Ͽ� ����
    for (int i = 0; i < nArrSize; i++) 
    {
        if (*(pInputArr + i) % 2 == 0) //¦��
        {
            *(pEvenArr + *pEvenCount) = *(pInputArr + i);
            (*pEvenCount)++;
        }
        else // Ȧ��
        {
            *(pOddArr + *pOddCount) = *(pInputArr + i);
            (*pOddCount)++;
        }
    }
}

// �迭 ��� �Լ�
void PrintArray(int* pArr, int nArrSize, const char* array) 
{
    printf("\n%s: ", array);
    printf("[����: %d]\n", nArrSize);
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

    // ���� �迭 ����
    GenRandArray(pInputArr, ARRAY_SIZE);
    PrintArray(pInputArr, ARRAY_SIZE, "���� �迭");

    // ¦��/Ȧ�� �и�
    CalcEvenOddArray(pInputArr, pEvenArr, pOddArr, ARRAY_SIZE, &evenCount, &oddCount);

    // ���� ������ŭ�� ���
    PrintArray(pEvenArr, evenCount, "¦�� �迭");
    PrintArray(pOddArr, oddCount, "Ȧ�� �迭");

    return 0;
}