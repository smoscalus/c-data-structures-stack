#include "stdio.h"
#include "string.h"
#include "stdlib.h"

typedef struct{
    char* buf;
    size_t* beginningElem;
    size_t maxlen;
    size_t len;
    size_t CallList;
}MyStack;

MyStack CreateStack(size_t size)
{
    MyStack base;
    base.maxlen = size;
    base.buf = malloc(size);
    base.beginningElem = malloc(size * sizeof(int));
    base.len = 0;
    base.CallList = 0;
    return base;
}

int push(MyStack* stack, void* data, size_t size)
{
    if (stack->len + size >= stack->maxlen)
    {
        stack->maxlen *= 2;

        char* buf = realloc(stack->buf, stack->maxlen * sizeof(char));
        size_t* beginningElem = realloc(stack->beginningElem, stack->maxlen * sizeof(int));

        if (!buf || !beginningElem){
            printf("realloc failed\n");
            exit(1);
        }

        stack->buf = buf;
        stack->beginningElem = beginningElem;
    }

        stack->beginningElem[stack->CallList] = stack->len;
        memcpy(stack->buf + stack->len, data, size);

        stack->len += size; 
        stack->CallList++;

    return 1;
}


void pop(MyStack* stack, void* data, size_t size,size_t IsStr)
{
    if (stack->CallList == 0)
        return;

    int i = stack->beginningElem[stack->CallList - 1];   
    
    memcpy(data,stack->buf + i, size);   
    stack->len = i;
    stack->CallList--;

}  

void peek(MyStack* stack,void* data,size_t size)
{
    if (stack->CallList == 0)
        return;
    int i = stack->beginningElem[stack->CallList - 1];
    memcpy(data,stack->buf + i,size);   
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
