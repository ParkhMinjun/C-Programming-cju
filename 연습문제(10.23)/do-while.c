#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h> 

int main()
{
    int n1, n2, gcd, lcm;  // 정수형 변수 선언 gcd:최대공약수,lcm:최소공배수

    printf("두 정수를 입력: ");  // 정수입력메시지
    scanf("%d %d", &n1, &n2);   // 정수 입력

    int On1 = n1; // 원본변수 저장위해 새 변수 On1선언(n1은 값이 변할예정)
    int On2 = n2; // 원본변수 저장위해 새 변수 On2선언(n2은 값이 변할예정)

    // 최대공약수 계산 (do-while) 
    do {
        if (n1 > n2)  // 만약 입력된 정수가 n1이 n2보다 크면
            n1 -= n2; // n1에 n2값 빼고 저장
        else
            n2 -= n1; // n2에 n1값 빼고 저장
    } while (n1 != n2);  // n1이랑n2가 같지 않을때 반복 (같으면 멈춘다)
    // do-while은 먼저 실행문 수행하고 조건식 검사 이 경우 while문과 큰 차이 없다

    gcd = n1; // 최종 결과 저장

    // 최소공배수 계산
    lcm = (On1 * On2) / gcd;  // 최소공배수 공식

    printf("최대 공약수: %d\n", gcd);  // 최대공약수 출력
    printf("최소 공배수: %d\n", lcm);  // 최소공배수 출력

    return 0;
}
