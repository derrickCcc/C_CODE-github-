#define _CRT_SECURE_NO_WARNINGS
#include "BTree.h"
#include "Queue.h"

// 通过前序遍历的数组"ABD##E#H##CF##G##"构建二叉树
BTNode* BinaryTreeCreate(BTDataType* a, int* pi)
{
	if (a[*pi] == '#')
	{
		(*pi)++;
		return NULL;
	}

	BTNode* root = (BTNode*)malloc(sizeof(BTNode));
	if (root == NULL)
	{
		perror("malloc fail!");
		exit(-1);
	}
	root->val = a[(*pi)++];
	root->left = BinaryTreeCreate(a, pi);
	root->right = BinaryTreeCreate(a, pi);

	return root;
}

// 二叉树销毁
void BinaryTreeDestory(BTNode* root)
{
	if (root == NULL)
		return;

	BinaryTreeDestory(root->left);
	BinaryTreeDestory(root->right);
	free(root);
	root = NULL;
}

// 二叉树节点个数
int BinaryTreeSize(BTNode* root)
{
	if (root == NULL)
		return 0;

	return BinaryTreeSize(root->left) 
		 + BinaryTreeSize(root->right) 
		 + 1;
}

// 二叉树叶子节点个数
int BinaryTreeLeafSize(BTNode* root)
{
	if (root == NULL)
		return 0;

	if (root->left == NULL && root->right == NULL)
		return 1;

	return BinaryTreeLeafSize(root->left) 
		 + BinaryTreeLeafSize(root->right);
}

// 二叉树第k层节点个数
int BinaryTreeLevelKSize(BTNode* root, int k)
{
	assert(k > 0);

	if (root == NULL)
		return 0;

	if (k == 1)
		return 1;

	return BinaryTreeLevelKSize(root->left, k - 1) 
		 + BinaryTreeLevelKSize(root->right, k - 1);

}

// 二叉树查找值为x的节点
BTNode* BinaryTreeFind(BTNode* root, BTDataType x)
{
	if (root == NULL)
		return NULL;

	if (root->val == x)
		return root;

	BTNode* left = BinaryTreeFind(root->left, x);
	if (left)
		return left;

	return BinaryTreeFind(root->right, x);
}

// 二叉树前序遍历 
void BinaryTreePrevOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("# ");
		return;
	}

	printf("%c ", root->val);
	BinaryTreePrevOrder(root->left);
	BinaryTreePrevOrder(root->right);
}

// 二叉树中序遍历
void BinaryTreeInOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("# ");
		return;
	}

	BinaryTreePrevOrder(root->left);
	printf("%c ", root->val);
	BinaryTreePrevOrder(root->right);
}

// 二叉树后序遍历
void BinaryTreePostOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("# ");
		return;
	}

	BinaryTreePrevOrder(root->left);
	BinaryTreePrevOrder(root->right);
	printf("%c ", root->val);
}

// 层序遍历
void BinaryTreeLevelOrder(BTNode* root)
{

	Queue pq;
	QueueInit(&pq);
	if(root)
		QueuePush(&pq, root);
	while (!QueueEmpty(&pq))
	{
		BTNode* cur = QueueFront(&pq);
		QueuePop(&pq);
		printf("%c ", cur->val);

		if(cur->left)
			QueuePush(&pq, cur->left);
		if(cur->right)
			QueuePush(&pq, cur->right);

	}

	QueueDestroy(&pq);
}

// 判断二叉树是否是完全二叉树
int BinaryTreeComplete(BTNode* root)
{
	Queue pq;
	QueueInit(&pq);
	if (root)
		QueuePush(&pq, root);

	while (!QueueEmpty(&pq))
	{
		BTNode* head = QueueFront(&pq);
		QueuePop(&pq);

		if (head)
		{
			QueuePush(&pq, head->left);
			QueuePush(&pq, head->right);
		}
		else
			break;
	}

	while (!QueueEmpty(&pq))
	{
		BTNode* head = QueueFront(&pq);
		QueuePop(&pq);

		if (head)
		{
			QueueDestroy(&pq);
			return 0;
		}
	}

	QueueDestroy(&pq);
	return 1;
}