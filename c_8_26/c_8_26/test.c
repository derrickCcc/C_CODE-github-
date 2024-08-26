#define _CRT_SECURE_NO_WARNINGS


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* reverseKGroup(struct ListNode* head, int k)
{
    struct ListNode* dummyhead = malloc(sizeof(struct ListNode));
    dummyhead->next = head;
    struct ListNode* prev = dummyhead;
    struct ListNode* cur = prev->next;
    int cnt = 0;
    while (head)
    {
        head = head->next;
        cnt++;
    }

    if (cnt <= 1)
        return dummyhead->next;

    while (cnt >= k)
    {
        struct ListNode* pre = NULL;
        for (int i = 0; i < k; i++)
        {
            struct ListNode* tmp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = tmp;
        }
        prev->next->next = cur;
        struct ListNode* tail = prev->next;
        prev->next = pre;
        prev = tail;
        cnt -= k;
    }
    return dummyhead->next;
}