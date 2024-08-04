#define _CRT_SECURE_NO_WARNINGS


int sumOddLengthSubarrays(int* arr, int arrSize)
{
    int sum = 0;
    int LCnt = 0;
    int RCnt = 0;

    for (int i = 0; i < arrSize; i++)
    {
        LCnt = i;
        RCnt = arrSize - 1 - i;

        int LOdd = (LCnt + 1) / 2;
        int ROdd = (RCnt + 1) / 2;

        int LEven = LCnt / 2 + 1;
        int REven = RCnt / 2 + 1;

        sum += arr[i] * (LOdd * ROdd + LEven * REven);
    }

    return sum;
}