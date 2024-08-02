#define _CRT_SECURE_NO_WARNINGS



int reverse(int x)
{
    long i = 0;
    int t = x;
    while (t)
    {
        i = i * 10 + t % 10;
        t /= 10;
    }

    if (i > INT_MAX || i < INT_MIN)
        return 0;

    return (int)i;
}



int* plusOne(int* digits, int digitsSize, int* returnSize)
{
    //int i;
    //for (i = digitsSize - 1; i >= 0; i--)
    //{
    //    digits[i]++;

    //    if (digits[i] != 10)
    //    {
    //        *returnSize = digitsSize;
    //        return digits;
    //    }
    //    else
    //    {
    //        digits[i] = 0;
    //    }
    //}

    //int* p = (int*)malloc(sizeof(int) * (digitsSize + 1));
    //memset(p, 0, sizeof(int) * (digitsSize + 1));
    //p[0] = 1;
    //*returnSize = digitsSize + 1;
    //return p;

    //效率更高
    int i = digitsSize - 1;
    int flag = 0;
    while (digits[i] == 9) {
        digits[i] = 0;
        if (i > 0)i--;
        else flag = 1;
    }
    if (flag != 1) {
        digits[i]++;
        *returnSize = digitsSize;
        return digits;
    }
    else {
        *returnSize = digitsSize + 1;
        int* arr = (int*)calloc(*returnSize, sizeof(int));
        arr[0] = 1;
        return arr;
    }

}

