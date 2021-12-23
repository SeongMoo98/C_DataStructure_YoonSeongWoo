#include<string.h>
#include<ctype.h>
#include"LBStack.h"
#include"PostCalculator.h"


int EvalRPNExp(char exp[])
{
	Stack stack;
	StackInit(&stack);

	int expLen = strlen(exp);
	char tok, op1, op2;

	for (int i = 0; i < expLen; i++)
	{
		tok = exp[i];
		if (isdigit(tok))
		{
			//스택에 숫자로 변환해서 저장
			SPush(&stack,tok-'0');   
			break;
		}
		else
		{
			op2 = SPop(&stack);
			op1 = SPop(&stack);
			switch (tok)
			{
			case'+':
			{
				SPush(&stack, op1 + op2);
				break;
			}
			case'-':
			{
				SPush(&stack, op1 - op2);
				break;
			}
			case'*':
			{
				SPush(&stack, op1 * op2);
				break;
			}
			case'/':
			{
				SPush(&stack, op1 / op2);
				break;
			}
			}
		}
	}
	return SPop(&stack);
}