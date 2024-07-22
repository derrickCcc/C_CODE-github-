#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
int Max(int a, int b, int c)
{
    if (a > b) b = a;
    return b > c ? b : c;
}
int main()
{
    int a, b, c;
    float m = 0;

    scanf("%d %d %d", &a, &b, &c);
    m = 1.0 * Max(a + b, b, c) / (Max(a, b + c, c) + Max(a, b, b + c));

    printf("%.2f", m);
    return 0;
}


#include <stdio.h>

int SingleSum(long long n)
{
    int sum = 0;

    while (n)
    {
        sum += n % 10;
        n /= 10;
    }

    return sum;
}

int main()
{
    long long n;
    scanf("%lld", &n);

    int t;
    t = SingleSum(n);
    while (t > 9)
    {
        t = SingleSum(t);
    }

    printf("%d\n", t);
    return 0;
}