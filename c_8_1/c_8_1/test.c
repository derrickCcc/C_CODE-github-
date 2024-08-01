#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int Arr_Dig(int n, int m)
{
    if (m == 1)
        return n;
    else
        return n * Arr_Dig(n - 1, m - 1);
}
int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    printf("%d", Arr_Dig(n, m));
    return 0;
}


#include <stdio.h>

void Reverse(int n)
{
    if (n)
    {
        printf("%d", n % 10);
        Reverse(n / 10);
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    Reverse(n);
    return 0;
}