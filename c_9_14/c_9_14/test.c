#define _CRT_SECURE_NO_WARNINGS
#include "BTree.h"
#include "Queue.h"

void test1()
{
	//char a[18] = { 'A','B','D','#','#','E','#','H','#','#','C','F','#','#','G','#','#' };
	char a[18] = "ABD##E#H##CF##G##";
	int i = 0;
	BTNode* root = BinaryTreeCreate(&a, &i);
	int size = BinaryTreeSize(root);
	int leafsize = BinaryTreeLeafSize(root);
	printf("i = %d\n", i);
	printf("size = %d\n", size);
	printf("leafsize = %d\n", leafsize);

	int klevelsize = BinaryTreeLevelKSize(root, 3);
	printf("klsize = %d\n", klevelsize);

	BTNode* BTF = BinaryTreeFind(root, 'B');
	printf("char = %c\n", BTF->val);

	BinaryTreePrevOrder(root);
	printf("\n");
	BinaryTreeInOrder(root);
	printf("\n");
	BinaryTreePostOrder(root);
	printf("\n");
	BinaryTreeLevelOrder(root);
	printf("\n");
	int flag = BinaryTreeComplete(root);
	if (flag)
		printf("是完全二叉树！\n");
	else
		printf("不是完全二叉树！\n");

	BinaryTreeDestory(root);
}

int main()
{
	test1();
	return 0;
}