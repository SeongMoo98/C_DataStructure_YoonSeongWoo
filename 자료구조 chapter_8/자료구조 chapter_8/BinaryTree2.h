#pragma once
#ifndef __BINARY_TREE2_H__
#define __BINARY_TREE2_H__

typedef int BTData;

typedef struct _btreeNode
{
	BTData data;
	struct _btreeNode* left;
	struct _btreeNode* right;
}BTreeNode;


BTreeNode* MakeBTreeNode(void);
BTData GetData(BTreeNode* bt);
void SetData(BTreeNode* bt, BTData data);


BTreeNode* GetLeftSubTree(BTreeNode* bt);
BTreeNode* GetRightSubTree(BTreeNode* bt);

void MakeLeftSubTree(BTreeNode* main, BTreeNode* sub);
void MakeRightSubTree(BTreeNode* main, BTreeNode* sub);

typedef void (*VisitFunPtr)(BTData data);

//������ȸ
void PreorderTraverse(BTreeNode* bt, VisitFunPtr action);
//������ȸ
void InorderTraverse(BTreeNode* bt, VisitFunPtr action);
//������ȸ
void PostorderTraverse(BTreeNode* bt, VisitFunPtr action);  







//���� 8-1
void DeleteTree(BTreeNode* bt);
#endif