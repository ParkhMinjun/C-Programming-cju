#include <stdio.h>

int sum(int n);

int main(void)
{
    int res;
    res = sum(10); // 1���� 10������ �� ���
    printf("%d", res);

    return 0;
}

int sum(int n)
{
    if (n == 1)
        return 1;
    else
        return n + sum(n - 1);
}
