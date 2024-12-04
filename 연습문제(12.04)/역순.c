#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 10

// ���� �迭 ���� �Լ�
// pDArr: �迭 ������, nArrSize: �迭 ũ��
void GenRandArray(double* pDArr, int nArrSize) 
{
    srand(time(NULL));
    for (int i = 0; i < nArrSize; i++) 
    {
        // rand()�� ����Ͽ� ���� �Ǵ� �Ǽ� ���� ����
        if (rand() % 2) 
        {
            // ���� ���� (-100 ~ 100)
            pDArr[i] = (double)(rand() % 201 - 100);
        }
        else 
        {
            // �Ǽ� ���� (-100.0 ~ 100.0)
            pDArr[i] = ((double)rand() / RAND_MAX) * 200.0 - 100.0;
        }
    }
}

// �迭 ���� ��ȯ �Լ�
// pDArr: ���� �迭 ������, nArrSize: �迭 ũ��
void CalcInverseArray(double* pDArr, int nArrSize) 
{
    double temp;
    // �迭�� ���ݸ�ŭ�� �ݺ��Ͽ� �糡 ���� ��ȯ
    for (int i = 0; i < nArrSize / 2; i++) 
    {
        temp = *(pDArr + i);
        *(pDArr + i) = *(pDArr + (nArrSize - 1 - i));
        *(pDArr + (nArrSize - 1 - i)) = temp;
    }
}

// �迭 ��� �Լ�
// pDArr: ����� �迭 ������, nArrSize: �迭 ũ��, description: ��� ����
void PrintArray(double* pDArr, int nArrSize, const char* description) 
{
    printf("\n%s:\n", description);
    for (int i = 0; i < nArrSize; i++) 
    {
        // �ε���, �޸� �ּ�, �� ���
        printf("[%d](%u, %.4lf)\n", i, (pDArr + i), *(pDArr + i));
    }
}

int main(void) 
{
    // �迭 ���� �� ������ ����
    double dArr[ARRAY_SIZE] = {};
    double* pDArr = dArr;

    // ���� �迭 ����
    GenRandArray(pDArr, ARRAY_SIZE);
    PrintArray(pDArr, ARRAY_SIZE, "���� �迭");

    // �迭 ���� ��ȯ
    CalcInverseArray(pDArr, ARRAY_SIZE);
    PrintArray(pDArr, ARRAY_SIZE, "���� �迭");

    return 0;
}