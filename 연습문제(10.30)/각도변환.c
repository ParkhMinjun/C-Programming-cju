#include <stdio.h>
#include <math.h>
#define PI 3.141592

double sin_deg(double degree);  // 사인값 반환하는 함수 선언
double cos_deg(double degree);  // 코사인값 반한하는 함수 선언

int main()
{
    double degree, sinValue, cosValue;  // 변수 선언

    printf("각도를 입력하세요 (도 단위): ");   // 출력 메시지
    scanf_s("%lf", &degree);                   // 사용자 각도 입력

    sinValue = sin_deg(degree);                // 사인값 계산
    cosValue = cos_deg(degree);                // 코사인값 계산

    printf("sin(%.f) = %.2f\n", degree, sinValue);  // 사인값 결과 출력 메시지
    printf("cos(%.f) = %.2f\n", degree, cosValue);  // 코사인값 결과 출력 메시지

    return 0;
}

 // sin값 계산 함수
double sin_deg(double degree)             
{
    return sin(degree * (PI / 180.0)); // 도를 라디안으로 변환 후 결과 반환
}
 // cos값 계산 함수
double cos_deg(double degree)           
{
    return cos(degree * (PI / 180.0)); // 도를 라디안으로 변환 후 결과 반환
}
