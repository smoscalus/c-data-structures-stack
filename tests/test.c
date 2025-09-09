#include "stdio.h"
#include "../include/mystack.h"
#include "string.h"
#include "stdlib.h"

#define TEST_EQ_STR(expected,actual){\
        if (strcmp(expected,actual) != 0){ \
            printf ("[FAIL] %s:%d: expected %s, got %s\n",  __FILE__, __LINE__, (expected), (actual));\
            return 1;\
        }\
        else { \
            printf("[PASS] %s:%d\n", __FILE__, __LINE__); \
        } \
    }
#define TEST_EQ_int(expected,actual){\
        if (expected != actual){ \
            printf ("[FAIL] %s:%d: expected %d, got %d\n",  __FILE__, __LINE__, (expected), (actual));\
            return 1;\
        }\
        else { \
            printf("[PASS] %s:%d\n", __FILE__, __LINE__); \
        } \
    }

int test_push_pop(){
    MyStack s = CreateStack(10);
    push(&s, "hello");
    char res[10];
    pop(&s, res);
    TEST_EQ_STR("hello", res);
    return 0;
}

int test_peek(){
    MyStack s = CreateStack(10);

    push(&s, "hello");

    char res[10];
    peek(&s,res);
    TEST_EQ_STR("hello", res);
    pop(&s, res);

    peek(&s,res);
    TEST_EQ_STR("", res);
    return 0;
}

int test_isEmpty(){
    MyStack s = CreateStack(10);
    push(&s, "hello");
    TEST_EQ_int(0,isEmpty(&s));

    char res[10];
    pop(&s,res);

    TEST_EQ_int(1,isEmpty(&s));
    return 0;
}


int test_freestack()
{
    MyStack s;

    s.beginningElem = malloc(sizeof(int) * 10);
    s.buf = malloc(sizeof(char) * 10);

    freestack(&s);


    if(s.beginningElem != NULL || s.buf != NULL){
        printf("[WARN] pointers not null after free\n");
    }    

    printf("[PASS] freestack test ran \n");
    return 0;
}


int main() {
    test_peek();
    test_isEmpty();
    test_push_pop();
    test_freestack();
    return 0;
}