#define _CRT_SECURE_NO_WARNINGS


#include <stdio.h>
#include <math.h>

int main()
{
    long long t, r;
    int flag = 0;
    scanf("%lld", &t);

    r = t;
    r /= 10;

    while (r)
    {
        t = (t * 10) + (r % 10);
        r /= 10;
    }

    for (int i = 2; i <= sqrt(t); i++)
    {
        if (t % i == 0)
            flag = 1;
    }

    if (flag == 0)
        printf("prime\n");
    else
        printf("noprime\n");
    return 0;
}