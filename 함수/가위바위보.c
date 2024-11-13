#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define _CRT_SECURE_NO_WARNINGS 
#define ROCK_PAPER_SCISSORS 3
#define ROCK 0
#define PAPER 1
#define SCISSORS 2

#define PLAYER_WIN 11
#define PLAYER_LOSE 12
#define DRAW 13

// generating the seed number using the time clock information
void GenRandSeed()
{
    srand((unsigned int)(time(NULL)));
    return;
}

// generating the random number
unsigned int GenRandNum(unsigned int nRange)
{
    unsigned int nRes = 0;
    unsigned int nNum = rand();
    nRes = ((unsigned int)(nNum) % (nRange));
    return nRes;
}

// calculating result
unsigned int CalcRpsGameRes(unsigned int nPlayerRps, unsigned int nComRps)
{
    if (nPlayerRps == nComRps)
        return DRAW;

    if ((nPlayerRps == ROCK && nComRps == SCISSORS) ||
        (nPlayerRps == PAPER && nComRps == ROCK) ||
        (nPlayerRps == SCISSORS && nComRps == PAPER))
        return PLAYER_WIN;

    return PLAYER_LOSE;
}

int main(void)
{
    // assigning seed
    GenRandSeed();

    // initializing variables
    int nPlayerRps;
    int playerWins = 0, playerLosses = 0, draws = 0;

    // loop for exactly 3 rounds
    for (int round = 0; round < 3; round++)
    {
        // generating the player's status
        printf("Round %d - Input Your Status (ROCK:0, PAPER:1, SCISSORS:2):\n", round + 1);
        scanf_s("%d", &nPlayerRps);

        // input validation
        if ((nPlayerRps < ROCK) || (nPlayerRps >= ROCK_PAPER_SCISSORS))
        {
            printf("Invalid input! Please enter 0 for ROCK, 1 for PAPER, or 2 for SCISSORS.\n\n");
            round--; // repeat this round due to invalid input
            continue;
        }

        // generating the random choice for computer
        unsigned int nComRps = GenRandNum(ROCK_PAPER_SCISSORS);

        // calculating result
        unsigned int nGameRpsRes = CalcRpsGameRes(nPlayerRps, nComRps);

        // display choices for debugging purposes
        printf("Status(Player, Computer): (%d, %d)\n", nPlayerRps, nComRps);

        // updating win/loss/draw count based on result
        switch (nGameRpsRes)
        {
        case PLAYER_WIN:
            printf("Player Wins this round!\n\n");
            playerWins++;
            break;
        case PLAYER_LOSE:
            printf("Player Loses this round...\n\n");
            playerLosses++;
            break;
        case DRAW:
            printf("This round is a Draw!\n\n");
            draws++;
            break;
        default:
            printf("Unexpected result.\n\n");
            break;
        }
    }

    // Display final results after 3 rounds
    printf("Game Over! Final Results:\n");
    printf("Player Wins: %d\n", playerWins);
    printf("Player Losses: %d\n", playerLosses);
    printf("Draws: %d\n", draws);

    if (playerWins > playerLosses)
        printf("Overall Result: Player Wins!\n");
    else if (playerLosses > playerWins)
        printf("Overall Result: Player Loses...\n");
    else
        printf("Overall Result: It's a Draw!\n");

    return 0;
}