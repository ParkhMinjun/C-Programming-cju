#include <stdio.h>
#include <string.h>

void reverse_word(char* start, char* end) 
{
    char temp;
    while (start < end) 
    {
        temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
}

int main() 
{
    char input[100];

    printf("Enter a string: ");
    fgets(input, sizeof(input), stdin);

    // 개행문자 제거
    input[strcspn(input, "\n")] = '\0';

    printf("Before removing newline: \"%s\"\n", input);

    // 각 단어 뒤집기
    char* start = input;
    for (int i = 0; i <= strlen(input); i++) 
    {
        if (input[i] == ' ' || input[i] == '\0') 
        {
            reverse_word(start, &input[i - 1]);
            start = &input[i + 1];
        }
    }

    printf("After removing newline: \"%s\"\n", input);

    return 0;
}