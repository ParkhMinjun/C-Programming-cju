#define _CRT_SECURE_NO_WARNINGS // scanf 오류 해결
#include <stdio.h> // 입출력 헤더 포함

int main(void) // 시작
{
	int nMoney, nPrice, nChange; // 정수형 선언-지불 값, 가격, 잔돈
	int C1000, C500, C100;  // 정수형 선언-1000원 개수,500원 개수, 100원 개수


	printf("Input data(money,price):"); // 값,가격 입력 안내메시지 출력
	scanf("%d %d", &nMoney, &nPrice); // 원하는 값, 가격 입력

	nChange = nMoney - nPrice; // 잔돈 계산 공식=지불 값-가격

    if (nChange == 0) {
        printf("Don't need any change.\n"); // 만약 잔돈이 0원이 된다면 잔돈 필요 없다는 메시지 출력
        return 0;
    }

    C1000 = nChange / 1000;   // 1000원의 개수는 nChange에서 1000을 나눈 수
    nChange %= 1000;          // 복합대입연산자 %/ 사용 - nChange을 1000에 나눈 수를 다시 nChange에 대입

    C500 = nChange / 500;     // 500원의 개수는 nChange에서 500을 나눈 수
    nChange %= 500;           // nChange을 500에 나눈 수를 다시 nChange에 대입

    C100 = nChange / 100;     // 100원의 개수는 nChange에서 100을 나눈 수
    nChange %= 100;           // nChange을 100에 나눈 수를 다시 nChange에 대입

    printf("change: %d원\n", nMoney - nPrice); // 잔돈 결과 값 출력
    printf("1000원 : %d개\n", C1000);      // 1000원 개수 출력
    printf("500원 : %d개\n", C500);        // 500원 개수 출력
    printf("100원 : %d개\n", C100);        // 100원 개수 출력

    return 0;

}