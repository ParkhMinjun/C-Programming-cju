#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define SIZE 100        // ��ü �迭 ũ��
#define EXTRACT_SIZE 10 // ������ ����

// �Լ� ���� ����
void GenRanNum(int* arr, int size);
void extractNumbers(int* source, int* dest, int start, int count);
double calculateMean(int* arr, int size);
double calculateVariance(int* arr, int size, double mean);
double calculateStdDev(double variance);

// ���� ���� �Լ�
void GenRanNum(int* arr, int size)
{
    for (int i = 0; i < size; i++) 
    {
        arr[i] = rand() % 1000 + 1;  // 1~1000 ������ ���� ����
    }
}

// Ư�� ������ ���� ���� �Լ�
void extractNumbers(int* source, int* dest, int start, int count) 
{
    for (int i = 0; i < count; i++) 
    {
        dest[i] = source[start + i];  // start �ε������� count�� ��ŭ ����
    }
}

// ��� ��� �Լ�
double calculateMean(int* arr, int size) 
{
    double sum = 0;
    for (int i = 0; i < size; i++) 
    {
        sum += arr[i];
    }
    return sum / size;
}

// �л� ��� �Լ�
double calculateVariance(int* arr, int size, double mean) 
{
    double sum = 0;
    for (int i = 0; i < size; i++) 
    {
        sum += pow(arr[i] - mean, 2);  // (�� - ���)^2 �� ��
    }
    return sum / size;
}

// ǥ������ ��� �Լ�
double calculateStdDev(double variance) 
{
    return sqrt(variance);  // �л��� ������
}

// ���� �Լ�
int main() 
{
    int numbers[SIZE];          // ��ü ������ ������ �迭
    int extracted[EXTRACT_SIZE];// ����� ���ڸ� ������ �迭

    // ���� ������ ���� �õ� ����
    srand(time(NULL));

    // ���� ����
    GenRanNum(numbers, SIZE);

    // Ư�� ����(10~19 �ε���)�� ���� ����
    extractNumbers(numbers, extracted, 10, EXTRACT_SIZE);

    // ���� ���
    int sum = 0;
    for (int i = 0; i < EXTRACT_SIZE; i++) 
    {
        sum += extracted[i];
    }

    // ���, �л�, ǥ������ ���
    double mean = calculateMean(extracted, EXTRACT_SIZE);
    double variance = calculateVariance(extracted, EXTRACT_SIZE, mean);
    double stdDev = calculateStdDev(variance);

    // ��� ���
    printf("����� ���ڵ�: ");
    for (int i = 0; i < EXTRACT_SIZE; i++) 
    {
        printf("%d ", extracted[i]);
    }
    printf("\n\n����: %d\n", sum);
    printf("�л�: %.2f\n", variance);
    printf("ǥ������: %.2f\n", stdDev);

    return 0;
}