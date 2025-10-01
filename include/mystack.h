#ifndef MYSTACK_H
#define MYSTACK_H


typedef struct{
    char* buf;
    size_t* beginningElem;
    size_t maxlen;
    size_t len;
    size_t CallList;
}MyStack;

// create stack
MyStack CreateStack(size_t size);

// add elem
int push(MyStack* stack, void* data, size_t size);

// give elem
void pop(MyStack* stack, void* data, size_t size);

// check last elem
void peek(MyStack* stack,void* data,size_t size);

// check if the stack is empty
int isEmpty(MyStack* stack);

// free member
void freestack(MyStack* stack);


#endif