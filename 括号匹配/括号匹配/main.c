#include <string.h>
#include "SqStack.h"

int main()
{
	printf("--Parentheses Match--\n");
	char pare[MAXSIZE];
	char p[16] = "\0";
	do {
        printf("\nInput a string characters which includes () [] {} <> :\n");
        scanf("%s", pare);
        ParenMatch(pare);
        printf("\nY/yes to continue, other command to quit: ");
        scanf("%s", p);
	} while (strcmp(p,"Y")==0 || strcmp(p,"yes")==0 || strcmp(p,"y")==0);
    return 0;
}
