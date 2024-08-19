#define _CRT_SECURE_NO_WARNINGS


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* partition(struct ListNode* head, int x)
{
    struct ListNode* small = malloc(sizeof(struct ListNode));
    small->next = NULL;
    struct ListNode* large = malloc(sizeof(struct ListNode));
    large->next = NULL;
    struct ListNode* smallhead = small, * largehead = large;

    while (head)
    {
        if (head->val >= x)
        {
            large->next = head;
            large = large->next;
        }
        else
        {
            small->next = head;
            small = small->next;
        }
        head = head->next;
    }
    large->next = NULL;
    small->next = largehead->next;
    return smallhead->next;
}



/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* swapPairs(struct ListNode* head)
{
    struct ListNode dhead;
    dhead.next = head;
    struct ListNode* tmp = &dhead;

    while (tmp->next && tmp->next->next)
    {
        struct ListNode* n1 = tmp->next, * n2 = tmp->next->next;

        tmp->next = n2;
        n1->next = n2->next;
        n2->next = n1;
        tmp = n1;
    }
    return dhead.next;
}