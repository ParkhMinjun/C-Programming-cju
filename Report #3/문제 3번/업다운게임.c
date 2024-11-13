#include <stdio.h>
#include <stdlib.h>
#include <time.h>

unsigned int GenRandNum(unsigned int nRange)  // 양의 정수 난수 생성
{
    unsigned int nRes = 0;
    unsigned int nNum = rand();
    nRes = ((unsigned int)(nNum) % (nRange));
    return nRes;
}

void PlayUpDownGame() // 업다운게임 함수
{
    int answer = GenRandNum(100) + 1;  // 1~100 사이의 난수 생성
    int num; // 입력값
    int attempts = 10; // 시도 횟수 10 선언

    printf("1부터 100 사이의 숫자를 맞혀보세요.\n");
    printf("기회는 총 10번 입니다.\n\n");

    for (int i = 1; i <= attempts; i++) // 10번 반복문
    {
        printf("%d: 숫자를 입력하세요: ", i); 
        scanf_s("%d", &num); // 사용자 입력

        if (answer < 1 || answer > 100) // 1~100의 수만 받기 범위 벗어나면 메시지 출력
        {
            printf("1부터 100 사이의 숫자를 입력해주세요!\n");
            i--;  // 시도 횟수 무효
            continue; // 다음 반복 넘어감
        }

        if (num == answer) // 숫자 맞혔을 경우
        {
            printf("정답입니다. 시도 횟수는 %d번입니다.\n", i);
            return;
        }
        else if (num < answer)  // 정답보다 작은 수를 입력했을 경우 
        {
            printf("UP 더 큰 숫자입니다.\n");
        }
        else  // 정답보다 큰 수를 입력했을 경우
        {
            printf("DOWN 더 작은 숫자입니다.\n");
        }

        if (i == attempts) // 정답과 입력값이 같을경우
        {
            printf("\n게임 끝! 정답은 %d입니다.\n", answer);
        }
    }
}

int main() 
{
    srand(time(NULL)); // 난수 생성
    PlayUpDownGame(); // 함수 호출 게임 시작
    return 0;
}