#include "stdio.h"
#include "string.h"

#define MaxSizeStack 120
#define MaxLen 100


typedef struct
{
    char buf[MaxSizeStack];

    int startElem[MaxLen];

    int len;
    int CallList;
}MyStack;

MyStack CreateStack()
{
    MyStack base;
    for(int i = 0; i < MaxSizeStack;i++){base.buf[i] = '\0';}
    base.len = 0;
    base.CallList = 0;
    return base;
}

int push(MyStack* stack, char value[])
{
    if (stack->len >= MaxSizeStack)
    {
        printf("stack overflow");
        return 0;
    }
    else
    {
        strcat(stack->buf + stack->len, value);

        size_t lenVal = strlen(value) + 1;
        stack->startElem[stack->CallList] = stack->len;

        stack->len +=  lenVal;
        stack->CallList++;
    }
    return 1;
}
void pop(MyStack* stack,char* res)
{

    for (int i = stack->startElem[stack->CallList - 1], j = 0;  i < stack->len; i++,j++)
    {
        res[j] = stack->buf[i];
        stack->buf[i] = '\0';
    }

    stack->len -= stack->len - stack->startElem[stack->CallList - 1];
    stack->startElem[stack->CallList - 1] = 0;
    stack->CallList -= 1;
}  

int isEmpty(MyStack* stack)
{
    if (stack->CallList)
        return 0;
    else
        return 1;

}


int peek(MyStack* stack,char* res)
{
    for (int i = stack->startElem[stack->CallList - 1], j = 0; i < stack->len; i++,j++)
        res[j] = stack->buf[i];
}
int main ()
{
    MyStack stack = CreateStack();
    push(&stack,"hello");
    push(&stack,"pidr");
    push(&stack,"bye");
    
    printf("%d",isEmpty(&stack));
    
    return 0;
}