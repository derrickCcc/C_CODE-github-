#define _CRT_SECURE_NO_WARNINGS

//二叉树的前序遍历
void BinaryTreeInOrder(struct TreeNode* root, int* a, int* pi)
{
    if (root == NULL)
        return;

    a[(*pi)++] = root->val;
    BinaryTreeInOrder(root->left, a, pi);
    BinaryTreeInOrder(root->right, a, pi);
}

int* preorderTraversal(struct TreeNode* root, int* returnSize)
{
    int* ret = (int*)malloc(sizeof(int) * 100);
    if (ret == NULL)
    {
        perror("malloc fail");
        exit(-1);
    }

    int i = 0;
    BinaryTreeInOrder(root, ret, &i);

    *returnSize = i;
    return ret;
}

//101. 对称二叉树
bool _isSymmetric(struct TreeNode* root1, struct TreeNode* root2)
{
    if (root1 == NULL && root2 == NULL)
        return true;

    if (root1 == NULL || root2 == NULL)
        return false;

    if (root1->val != root2->val)
        return false;

    return  _isSymmetric(root1->left, root2->right)
        && _isSymmetric(root1->right, root2->left);
}

bool isSymmetric(struct TreeNode* root)
{
    if (root == NULL)
        return true;

    return _isSymmetric(root->left, root->right);

}

//572. 另一棵树的子树
bool isTheSameTree(struct TreeNode* root1, struct TreeNode* root2)
{
    if (root1 == NULL && root2 == NULL)
        return true;

    if (root1 == NULL || root2 == NULL)
        return false;

    if (root1->val != root2->val)
        return false;

    return isTheSameTree(root1->left, root2->left)
        && isTheSameTree(root1->right, root2->right);
}

bool isSubtree(struct TreeNode* root, struct TreeNode* subRoot)
{
    if (root == NULL)
        return false;

    if (isTheSameTree(root, subRoot))
        return true;

    return isSubtree(root->left, subRoot)
        || isSubtree(root->right, subRoot);
}

//KY11 二叉树遍历
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>

typedef char BTDataType;

typedef struct BinaryTreeNode
{
    BTDataType val;
    struct BinaryTreeNode* left;
    struct BinaryTreeNode* right;
}BTNode;

BTNode* BTreeCreat(BTDataType* a, int* pi)
{
    if (a[*pi] == '#')
    {
        (*pi)++;
        return NULL;
    }

    BTNode* root = (BTNode*)malloc(sizeof(BTNode));
    if (root == NULL)
    {
        perror("malloc fail");
        exit(-1);
    }
    root->val = a[(*pi)++];
    root->left = BTreeCreat(a, pi);
    root->right = BTreeCreat(a, pi);

    return root;
}

void BTInOrder(BTNode* root)
{
    if (root == NULL)
        return;

    BTInOrder(root->left);
    printf("%c ", root->val);
    BTInOrder(root->right);
}

int main()
{
    char a[100];
    for (int i = 0; i < 100; i++)
        scanf("%c", &a[i]);

    int i = 0;
    BTNode* root = BTreeCreat(a, &i);
    BTInOrder(root);

    return 0;
}

//965. 单值二叉树
bool isUnivalTree(struct TreeNode* root)
{
    if (root == NULL)
        return true;

    if (root->left && root->left->val != root->val)
        return false;

    if (root->right && root->right->val != root->val)
        return false;

    return isUnivalTree(root->left) && isUnivalTree(root->right);
}

//104. 二叉树的最大深度
int Max(int a, int b)
{
    if (a < b)
        return b;
    else
        return a;
}

int maxDepth(struct TreeNode* root)
{
    if (root == NULL)
        return 0;

    return Max(maxDepth(root->left), maxDepth(root->right)) + 1;
}

//226. 翻转二叉树
void Swap(struct TreeNode** root1, struct TreeNode** root2)
{
    struct TreeNode* tmp = *root1;
    *root1 = *root2;
    *root2 = tmp;
}

struct TreeNode* invertTree(struct TreeNode* root)
{
    if (root == NULL)
        return root;

    Swap(&root->left, &root->right);

    struct TreeNode* left = invertTree(root->left);
    struct TreeNode* right = invertTree(root->right);
    return root;
}

//100. 相同的树
bool isSameTree(struct TreeNode* p, struct TreeNode* q)
{
    if (p == NULL && q == NULL)
        return true;

    if (p == NULL || q == NULL)
        return false;

    if (p->val != q->val)
        return false;

    return isSameTree(p->left, q->left)
        && isSameTree(p->right, q->right);
}