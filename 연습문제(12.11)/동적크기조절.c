#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() 
{
    // �ʱ� �迭 �Է�
    int InitialSize = 3;
    int* arr = (int*)malloc(InitialSize * sizeof(int));

    printf("�ʱ� �迭 ũ��: %d\n", InitialSize);
    printf("�Էµ� ��: ");
    for (int i = 0; i < InitialSize; i++)
    {
        scanf_s("%d", &arr[i]);
    }

    // �ʱ� �迭�� ���
    double InitialSum = 0;
    for (int i = 0; i < InitialSize; i++)
    {
        InitialSum += arr[i];
    }
    double InitialMean = InitialSum / InitialSize;

    double InitialVar = 0;
    for (int i = 0; i < InitialSize; i++) 
    {
        InitialVar += pow(arr[i] - InitialMean, 2); // pow �ŵ����� ����
    }
    InitialVar /= InitialSize;

    double InitialStdDev = sqrt(InitialVar);

    // �ʱ� �� ���
    
    printf("�ʱ� �հ�: %.2f\n", InitialSum);
    printf("�ʱ� ���: %.2f\n", InitialMean);
    printf("�ʱ� �л�: %.2f\n", InitialVar);
    printf("�ʱ� ǥ������: %.2f\n", InitialStdDev);

    // �߰� �迭 �Է�
    int AddSize = 2;
    int NewSize = InitialSize + AddSize;
    arr = (int*)realloc(arr, NewSize * sizeof(int)); // ���Ҵ�

    printf("\n�߰� �迭 ũ��: %d\n", AddSize);
    printf("�߰����� �Է��ϼ���: ");
    for (int i = InitialSize; i < NewSize; i++) 
    {
        scanf_s("%d", &arr[i]);
    }

    // ��ü �迭�� ���
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

    // ��� ���
    printf("\n�Էµ� ��: ");
    for (int i = 0; i < InitialSize; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n�߰��� ��: ");
    for (int i = InitialSize; i < NewSize; i++) 
    {
        printf("%d ", arr[i]);
    }
    
    printf("\n���ο� �հ�: %.2f\n", sum);
    printf("���ο� ���: %.2f\n", mean);
    printf("���ο� �л�: %.2f\n", variance);
    printf("���ο� ǥ������: %.2f\n", std_dev);

    free(arr);
    
    return 0;
}
