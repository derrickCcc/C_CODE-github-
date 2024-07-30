#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main()
{
    int n, i;
    int arr[1000];
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);

        int t = arr[i];
        int cnt0 = 0;
        int cnt1 = 0;
        while (t)
        {
            if (t % 2 == 1)
                cnt1++;
            if (t % 2 == 0)
                cnt0++;
            t /= 2;
        }

        //printf("c0=%d c1=%d\n",cnt0,cnt1);
        if (cnt0 % 2 == 0 && cnt1 % 2 != 0)
            printf("0 ");
        else if (cnt1 % 2 == 0 && cnt0 % 2 != 0)
            printf("1 ");
        else if (cnt0 % 2 == 0 && cnt1 % 2 == 0)
            printf("10 ");
        else
            printf("100 ");
    }
    return 0;
}


#include <stdio.h>

int fib(int n)
{
    if (n <= 2)
        return n;
    else
        return fib(n - 1) + fib(n - 2);
}

int main()
{
    int n;
    scanf("%d", &n);

    printf("%d\n", fib(n));
    return 0;
}