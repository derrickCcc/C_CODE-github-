#define _CRT_SECURE_NO_WARNINGS


#include <stdio.h>

int Add(int n)
{
    if (n == 1)
        return n;
    else
        return n + Add(n - 1);
}

int main()
{
    int n;
    scanf("%d", &n);
    printf("%d", Add(n));
    return 0;
}



#include <stdio.h>

int Digit(int x, int i)
{
    if (i == 1)
        return x % 10;
    else
        return x % 10 + 10 * Digit(x / 10, i - 1);
}
int main()
{
    int x, i;
    scanf("%d %d", &x, &i);
    printf("%d", Digit(x, i));
    return 0;
}