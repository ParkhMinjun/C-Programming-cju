#include <stdio.h>
#include <stdlib.h> // �Լ�(library)
#include <time.h>   // �ð��Լ�
#include <math.h>   // �����Լ�
#define END_COND 999  // ��ó���� ��� �ο�

// generating the seed number using the time clock information
void GenRandSeed()  // �Էµ� ���� ��µ� ���� �Լ�
{
    // generating the random number using the time seed
    srand((unsigned int)(time(NULL)));  // ����ȯ �����߿� �����
    return;
}


// char chAbcDef -ch����
// char strAbcDef -str(ing) ���ڿ� ����
// int nAbcDef -n
// float fAbcDef -f
// double dAbcDef- d


// generating the random number
unsigned int GenRandNum(unsigned int nRange) // ���� ������
{
    unsigned int nRes = 0;
    unsigned int nNum = rand();
    nRes = ((unsigned int)(nNum) % (nRange));
    return nRes;
}

int main(void)
{
    // assigning seed
    GenRandSeed();

    // initializing variables
    int nRange = 0;

    while (1)
    {
        // generating the input information
        printf("Input a single number, for generating the random number related to your input:\n");
        printf("if you want to end the loop, please input 999\n");
        scanf_s("%d", &nRange);

        // escaping the while loop
        if (nRange == END_COND)
        {
            printf("end of the infinite while loop...\n");
            break;
        }
        else
        {
            // generating the random number
            int nRes = GenRandNum(abs(nRange));

            // for debugging
            printf("Result:random number generator, %d\n\n", nRes);
        }
    }

    system("pause");
    return 0;
}
