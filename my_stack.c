#include "stdio.h"
#include "string.h"

#define MaxSizeStack 120
#define MaxLen 100
typedef struct
{
    char buf[MaxSizeStack];
    int LenElem[MaxLen];
    int wereFIRST;
    int CallList;
}MyStack;

MyStack CreateStack()
{
    MyStack base;
    base.wereFIRST = 0;
    base.CallList = 0;
    return base;
}

int push(MyStack* stack, char value[])
{
    if (stack->wereFIRST >= MaxSizeStack)
    {
        printf("stack overflow");
        return 0;
    }
    else
    {
        strcat(stack->buf + stack->wereFIRST, value);
        stack->LenElem[stack->CallList] = strlen(value) + 1;
        stack->wereFIRST += strlen(value) + 1;
        stack->CallList++;
    }
    return 1;
}
void pop(MyStack* stack,char* res)
{
    int start = 0;
    for (int i = 0; i < stack->CallList - 1; i++)
        start += stack->LenElem[i];
    
    char _char = stack->buf[start];
    for (int i = 0;  _char != '\0';i++)
    {
        _char = stack->buf[start++];
        res[i] = _char;
    }
       
}  
int main ()
{
    MyStack stack = CreateStack();
    push(&stack,"hello");
    push(&stack,"pidr");
    push(&stack,"bye");
    char res[60];
    pop(&stack, res);
    printf("%s", res);
    
    return 0;
}