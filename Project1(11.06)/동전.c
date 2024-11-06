#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define NUM_FLIP 10000
#define COIN_FWD_BWD 3
#define COIN_FWD_STATUS 1
#define COIN_BWD_STATUS 2
#define COIN_NOT_VALID 0
#define INITSTATUS 100
#define END_COND 999



// generating the seed number using the time clock information
void GenRandSeed()
{
	// generating the random number using the time seed
	srand((unsigned int)(time(NULL)));
	return;
}

// generating the random number
unsigned int GenRandNumFlipCoin(unsigned int nRange)  // nRange는 3으로 설정됨. 뒤에 코드 살펴보면 COIN_FWD_BWD가 3으로 설정되어있음
{
	unsigned int nRes = 0;
    while (1)
    {
        nRes = ((unsigned int)(rand()) % (nRange)); 
        if ((nRes == COIN_FWD_STATUS) || (nRes == COIN_BWD_STATUS))  // 1 or 2 라면 빠져나온다, 0이면 무한루프
        {
         break;
        }
    }
	return nRes;
}

// main function loop
int main(void)
{
    // assigning seed
    GenRandSeed();

    // initializing variables
    int nNumSumFwdFlip = 0;
    int nNumSumBwdFlip = 0;
    double dvarFwdFlip = 0.0;
    double dvarBwdFlip = 0.0;
    double dStdevFwdFlip = 0.0;
    double dStdevBwdFlip = 0.0;


    // finite loop
     for(unsigned int i=0;i< NUM_FLIP;i++)
    {
       
        // generating the random number, flip coin, 0: fwd, 1: bwd
        unsigned int nStatusFlipCoin = GenRandNumFlipCoin(COIN_FWD_BWD);

        // calculating result
        switch (nStatusFlipCoin)
        {
        case COIN_FWD_STATUS:
            {
             nNumSumFwdFlip++;
             break;
            }
        case COIN_BWD_STATUS:
            { 
             nNumSumBwdFlip++;
             break;
            }
        default:
            {
             printf("please check your main loop or sub function...\n");
             break;
            }
        }
    }

     printf("Summation Result:(Fwd,Bwd):(%d,%d)\n", nNumSumFwdFlip, nNumSumBwdFlip);
     printf("Probability:(Fwd,Bwd):(%.4lf,%.4lf)\n", (double)nNumSumFwdFlip/(NUM_FLIP), (double)nNumSumBwdFlip/(NUM_FLIP));

    return 0;
}