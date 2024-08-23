#define _CRT_SECURE_NO_WARNINGS

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* insertionSortList(struct ListNode* head)
{
    if (head == NULL)
        return head;

    struct ListNode* dhead = malloc(sizeof(struct ListNode));
    dhead->next = head;

    struct ListNode* end = head;
    struct ListNode* cur = head->next;
    while (cur)
    {
        if (end->val <= cur->val)
        {
            end = end->next;
        }
        else
        {
            struct ListNode* prev = dhead;
            while (prev->next->val <= cur->val)
                prev = prev->next;
            end->next = cur->next;
            cur->next = prev->next;
            prev->next = cur;
        }
        cur = end->next;
    }
    return dhead->next;
}