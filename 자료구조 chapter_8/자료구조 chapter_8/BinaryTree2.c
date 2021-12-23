#include<stdio.h>
#include<stdlib.h>
#include"BinaryTree2.h"

BTreeNode* MakeBTreeNode(void)
{
	BTreeNode* nd = (BTreeNode*)malloc(sizeof(BTreeNode));
	nd->left = NULL;
	nd->right = NULL;
	return nd;
}
BTData GetData(BTreeNode* bt)
{
	return bt->data;
}
void SetData(BTreeNode* bt, BTData data)
{
	bt->data = data;
}

BTreeNode* GetLeftSubTree(BTreeNode* bt)
{
	return bt->left;
}
BTreeNode* GetRightSubTree(BTreeNode* bt)
{
	return bt->right;
}

void MakeLeftSubTree(BTreeNode* main, BTreeNode* sub)
{
	//main->left가 단말노드가 아니라면 문제가 발생
	//====> "순회"가 필요하다
	if (main->left != NULL)
	{
		free(main->left);
	}
	main->left = sub;
}
void MakeRightSubTree(BTreeNode* main, BTreeNode* sub)
{
	if (main->right != NULL)
	{
		free(main->right);
	}
	main->right = sub;
}

//전위 순회
void PreorderTraverse(BTreeNode* bt, VisitFunPtr action)
{
	if (bt == NULL)
	{
		return;
	}

	//노드의 방문
	action(bt->data);
	PreorderTraverse(bt->left, action);
	PreorderTraverse(bt->right, action);

}

//중위 순회
void InorderTraverse(BTreeNode* bt, VisitFunPtr action)
{
	if (bt == NULL)
	{
		return;
	}
	InorderTraverse(bt->left,action);
	action(bt->data);
	InorderTraverse(bt->right,action);
}
//후위순회
void PostorderTraverse(BTreeNode* bt, VisitFunPtr action)
{
	if (bt == NULL)
	{
		return;
	}

	PostorderTraverse(bt->left, action);
	PostorderTraverse(bt->right, action);
	action(bt->data);
}




//문제 8-1
void DeleteTree(BTreeNode* bt)
{
	if (bt == NULL)
	{
		return;
	}
	DeleteTree(bt->left);
	DeleteTree(bt->right);

	printf("del tree data : %d \n", bt->data);
	free(bt);
}
