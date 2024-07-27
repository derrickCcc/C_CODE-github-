#define _CRT_SECURE_NO_WARNINGS


#include <stdio.h>
#include <math.h>

long long Reverse(long long m, int n)
{
    long long r = 0;
    while (m)
    {
        if (n < 11)
        {
            r = r * 10 + m % 10;
            m /= 10;
        }
        else
        {
            r = r * 16 + m % 16;
            m /= 16;
        }
    }

    return r;
}

long long Add(long long m, long long r, int n)
{
    long long u = 0;
    long long s = 0;
    long long j = 0;
    int i = 0;

    while (m)
    {
        if (n < 11)
        {
            u = m % 10 + r % 10 + j;
            j = u / n;
            s = s + u % n * pow(10, i);

            m /= 10;
            r /= 10;
            i++;
        }
        else
        {
            u = m % 16 + r % 16 + j;
            j = u / n;
            s = s + u % n * pow(16, i);

            m /= 16;
            r /= 16;
            i++;
        }
    }

    if (n < 11)
        s = s + j * pow(10, i);
    else
        s = s + j * pow(16, i);

    return s;

}

int main()
{
    int n;
    int flag = 0;
    int s = 0;
    long long m;
    scanf("%d", &n);
    if (n < 11)
        scanf("%lld", &m);
    else
        scanf("%x", &m);

    while (m != Reverse(m, n))
    {
        if (s > 30)
        {
            flag = 1;
            break;
        }

        m = Add(m, Reverse(m, n), n);
        s++;
    }

    if (flag == 0)
        printf("STEP=%d", s);
    else
        printf("Impossible!\n");

    return 0;
}