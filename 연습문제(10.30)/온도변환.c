/*#include <stdio.h>

double celsius(double C);    // 화씨 변환 함수 선언
double fahrenheit(double F); // 섭씨 변환 함수 선언

int main()
{
    double C, F;             //  변수 선언
    printf("섭씨 온도를 입력하세요:");  // 출력 메시지
    scanf_s("%lf", &C);                 // 사용자 섭씨온도 입력

    F = celsius(C);         // 함수로 화씨온도 값 대입 
    printf("화씨 온도는:%.1f\n", F);   // 화씨온도 출력 메시지

    printf("화씨 온도를 입력하세요:");  // 출력 메시지
    scanf_s("%lf", &F);                // 사용자 화씨온도 입력

    C = fahrenheit(F);                // 함수로 섭씨온도 값 대입
    printf("섭씨 온도는:%.1f\n", C);  // 섭씨온도 출력 메시지

    return 0;
}

// 섭씨를 화씨로 변환하는 함수
double celsius(double C)
{
    return (C * 9.0 / 5.0) + 32.0; // 섭씨를 화씨로 계산 후 반환
}

// 화씨를 섭씨로 변환하는 함수
double fahrenheit(double F)
{
    return (F - 32.0) * 5.0 / 9.0; // 화씨를 섭씨로 계산 후 반환
}*/