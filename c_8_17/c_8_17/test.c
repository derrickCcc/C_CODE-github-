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
        struct ListNode* next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    return prev;
}




/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

//version one
struct ListNode* reverseList(struct ListNode* head)
{
    struct ListNode* prev = NULL;
    struct ListNode* cur = head;
    while (cur)
    {
        struct ListNode* next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    return prev;
}

struct ListNode* reverseBetween(struct ListNode* head, int left, int right)
{
    struct ListNode* Dhead = (struct ListNode*)malloc(sizeof(struct ListNode));
    Dhead->val = -1;
    Dhead->next = head;

    struct ListNode* prev = Dhead;
    struct ListNode* succ = Dhead;
    struct ListNode* leftNode = Dhead;
    struct ListNode* rightNode = Dhead;

    for (int i = 0; i < left - 1; i++)
        prev = prev->next;

    rightNode = prev;
    for (int i = 0; i < right - left + 1; i++)
        rightNode = rightNode->next;

    leftNode = prev->next;
    succ = rightNode->next;

    prev->next = NULL;
    rightNode->next = NULL;
    reverseList(leftNode);

    prev->next = rightNode;
    leftNode->next = succ;

    return Dhead->next;
}

//version two
struct ListNode* reverseBetween(struct ListNode* head, int left, int right) {
    // 因为头节点有可能发生变化，使用虚拟头节点可以避免复杂的分类讨论
    struct ListNode* dummyNode = malloc(sizeof(struct ListNode));
    dummyNode->val = -1;
    dummyNode->next = head;

    struct ListNode* pre = dummyNode;
    for (int i = 0; i < left - 1; i++) {
        pre = pre->next;
    }
    struct ListNode* cur = pre->next;
    struct ListNode* next;
    for (int i = 0; i < right - left; i++) {
        next = cur->next;
        cur->next = next->next;
        next->next = pre->next;
        pre->next = next;
    }
    return dummyNode->next;
}
