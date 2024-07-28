#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
int main() {
    int n;
    while (scanf("%d", &n) != EOF)
    {
        int m = 1;
        for (int i = 0; i < n; i++)
            m *= 3;
        printf("%d\n", m - 1);
    }
    return 0;
}