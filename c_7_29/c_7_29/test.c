#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>

int main()
{
    int n, m, i;
    scanf("%d %d", &n, &m);

    for (i = n; i <= m; i++)
    {
        int t = i;
        int s = 0;
        while (t)
        {
            s += pow(t % 10, 4);
            t /= 10;
        }
        if (s == i)
            printf("%d ", i);
    }
    return 0;
}