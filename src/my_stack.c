#include "stdio.h"
#include "string.h"
#include "stdlib.h"

typedef struct{
    char* buf;
    int* beginningElem;
    int maxlen;
    int len;
    int CallList;
}MyStack;

MyStack CreateStack(int lenghbuf)
{
    MyStack base;
    base.maxlen = lenghbuf;
    base.buf = malloc(lenghbuf * sizeof(char));
    base.beginningElem = malloc(lenghbuf * sizeof(int));
    base.len = 0;
    base.CallList = 0;
    return base;
}

int push(MyStack* stack, char value[])
{
    if (stack->len >= stack->maxlen)
    {
        printf("stack overflow");
        stack->buf = realloc(stack->buf, stack->maxlen * sizeof(char) * 2);
        stack->beginningElem = realloc(stack->beginningElem, stack->maxlen * sizeof(int) * 2);
        stack->maxlen *= 2;
    }
        stack->beginningElem[stack->CallList] = stack->len;
        strcpy(stack->buf + stack->len, value);

        stack->len += strlen(value) + 1;
        stack->CallList++;

    return 1;
}


void pop(MyStack* stack,char* res)
{
    if (stack->CallList == 0){
        res[0] = '\0';
        return;
    }

    for (int i = stack->beginningElem[stack->CallList - 1], j = 0;  i < stack->len; i++,j++)
    {
        res[j] = stack->buf[i];
        stack->buf[i] = '\0';
    }

    stack->len = stack->beginningElem[stack->CallList - 1];
    stack->beginningElem[stack->CallList - 1] = 0;
    stack->CallList--;
}  

void peek(MyStack* stack,char* res)
{
    if (stack->CallList == 0) {
        res[0] = '\0';
        return;
    }

    int j = 0;
    for (int i = stack->beginningElem[stack->CallList - 1]; i < stack->len; i++,j++)
        res[j] = stack->buf[i];

    res[j++] = '\0';
}

int isEmpty(MyStack* stack)
{
    return stack->CallList == 0;
}

void freestack(MyStack* stack)
{
    if (stack->buf){
        free(stack->buf);
        stack->buf = NULL;
    }
    if (stack->beginningElem){
        free(stack->beginningElem);
        stack->beginningElem = NULL;
    }
}
