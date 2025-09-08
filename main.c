#include "stdio.h"
#include "include/mystack.h"


int main()
{
    MyStack s = CreateStack(60);
    
    printf("%d",isEmpty(&s));

    push(&s, "Hello");
    push(&s, "world");

    printf("%d",isEmpty(&s));
    
    char res[60];
    peek(&s, res);
    printf("%s",res);

    pop(&s, res);
    printf("%s",res);

    peek(&s, res);
    printf("%s",res);

    pop(&s, res);
    printf("%s",res);


    freestack(&s);
    return 0;
}