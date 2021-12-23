#pragma once
#ifndef __EXPRESSION_TREE_H__
#define __EXPRESSION_TREE_H__

#include"BinaryTree2.h"

//����Ʈ�� ����
BTreeNode* MakeExpTree(char exp[]);
//����Ʈ�� ���
int EvaluateExpTree(BTreeNode* bt);


//����ǥ��� ��� ���
void ShowPrefixTypeExp(BTreeNode* bt);
//����ǥ��� ��� ���
void ShowInfixTypeExp(BTreeNode* bt);
//����ǥ��� ��� ���
void ShowPostfixTypeExp(BTreeNode* bt);
#endif
