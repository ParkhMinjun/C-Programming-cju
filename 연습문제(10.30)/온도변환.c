/*#include <stdio.h>

double celsius(double C);    // ȭ�� ��ȯ �Լ� ����
double fahrenheit(double F); // ���� ��ȯ �Լ� ����

int main()
{
    double C, F;             //  ���� ����
    printf("���� �µ��� �Է��ϼ���:");  // ��� �޽���
    scanf_s("%lf", &C);                 // ����� �����µ� �Է�

    F = celsius(C);         // �Լ��� ȭ���µ� �� ���� 
    printf("ȭ�� �µ���:%.1f\n", F);   // ȭ���µ� ��� �޽���

    printf("ȭ�� �µ��� �Է��ϼ���:");  // ��� �޽���
    scanf_s("%lf", &F);                // ����� ȭ���µ� �Է�

    C = fahrenheit(F);                // �Լ��� �����µ� �� ����
    printf("���� �µ���:%.1f\n", C);  // �����µ� ��� �޽���

    return 0;
}

// ������ ȭ���� ��ȯ�ϴ� �Լ�
double celsius(double C)
{
    return (C * 9.0 / 5.0) + 32.0; // ������ ȭ���� ��� �� ��ȯ
}

// ȭ���� ������ ��ȯ�ϴ� �Լ�
double fahrenheit(double F)
{
    return (F - 32.0) * 5.0 / 9.0; // ȭ���� ������ ��� �� ��ȯ
}*/