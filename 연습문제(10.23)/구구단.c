#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h> 

int main(void)
{
	int i, a, n; // ������ ���� ����

	printf("�������� ��� (2~9)��: ");  // ������ ��� �޽���
	scanf("%d", &a);                    // ���ϴ� ������ ���� �Է�

	printf("%d��\n", a);               // �Էµ� ������ ��� �޽���
	for (i = 1; i <= 9; i++)           // 1~9���� �ݺ�
	{
		printf("%d * %d = %d\n", a, i, a * i);   // �Է����� a*i(1~9) ���
	}

     // 2~9���� �� ���� ���
    printf("\n2~9�� ��ü ���:\n");   // ��ü ��� �޽���
    for (n = 2; n <= 9; n++)          // 2~9���� �ݺ�
	{
        printf("%d��:\n", n);        // 2~9�� ���
        for (i = 1; i <= 9; i++)    // 1~9���� �ݺ�
		{
            printf("%d * %d = %d\n", n, i, n * i);   // (2~9)*(1~9) ��� 
        }
    }

	return 0;
}