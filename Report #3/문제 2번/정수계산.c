#include <stdio.h>
#include <stdlib.h>
#include <time.h> // �ð��Լ�
#include <math.h> // �����Լ�

unsigned int GenRandNum(unsigned int nRange)  // ���� ���� ���� �Լ�
{
    unsigned int nRes = 0;
    unsigned int nNum = rand();
    nRes = ((unsigned int)(nNum) % (nRange));
    return nRes;
}

int main() 
{
    int n = 10;  // ���� ���� ����
    int sum = 0;
    double mean = 0.0;
    double sum_squared = 0.0;

    srand(time(NULL)); // ���� ���� time(Null)����ð� �õ尪 ���

    // �հ�� ��� ���
    printf("������ ����: ");
    for (int i = 0; i < n; i++) // 10�� ����
    {
        int num = GenRandNum(100) + 1;  // 1~100 ������ ����
        printf("%d ", num);  // 10�� ���� ���
        sum += num; // �հ� ����� ����
    }
    printf("\n"); // ��ĭ �ٿ��

    mean = (double)sum / n; // ��� ���

    // �л� ����� ���� ������ ��
    srand(time(NULL));  // ���� ���� ������ �����
    for (int i = 0; i < n; i++) 
    {
        int num = GenRandNum(100) + 1;
        sum_squared += pow(num - mean, 2); // (���� - ���)���� ���-������ ����
    }

    double variance = sum_squared / n; // �л��� ���� ������ ���
    double stdDev = sqrt(variance);  // ǥ�������� �л��� ������

    // �� ���
    printf("����: %d\n", sum); 
    printf("���: %.2f\n", mean);
    printf("�л�: %.2f\n", variance);
    printf("ǥ������: %.2f\n", stdDev);

    return 0;
}