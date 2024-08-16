#define _CRT_SECURE_NO_WARNINGS



/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeElements(struct ListNode* head, int val)
{
    struct ListNode* curhead = (struct ListNode*)malloc(sizeof(struct ListNode));
    curhead->next = head;
    struct ListNode* cur = curhead;
    while (cur->next)
    {
        if (cur->next->val == val)
        {
            cur->next = cur->next->next;
        }
        else
            cur = cur->next;
    }
    return curhead->next;
}



/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
void deleteNode(struct ListNode* node)
{
    struct ListNode* cur = node->next;
    node->val = cur->val;
    cur = cur->next;
    node->next = cur;
}