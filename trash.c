#include "stdio.h"



int main()
{

    int a, b, d;
    int* _a = &a;
    int* _b = &b;
    int* _d = &d;

    printf("%d, %d, %d \n %d, %d, %d",a,b,d,_a,_b,_d);
}