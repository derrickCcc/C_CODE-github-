#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>

int main()
{
    int l, r, i;
    int flag = 0;
    int sum = 0;
    scanf("%d %d", &l, &r);

    for (i = l; i <= r; i++)
    {
        flag = 0;

        if (i == 1)
            i++;

        int j;
        for (j = 2; j <= sqrt(i); j++)
        {
            if (i % j == 0)
                flag = 1;
        }

        if (flag == 0)
            sum += i;
    }

    printf("%d\n", sum);
    return 0;
}