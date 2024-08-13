#define _CRT_SECURE_NO_WARNINGS


typedef int STLDataType;

struct SListNode
{
    STLDataType val;
    struct SListNode* next;
};

typedef struct SListNode SLTNode;

typedef struct
{
    int size;
    SLTNode* head;
} MyLinkedList;

SLTNode* SListNodeCreat(STLDataType val)
{
    SLTNode* newnode = (SLTNode*)malloc(sizeof(SLTNode));
    newnode->val = val;
    newnode->next = NULL;

    return newnode;
}

MyLinkedList* myLinkedListCreate()
{
    MyLinkedList* obj = (MyLinkedList*)malloc(sizeof(MyLinkedList));
    obj->size = 0;
    obj->head = SListNodeCreat(0);

    return obj;
}

int myLinkedListGet(MyLinkedList* obj, int index)
{
    if (index < 0 || index >= obj->size)
        return -1;

    SLTNode* cur = obj->head;
    while (index != -1)
    {
        cur = cur->next;
        index--;
    }
    return cur->val;
}

void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val);

void myLinkedListAddAtHead(MyLinkedList* obj, int val)
{
    myLinkedListAddAtIndex(obj, 0, val);
}

void myLinkedListAddAtTail(MyLinkedList* obj, int val)
{
    myLinkedListAddAtIndex(obj, obj->size, val);
}

void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val)
{
    if (index > obj->size || index < 0)
        return;

    SLTNode* prev = obj->head;
    SLTNode* cur = SListNodeCreat(val);
    for (int i = 0; i < index; i++)
        prev = prev->next;
    cur->next = prev->next;
    prev->next = cur;
    obj->size++;
}

void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index)
{
    if (index >= obj->size || index < 0)
        return;

    SLTNode* prev = obj->head;
    SLTNode* cur = NULL;
    for (int i = 0; i < index; i++)
        prev = prev->next;
    cur = prev->next;
    prev->next = prev->next->next;

    free(cur);
    cur = NULL;
    obj->size--;
}

void myLinkedListFree(MyLinkedList* obj)
{
    SLTNode* cur = obj->head;
    SLTNode* tmp = NULL;

    while (obj->size != -1)
    {
        tmp = cur;
        cur = cur->next;
        free(tmp);
        tmp = NULL;

        obj->size--;
    }
    free(obj);
}