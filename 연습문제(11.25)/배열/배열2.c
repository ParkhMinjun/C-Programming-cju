#include<stdio.h>

int main(void)
{
    char str[100];  // �Է� ���� ���ڿ� ũ�� 100���� 99���� ���� �Է� ����
    int count = 0;  // �ٲ� ���� �� Ȯ�� ����(�빮�� ���� Ȯ��)
    int i;

    printf("���� �Է� : "); 
    scanf_s("%[^\n]s", str,sizeof(str)); // [^\n]:���� ���� �Է� ����, scanf_s���� sizeof�� �迭 ũ�⵵ �Բ� �����ؾ� ��

    for (i = 0; str[i]; i++)  //�Է� ���� ��ŭ �ݺ�
    {
        if (str[i] >= 'A' && str[i] <= 'Z')  // �빮���� ��� �ҹ��ڷ� ��ȯ �Լ�
        {
            str[i] += 32;  // ASCII �ڵ尪 32�� ���� �ҹ��ڷ� ��ȯ
            count++;       // �빮�� �߰� �� ���� ���� 
        }
    }
    printf("�ٲ� ���� : %s\n", str);
    printf("�ٲ� ���� �� : %d", count);

    return 0;
}