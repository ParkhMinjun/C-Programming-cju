#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h> 

int main(void)
{
	char o;
	int a, b, res;

	printf("��Ģ���� �Է�(����):");
	scanf("%d %c %d", &a, &o, &b);

	switch (o)
	{
		{
			case '+': 
			res = a + b;     // + ��ȣ�̸� ���� �� ����������
			break; 
		}

		{
			case '-': 
			res = a - b;     // - ��ȣ�̸� ���� �� ����������
			break;
		}

		{
			case '*': 
			res = a * b;     // * ��ȣ�̸� ���� �� ����������
			break;
		}

		{
			case '/': 
			res = a / b;    // / ��ȣ�̸� ������ �� ����������
			break; 
		}

		{
			default:
			printf("�߸��� �����Է��Դϴ�.");    // +,-,*,/ �̿��� ��ȣ �Է½� ���
		}
			 
	}

	printf("%d %c %d = %d\n", a, o, b, res);

	return 0;
}