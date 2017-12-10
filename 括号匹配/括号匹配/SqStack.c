#include "SqStack.h"

void Stack_Init(SqStack *S)
{
    S->top = -1;
}

void Stack_Push(SqStack *S, datatype e)
{
    if (Stack_isFull(S) == TRUE)
    {
        printf("Stack is full!\n");
        return;
    }
    S->data[++(S->top)] = e;
}

datatype Stack_Pop(SqStack *S)
{
    if (Stack_isEmpty(S) == TRUE)
    {
        printf("Stack is empty!\n");
        return 0;
    }
    return S->data[S->top--];
}

datatype Stack_Top(SqStack *S)
{
    if (Stack_isEmpty(S) == TRUE)
    {
        printf("Stack is empty!\n");
        return 0;
    }
    return S->data[S->top];
}

int Stack_Size(SqStack *S)
{
    return S->top+1;
}

int Stack_isFull(SqStack *S)
{
    if (S->top+1 >= MAXSIZE)
        return TRUE;
    return FALSE;
}

int Stack_isEmpty(SqStack *S)
{
    if (S->top < 0)
        return TRUE;
    return FALSE;
}
