#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// �迭 ũ�� ����
#define ARRAY_SIZE 10

// ���� �迭 ���� �Լ�
void GenRandArray(double* pDArr, int nArrSize) 
{
    srand(time(NULL)); // ���� �ð��� �õ尪 ����
    for (int i = 0; i < nArrSize; i++) 
    {
        pDArr[i] = ((double)rand() / RAND_MAX) * 200.0 - 100.0;  // -100.0 ~ 100.0, RAND_MAX�� ������ 0~1������ �Ǽ��� scale, *200�� -100���� ���� ����
    }
}

// ���� �Է� �Լ�
void InputArray(double* pDArr, int nArrSize) 
{
    printf("10���� ���ڸ� �Է��ϼ��� (-100.0 ~ 100.0):\n");
    for (int i = 0; i < nArrSize; i++) 
    {
        printf("���� %d: ", i + 1);
        scanf_s("%lf", pDArr + i);  // ������ �������� �� ��ġ�� �� ����
    }
}

// �迭 ���� �Լ�
void CalcSortArray(double* pDArr, int nArrSize, int ascending)  // ascedning-���Ĺ��� 1:��������, 0:��������
{
    for (int i = 0; i < nArrSize - 1; i++) //�迭 ��ü �ݺ�, n-1�� �� ����
    {
        for (int j = 0; j < nArrSize - 1 - i; j++) // -i�� �̹� ���ĵ� �κ��� ������ �ݺ�
        {
            if (ascending) 
            {
                if (*(pDArr + j) > *(pDArr + j + 1)) // ���������϶� ū���� �ڷ� -���簪�� ���������� ũ�� ��ȯ
                {
                    // temp�� �� ��ȯ
                    double temp = *(pDArr + j);  // �ӽ�����  
                    *(pDArr + j) = *(pDArr + j + 1);   // �ι�° �� ù��°�� �̵�
                    *(pDArr + j + 1) = temp; // �ӽð� �ι�°�� �̵�
                }
            }
            else 
            {
                if (*(pDArr + j) < *(pDArr + j + 1)) //���������϶� �������� �ڷ�-���簪�� ���������� ������ ��ȯ
                {
                    double temp = *(pDArr + j);
                    *(pDArr + j) = *(pDArr + j + 1);
                    *(pDArr + j + 1) = temp;
                }
            }
        }
    }
}

// �迭 ��� �Լ�
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

    printf("�迭 ���� ��� ���� (1: ���� ����, 2: ���� �Է�): ");
    scanf_s("%d", &choice);

    // ���� �Լ� ����
    if (choice == 1) 
    {
        GenRandArray(pDArr, ARRAY_SIZE);
    }
    // �Է� �Լ� ����
    else 
    {
        InputArray(pDArr, ARRAY_SIZE);
    }

    printf("\n���� �迭:\n");
    PrintArray(pDArr, ARRAY_SIZE);

    printf("\n�������� ����:\n");
    CalcSortArray(pDArr, ARRAY_SIZE, 1);
    PrintArray(pDArr, ARRAY_SIZE);

    printf("\n�������� ����:\n");
    CalcSortArray(pDArr, ARRAY_SIZE, 0);
    PrintArray(pDArr, ARRAY_SIZE);

    return 0;


}