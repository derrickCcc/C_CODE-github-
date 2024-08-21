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
    struct ListNode* prev = NULL, * cur = head;
    while (cur)
    {
        struct ListNode* tmp = cur->next;
        cur->next = prev;
        prev = cur;
        cur = tmp;
    }
    return prev;
}

struct ListNode* endOfFirstHalf(struct ListNode* head)
{
    struct ListNode* fast = head;
    struct ListNode* slow = head;
    while (fast->next && fast->next->next)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

bool isPalindrome(struct ListNode* head)
{
    if (head == NULL)
        return head;

    struct ListNode* end1 = endOfFirstHalf(head);
    struct ListNode* head2 = reverseList(end1->next);
    struct ListNode* start1 = head;
    struct ListNode* start2 = head2;
    bool ret = true;
    while (ret && start2)
    {
        if (start1->val != start2->val)
            ret = false;
        start1 = start1->next;
        start2 = start2->next;
    }

    end1->next = reverseList(start2);
    return ret;
}