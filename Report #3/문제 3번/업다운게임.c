#include <stdio.h>
#include <stdlib.h>
#include <time.h>

unsigned int GenRandNum(unsigned int nRange)  // ���� ���� ���� ����
{
    unsigned int nRes = 0;
    unsigned int nNum = rand();
    nRes = ((unsigned int)(nNum) % (nRange));
    return nRes;
}

void PlayUpDownGame() // ���ٿ���� �Լ�
{
    int answer = GenRandNum(100) + 1;  // 1~100 ������ ���� ����
    int num; // �Է°�
    int attempts = 10; // �õ� Ƚ�� 10 ����

    printf("1���� 100 ������ ���ڸ� ����������.\n");
    printf("��ȸ�� �� 10�� �Դϴ�.\n\n");

    for (int i = 1; i <= attempts; i++) // 10�� �ݺ���
    {
        printf("%d: ���ڸ� �Է��ϼ���: ", i); 
        scanf_s("%d", &num); // ����� �Է�

        if (answer < 1 || answer > 100) // 1~100�� ���� �ޱ� ���� ����� �޽��� ���
        {
            printf("1���� 100 ������ ���ڸ� �Է����ּ���!\n");
            i--;  // �õ� Ƚ�� ��ȿ
            continue; // ���� �ݺ� �Ѿ
        }

        if (num == answer) // ���� ������ ���
        {
            printf("�����Դϴ�. �õ� Ƚ���� %d���Դϴ�.\n", i);
            return;
        }
        else if (num < answer)  // ���亸�� ���� ���� �Է����� ��� 
        {
            printf("UP �� ū �����Դϴ�.\n");
        }
        else  // ���亸�� ū ���� �Է����� ���
        {
            printf("DOWN �� ���� �����Դϴ�.\n");
        }

        if (i == attempts) // ����� �Է°��� �������
        {
            printf("\n���� ��! ������ %d�Դϴ�.\n", answer);
        }
    }
}

int main() 
{
    srand(time(NULL)); // ���� ����
    PlayUpDownGame(); // �Լ� ȣ�� ���� ����
    return 0;
}