#ifndef SQSTACK_H_
#define SQSTACK_H_

#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 50
#define TRUE 1
#define FALSE 0

typedef char datatype;
typedef struct sqstack
{
    datatype data[MAXSIZE];
    int top;
} SqStack;

void Stack_Init(SqStack *S);
void Stack_Push(SqStack *S, datatype e);
datatype Stack_Pop(SqStack *S);
datatype Stack_Top(SqStack *S);
int Stack_Size(SqStack *S);
int Stack_isFull(SqStack *S);
int Stack_isEmpty(SqStack *S);


#endif // !SQSTACK_H_
