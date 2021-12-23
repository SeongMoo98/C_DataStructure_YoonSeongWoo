#include<string.h>
#include<stdlib.h>
#include"InfixCalculator.h"
#include"InfixToPostfix.h" //ConvToRPNExp를 위해
#include"PostCalculator.h" //EvalRPNExp를 위해

int EvalInfixExp(char exp[])
{
	int len = strlen(exp);
	int ret;
	char* expcpy = (char*)malloc(sizeof(len + 1));
	strcpy_s(expcpy, len + 1, exp);

	ConvToRPNExp(expcpy);
	ret = EvalRPNExp(expcpy);

	free(expcpy);
	return ret;
}