#include<string.h> 
#include<stdlib.h>
#include<ctype.h>
#include"LBStack.h"
#include"InfixToPostfix.h"

//Helper Function
//연산자의 우선순위에 따른 숫자 부여
int GetOpPrec(char op)
{
	switch (op)
	{
	case'*':
	case'/':
	{
		return 5;
	}
	case'+':
	case'-':
	{
		return 3;
	}
	case'(':
	{
		return 1;
	}
	}
	return -1;
}

//연산자의 우선순위 비교
int WhoPrecOp(char op1, char op2)
{
	int op1Prec = GetOpPrec(op1);
	int op2Prec = GetOpPrec(op2);

	if (op1Prec > op2Prec)
	{
		return 1;
	}
	else if (op1Prec < op2Prec)
	{
		return -1;
	}
	else
	{
		return 0;
	}
}

void ConvToRPNExp(char exp[])
{
	Stack stack;
	int expLen = strlen(exp);

	char* convExp = (char*)malloc(expLen + 1);

	int idx = 0;
	char tok, popOp;

	memset(convExp, 0, sizeof(char) * expLen + 1);
	StackInit(&stack);

	for (int i = 0; i < expLen; i++)
	{
		tok = exp[i];
		//숫자 일때
		if (isdigit(tok))
		{
			convExp[idx++] = tok;
		}
		//연산자 일떄
		else
		{
			switch (tok)
			{
			case'(':
			{
				SPush(&stack, tok);
				break;
			}
			case')': //닫는 괄호라면
			{
				while (1)
				{
					popOp = SPop(&stack); //스택에서 연산자를 꺼내어
					if (popOp == '(')	  //연산자 ( 를 만날때 까지
					{
						break;
					}
					convExp[idx++] = popOp; //배열convExp에 저장
				}
				break;
			}
			case'+':
			case'-':
			case'*':
			case'/':
			{
				while (!SIsEmpty(&stack) && WhoPrecOp(SPeek(&stack), tok) >= 0)
				{
					convExp[idx++] = SPop(&stack);
				}
				SPush(&stack, tok);
				break;
			}

			}
		}
	}
	
	//스택에 남아있는 모든 연산자를 이동한다
	while (!SIsEmpty(&stack))
	{
		convExp[idx++] = SPop(&stack);
	}
	strcpy_s(exp,expLen+1,convExp);
	free(convExp);
}