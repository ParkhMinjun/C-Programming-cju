#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) // 함수 시작
{
    float fN;  // 실수형 선언
    int iN;  // 정수형으로 변환할 변수 선언

    printf("실수(0~100)를 입력하세요:");  // 실수 입력 안내 메시지, 메시지로 범위 지정
    scanf("%f", &fN);    // 원하는 실수 입력

    // 실수값을 정수로 변환 switch문은 정수로 받기 때문에
    iN = (int)fN / 10;  // 예) 10으로 나눠서 90이상은 9라는 정수로 변환

    switch (iN)
    {
        {
            case 10:  // 100점일 경우
            printf("%.1f점은 %c학점입니다.", fN, 'A');  // A 학점입니다 출력
            break;  // 빠져나오기
        
        }

        {
            case 9:   // 90점 이상일 경우
            printf("%.1f점은 %c학점입니다.", fN, 'A');  // A 학점입니다 출력
            break;     // 빠져나오기
        }

        {
            case 8:   // 80점 이상일 경우
            printf("%.1f점은 %c학점입니다.", fN, 'B');  // B 학점입니다 출력
            break;    // 빠져나오기
        }

        {
            case 7:   // 70점 이상일 경우
            printf("%.1f점은 %c학점입니다.", fN, 'C');  // C 학점입니다 출력
            break;  // 빠져나오기
        }

        {
            case 6:   // 60점 이상일 경우
            printf("%.1f점은 %c학점입니다.", fN, 'D'); // D 학점입니다 출력
            break;  // 빠져나오기
        }

        {
            default:  // 60점 미만일 경우
            printf("%.1f점은 %c학점입니다.", fN, 'F');  // F 학점입니다 출력
            break;  // 빠져나오기
        }
    }

    return 0;
}