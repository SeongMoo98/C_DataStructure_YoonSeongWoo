#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#include"ExpressionTree.h"
#include"ListBaseStack.h"

//�Լ� �����͸� �̿��� ��� ����
//VisitFuncPtr�� �Լ�
void ShowNodeData(BTData data)
{
	if (0 <= data && data <= 9)
	{
		//�ǿ����� ���
		printf("%d ", data);
	}
	else
	{
		//������ ���
		printf("%c ", data);
	}
}


//����Ʈ�� ����
BTreeNode* MakeExpTree(char exp[])
{
	Stack stack;
	BTreeNode* pnode;
	StackInit(&stack);

	int expLen = strlen(exp);
	for (int i = 0; i < expLen; i++)
	{
		pnode = MakeBTreeNode();

		if (isdigit(exp[i]))
		{
			SetData(pnode, exp[i]-'0');
		}
		else
		{
			MakeRightSubTree(pnode, SPop(&stack));
			MakeLeftSubTree(pnode, SPop(&stack));
			SetData(pnode, exp[i]);
		}
		SPush(&stack, pnode);

	}

	return SPop(&stack);

}
//����Ʈ�� ���
int EvaluateExpTree(BTreeNode* bt)
{
	int op1, op2;

	//bt�� �ܸ������ �� ����� �ǿ������� �� ��ȯ
	if (GetLeftSubTree(bt) == NULL && GetRightSubTree(bt) == NULL)
	{
		return GetData(bt);
	}
	//�ǿ����ڵ�
	op1 = EvaluateExpTree(GetLeftSubTree(bt));
	op2 = EvaluateExpTree(GetRightSubTree(bt));

	switch (GetData(bt))
	{
	case '+':
	{
		return op1 + op2;
	}
	case '-':
	{
		return op1 - op2;
	}
	case '*':
	{
		return op1 * op2;
	}
	case '/':
	{
		return op1 / op2;
	}
	}

	return 0;
}


//����ǥ��� ��� ���
void ShowPrefixTypeExp(BTreeNode* bt)
{
	PreorderTraverse(bt, ShowNodeData);
}
////����ǥ��� ��� ���
//void ShowInfixTypeExp(BTreeNode* bt)
//{
//	InorderTraverse(bt, ShowNodeData);
//}
//����ǥ��� ��� ���
void ShowPostfixTypeExp(BTreeNode* bt)
{
	PostorderTraverse(bt, ShowNodeData);
}


//���� 8-2
void ShowInfixTypeExp(BTreeNode* bt)
{
	if (bt == NULL)
	{
		return;
	}

	if (bt->left != NULL && bt->right != NULL)
	{
		printf(" ( ");
	}
	
	ShowInfixTypeExp(bt->left);
	ShowNodeData(bt->data);
	ShowInfixTypeExp(bt->right);
	
	if (bt->left != NULL || bt->right != NULL)
	{
		printf(" ) ");
	}
}