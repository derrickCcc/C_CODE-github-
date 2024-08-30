#define _CRT_SECURE_NO_WARNINGS

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2)
{
    if (list1 == NULL)
        return list2;
    if (list2 == NULL)
        return list1;

    struct ListNode* cur = malloc(sizeof(struct ListNode));
    struct ListNode* head = cur;

    while (list1 && list2)
    {
        if (list1->val <= list2->val)
        {
            cur->next = list1;
            list1 = list1->next;
            cur = cur->next;
        }
        else
        {
            cur->next = list2;
            list2 = list2->next;
            cur = cur->next;
        }
    }
    if (list1)
        cur->next = list1;
    else
        cur->next = list2;

    return head->next;
}




/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2)
{
    if (list1 == NULL)
        return list2;
    if (list2 == NULL)
        return list1;

    struct ListNode* ans;
    if (list1->val <= list2->val)
    {
        ans = list1;
        ans->next = mergeTwoLists(list1->next, list2);
    }
    else
    {
        ans = list2;
        ans->next = mergeTwoLists(list1, list2->next);
    }

    return ans;
}

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize)
{
    if (!listsSize)
        return NULL;

    struct ListNode* head = NULL;
    for (int i = 0; i < listsSize; i++)
        head = mergeTwoLists(head, lists[i]);

    return head;
}