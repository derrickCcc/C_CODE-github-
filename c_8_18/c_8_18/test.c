#define _CRT_SECURE_NO_WARNINGS


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* oddEvenList(struct ListNode* head)
{
    if (head == NULL)
        return head;

    struct ListNode* cur = head->next;
    struct ListNode* prev = head;
    struct ListNode* dummyhead = head->next;
    int i = 1;
    while (cur && cur->next)
    {
        prev->next = cur->next;
        prev = prev->next;
        cur->next = prev->next;
        cur = cur->next;
    }
    prev->next = dummyhead;
    return head;
}


