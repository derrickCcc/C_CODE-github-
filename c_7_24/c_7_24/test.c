#define _CRT_SECURE_NO_WARNINGS


#include <stdio.h>

int Minus(int n, int m)
{
    if (n >= m)
        return n - m;
    else
        return m - n;
}

int main()
{
    int n, m, i, min, k, l;
    int a[1000];
    int b[1000];
    int suma = 0;
    int sumb = 0;
    scanf("%d %d", &n, &m);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        suma += a[i];
    }
    for (i = 0; i < m; i++)
        scanf("%d", &b[i]);

    min = suma;
    for (i = 0; i < m; i++)
    {
        int j;
        sumb = b[i];
        for (j = i + 1; j <= m; j++)
        {
            if (Minus(suma, sumb) < min)
            {
                min = Minus(suma, sumb);
                k = i;
                l = j;
            }
            sumb += b[j];
        }
    }

    for (i = k; i < l; i++)
        printf("%d ", b[i]);

    return 0;
}