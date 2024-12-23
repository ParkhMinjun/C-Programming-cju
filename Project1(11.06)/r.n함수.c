#include <stdio.h>
#include <stdlib.h> // 함수(library)
#include <time.h>   // 시간함수
#include <math.h>   // 수학함수
#define END_COND 999  // 전처리기 상수 부여

// generating the seed number using the time clock information
void GenRandSeed()  // 입력도 없고 출력도 없는 함수
{
    // generating the random number using the time seed
    srand((unsigned int)(time(NULL)));  // 형변환 정수중에 양수만
    return;
}


// char chAbcDef -ch시작
// char strAbcDef -str(ing) 문자열 시작
// int nAbcDef -n
// float fAbcDef -f
// double dAbcDef- d


// generating the random number
unsigned int GenRandNum(unsigned int nRange) // 양의 정수만
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
