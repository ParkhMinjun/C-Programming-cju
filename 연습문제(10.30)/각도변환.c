#include <stdio.h>
#include <math.h>
#define PI 3.141592

double sin_deg(double degree);  // ���ΰ� ��ȯ�ϴ� �Լ� ����
double cos_deg(double degree);  // �ڻ��ΰ� �����ϴ� �Լ� ����

int main()
{
    double degree, sinValue, cosValue;  // ���� ����

    printf("������ �Է��ϼ��� (�� ����): ");   // ��� �޽���
    scanf_s("%lf", &degree);                   // ����� ���� �Է�

    sinValue = sin_deg(degree);                // ���ΰ� ���
    cosValue = cos_deg(degree);                // �ڻ��ΰ� ���

    printf("sin(%.f) = %.2f\n", degree, sinValue);  // ���ΰ� ��� ��� �޽���
    printf("cos(%.f) = %.2f\n", degree, cosValue);  // �ڻ��ΰ� ��� ��� �޽���

    return 0;
}

 // sin�� ��� �Լ�
double sin_deg(double degree)             
{
    return sin(degree * (PI / 180.0)); // ���� �������� ��ȯ �� ��� ��ȯ
}
 // cos�� ��� �Լ�
double cos_deg(double degree)           
{
    return cos(degree * (PI / 180.0)); // ���� �������� ��ȯ �� ��� ��ȯ
}
