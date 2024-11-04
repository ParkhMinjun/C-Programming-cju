#include <stdio.h>
#include <stdlib.h> 
#include <time.h>   
   
#define END_COND 999  
#define ROCK_SCISSORS_PAPER 3  
#define ROCK  0
#define PAPER 1 
#define SCISSORS 2 
#define INITSTATUS 100 
#define PLAYER_WIN 11
#define PLAYER_WIN 12
#define DRAW 13 



// generating the seed number using the time clock information
void GenRandSeed()  
{
    // generating the random number using the time seed
    srand((unsigned int)(time(NULL)));  
    return;
}


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
    unsigned int nComRps = INITSTATUS;
    unsigned int nPlayerRps = INITSTATUS;

    while (1)
    {
        // generating the player's status
        printf("Input (ROCK:0,PAPER:1,SCISSORS:2):\n");
        printf("if you want to end the loop, please input 999\n");
        scanf_s("%d", &nPlayerRps);

        // exception #1, input condition
        if (nPlayerRps == END_COND)
        {
            printf("end of the infinite while loop RPS game...\n");
            break;
        }
        
        // exception #2, input, condition
        if ((nPlayerRps < 0) || (nPlayerRps >= ROCK_SCISSORS_PAPER))
        {
            printf("check your input condition..\n\n");
            continue;
        }
        
         // generating the random number
         unsigned int nComRps = GenRandNum(ROCK_SCISSORS_PAPER);

         // for debugging
         printf("(Player, Computer):(%d,%d)\n\n", nPlayerRps, nComRps);
        
    }
    switch (nGameRpsRes)
    {
    case PLAYER_WIN:
    {
        printf()
    }
    }

    return 0;
}

unsigned int CalcRpsGameRes(unsigned int nPlayerRps, unsigned int nComRps)
{
    if (nPlayerRps == nComRps)
    {
        return DRAW;
    }

    if ((nPlayerRps == ROCK) && (nComRps == SCISSORS))
    {
        return PLAYER_WIN;
    }
    else if ((nPlayerRps == SCISSORS) && (nComRps == ROCK))
    {
        return PLAYER_LOSE;
    }
    else
    {
        if (nPlayerRps<nComRps)
            return PLAYER_LOSE
        else
            return PLAYER_WIN
    }
}
