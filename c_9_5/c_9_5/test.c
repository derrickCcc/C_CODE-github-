#define _CRT_SECURE_NO_WARNINGS



typedef int STDataType;

typedef struct
{
    STDataType* data;
    int top;
    int maxSize;
} CustomStack;


CustomStack* customStackCreate(int maxSize)
{
    CustomStack* obj = (CustomStack*)malloc(sizeof(CustomStack));
    obj->data = (STDataType*)malloc(maxSize * sizeof(STDataType));
    obj->top = -1;
    obj->maxSize = maxSize;

    return obj;
}

void customStackPush(CustomStack* obj, int x)
{
    if (obj->top == obj->maxSize - 1)
        return;
    obj->top++;
    obj->data[obj->top] = x;
}

int customStackPop(CustomStack* obj)
{
    if (obj->top == -1)
        return -1;
    return obj->data[obj->top--];
}

void customStackIncrement(CustomStack* obj, int k, int val)
{
    if (k >= obj->top + 1)
        for (int i = 0; i <= obj->top; i++)
            obj->data[i] += val;
    else
        for (int i = 0; i < k; i++)
            obj->data[i] += val;
}

void customStackFree(CustomStack* obj)
{
    free(obj->data);
    free(obj);
}

/**
 * Your CustomStack struct will be instantiated and called as such:
 * CustomStack* obj = customStackCreate(maxSize);
 * customStackPush(obj, x);

 * int param_2 = customStackPop(obj);

 * customStackIncrement(obj, k, val);

 * customStackFree(obj);
*/