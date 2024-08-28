#define _CRT_SECURE_NO_WARNINGS


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 /**
  * Note: The returned array must be malloced, assume caller calls free().
  */
struct ListNode** splitListToParts(struct ListNode* head, int k, int* returnSize)
{
    struct ListNode** ret = (struct ListNode**)malloc(k * sizeof(struct ListNode*));

    int len = 0;
    struct ListNode* cur = head;
    while (cur)
    {
        cur = cur->next;
        len++;
    }
    cur = head;

    int mod = len % k;
    int size = len / k;

    for (int i = 0; i < k; i++)
    {
        ret[i] = cur;

        if (cur)
        {
            int curlen = size + (mod-- > 0 ? 1 : 0);
            for (int j = 0; j < curlen - 1; j++)
                cur = cur->next;
            struct ListNode* tmp = cur->next;
            cur->next = NULL;
            cur = tmp;
        }
    }
    *returnSize = k;
    return ret;
}



/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head)
{
    if (head == NULL)
        return head;

    struct ListNode* slow = head;
    struct ListNode* fast = head->next;
    while (head && fast)
    {
        if (fast->val == slow->val)
        {
            slow->next = fast->next;
            free(fast);
            fast = slow->next;
        }
        else
        {
            slow = slow->next;
            fast = fast->next;
        }
    }
    return head;
}