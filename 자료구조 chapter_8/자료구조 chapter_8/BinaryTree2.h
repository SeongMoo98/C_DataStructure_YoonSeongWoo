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

//전위순회
void PreorderTraverse(BTreeNode* bt, VisitFunPtr action);
//중위순회
void InorderTraverse(BTreeNode* bt, VisitFunPtr action);
//후위순회
void PostorderTraverse(BTreeNode* bt, VisitFunPtr action);  







//문제 8-1
void DeleteTree(BTreeNode* bt);
#endif