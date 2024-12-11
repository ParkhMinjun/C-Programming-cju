#include<stdio.h>

int main(void)
{
    char str[100];  // 입력 받을 문자열 크기 100설정 99개의 문자 입력 가능
    int count = 0;  // 바뀐 문자 수 확인 위해(대문자 개수 확인)
    int i;

    printf("문장 입력 : "); 
    scanf_s("%[^\n]s", str,sizeof(str)); // [^\n]:공백 포함 입력 받음, scanf_s사용시 sizeof로 배열 크기도 함께 지정해야 함

    for (i = 0; str[i]; i++)  //입력 문자 만큼 반복
    {
        if (str[i] >= 'A' && str[i] <= 'Z')  // 대문자인 경우 소문자로 변환 함수
        {
            str[i] += 32;  // ASCII 코드값 32를 더해 소문자로 변환
            count++;       // 대문자 발견 후 개수 증가 
        }
    }
    printf("바뀐 문장 : %s\n", str);
    printf("바뀐 문자 수 : %d", count);

    return 0;
}
