#define _CRT_SECURE_NO_WARNINGS


#include <stdio.h>

void Comma(long long n)
{
    if (n < 1000)
    {
        printf("%lld", n);
    }
    else
    {
        Comma(n / 1000);
        printf(",%03lld", n % 1000);
    }
}
int main()
{
    long long N;
    scanf("%lld", &N);
    Comma(N);
    return 0;
}



#include <stdio.h>
#include <string.h>

int main()
{
    char sum[10000];
    int i;

    gets(sum);

    for (i = 0; i < strlen(sum); i++)
    {
        if (sum[i - 1] == ' ' || i == 0)
        {
            if (sum[i] >= 'a' && sum[i] <= 'z')
                printf("%c", sum[i] - 32);
            else
                printf("%c", sum[i]);
        }
    }

    return 0;
}