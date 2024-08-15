#define _CRT_SECURE_NO_WARNINGS

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */



typedef struct
{
    struct ListNode* head;
} Solution;


Solution* solutionCreate(struct ListNode* head)
{
    Solution* obj = (Solution*)malloc(sizeof(Solution));
    assert(obj);

    obj->head = head;
    return obj;
}

int solutionGetRandom(Solution* obj)
{
    int ans = 0;
    int i = 1;
    struct ListNode* cur = obj->head;
    while (cur)
    {
        if (rand() % i == 0)
            ans = cur->val;

        cur = cur->next;
        i++;
    }
    return ans;
}

void solutionFree(Solution* obj)
{
    free(obj);
    obj = NULL;
}

/**
 * Your Solution struct will be instantiated and called as such:
 * Solution* obj = solutionCreate(head);
 * int param_1 = solutionGetRandom(obj);

 * solutionFree(obj);
*/