#include "ParenMatch.h"
#include <string.h>

void FilterParen(char pm[])     //¹ıÂËº¯Êı
{
    char *p = pm;
    for (int i=0; pm[i]!='\0'; i++)
    {
        if (   pm[i]=='(' || pm[i]==')'
            || pm[i]=='[' || pm[i]==']'
            || pm[i]=='{' || pm[i]=='}'
            || pm[i]=='<' || pm[i]=='>')
                *(p++) = pm[i];
    }
	*p = '\0';
}

char ParenTrans(char p)         //×ª»»¶ÔÓ¦À¨ºÅ
{
    switch (p)
	{
		case ')': return '(';
		case ']': return '[';
		case '}': return '{';
		case '>': return '<';
		default : return 0;
	}
}

void ParenMatch(char pm[])     //À¨ºÅÆ¥Åä
{
	SqStack P, *S = &P;
    Stack_Init(S);
    FilterParen(pm);
	printf("After filter: %s\n", pm);
    for (int i=0; pm[i]!='\0'; i++)
    {
        if (pm[i]=='(' || pm[i]=='[' || pm[i]=='{' || pm[i]=='<')
            Stack_Push(S,pm[i]);
		else if (Stack_isEmpty(S) == TRUE)
		{
			printf(" ! %c\n", pm[i]);
			printf("Parentheses does not match: Stack is empty.\n");
			return;
		}
        else if (Stack_Top(S) == ParenTrans(pm[i]))
			printf("%c%c", Stack_Pop(S), pm[i]);
		else
		{
			printf(" ! %c%c\n", Stack_Pop(S), pm[i]);
			printf("Parentheses does not match.\n");
			return;
		}
    }
	if (Stack_isEmpty(S) == FALSE)
	{
		printf(" ! %c\n", Stack_Pop(S));
		printf("Parentheses does not match!\n");
	}
	else
	    printf("\nAll matched!\n");
}
