#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#include"ExpressionTree.h"
#include"ListBaseStack.h"

//함수 포인터를 이용해 기능 설정
//VisitFuncPtr형 함수
void ShowNodeData(BTData data)
{
	if (0 <= data && data <= 9)
	{
		//피연산자 출력
		printf("%d ", data);
	}
	else
	{
		//연산자 출력
		printf("%c ", data);
	}
}


//수식트리 구성
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
//수식트리 계산
int EvaluateExpTree(BTreeNode* bt)
{
	int op1, op2;

	//bt가 단말노드라면 그 노드의 피연산자의 값 반환
	if (GetLeftSubTree(bt) == NULL && GetRightSubTree(bt) == NULL)
	{
		return GetData(bt);
	}
	//피연산자들
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


//전위표기법 기반 출력
void ShowPrefixTypeExp(BTreeNode* bt)
{
	PreorderTraverse(bt, ShowNodeData);
}
////중위표기법 기반 출력
//void ShowInfixTypeExp(BTreeNode* bt)
//{
//	InorderTraverse(bt, ShowNodeData);
//}
//후위표기법 기반 출력
void ShowPostfixTypeExp(BTreeNode* bt)
{
	PostorderTraverse(bt, ShowNodeData);
}


//문제 8-2
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