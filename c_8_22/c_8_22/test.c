#define _CRT_SECURE_NO_WARNINGS


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* reverseList(struct ListNode* head)
{
    struct ListNode* prev = NULL;
    struct ListNode* cur = head;
    while (cur)
    {
        struct ListNode* tmp = cur->next;
        cur->next = prev;
        prev = cur;
        cur = tmp;
    }
    return prev;
}

struct ListNode* middleNode(struct ListNode* head)
{
    struct ListNode* slow = head;
    struct ListNode* fast = head;
    while (fast->next && fast->next->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

void mergeList(struct ListNode* h1, struct ListNode* h2)
{
    struct ListNode* tmp1 = NULL;
    struct ListNode* tmp2 = NULL;

    while (h2)
    {
        tmp1 = h1->next;
        tmp2 = h2->next;

        h1->next = h2;
        h2->next = tmp1;
        h1 = tmp1;
        h2 = tmp2;
    }
}

void reorderList(struct ListNode* head)
{
    if (head == NULL)
        return;

    struct ListNode* end1 = middleNode(head);
    struct ListNode* head2 = reverseList(end1->next);
    end1->next = NULL;

    struct ListNode* cur = head;
    struct ListNode* tmp = head2;
    mergeList(cur, tmp);
}