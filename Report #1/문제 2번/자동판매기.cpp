#define _CRT_SECURE_NO_WARNINGS // scanf ���� �ذ�
#include <stdio.h> // ����� ��� ����

int main(void) // ����
{
	int nMoney, nPrice, nChange; // ������ ����-���� ��, ����, �ܵ�
	int C1000, C500, C100;  // ������ ����-1000�� ����,500�� ����, 100�� ����


	printf("Input data(money,price):"); // ��,���� �Է� �ȳ��޽��� ���
	scanf("%d %d", &nMoney, &nPrice); // ���ϴ� ��, ���� �Է�

	nChange = nMoney - nPrice; // �ܵ� ��� ����=���� ��-����

    if (nChange == 0) {
        printf("Don't need any change.\n"); // ���� �ܵ��� 0���� �ȴٸ� �ܵ� �ʿ� ���ٴ� �޽��� ���
        return 0;
    }

    C1000 = nChange / 1000;   // 1000���� ������ nChange���� 1000�� ���� ��
    nChange %= 1000;          // ���մ��Կ����� %/ ��� - nChange�� 1000�� ���� ���� �ٽ� nChange�� ����

    C500 = nChange / 500;     // 500���� ������ nChange���� 500�� ���� ��
    nChange %= 500;           // nChange�� 500�� ���� ���� �ٽ� nChange�� ����

    C100 = nChange / 100;     // 100���� ������ nChange���� 100�� ���� ��
    nChange %= 100;           // nChange�� 100�� ���� ���� �ٽ� nChange�� ����

    printf("change: %d��\n", nMoney - nPrice); // �ܵ� ��� �� ���
    printf("1000�� : %d��\n", C1000);      // 1000�� ���� ���
    printf("500�� : %d��\n", C500);        // 500�� ���� ���
    printf("100�� : %d��\n", C100);        // 100�� ���� ���

    return 0;

}