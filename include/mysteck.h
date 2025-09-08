#ifndef MYSTECK_H
#define MYSTECK_H


typedef struct {
    char* buf;
    int* beginningElem;
    int maxlen;
    int len;
    int CallList;
}MyStack;

// create stack
MyStack CreateStack(int lenghbuf);

// add elem
int push(MyStack* stack, char value[]);

// give elem
void pop(MyStack* stack,char* res);

// see on elem
void peek(MyStack* stack,char* res);

// check if the stack is empty
int isEmpty(MyStack* stack);

// free member
void freestack(MyStack* stack);


#endif