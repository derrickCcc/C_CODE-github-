#define _CRT_SECURE_NO_WARNINGS


int removeDuplicates(int* nums, int numsSize)
{
    int slow = 1;
    int fast = 1;
    while (fast < numsSize)
    {
        if (nums[fast] != nums[fast - 1])
        {
            nums[slow] = nums[fast];
            slow++;
        }
        fast++;
    }

    return slow;
}


int removeElement(int* nums, int numsSize, int val)
{
    int left = 0;
    for (int right = 0; right < numsSize; right++)
    {
        if (nums[right] != val)
        {
            nums[left] = nums[right];
            left++;
        }
    }
    return left;
}
