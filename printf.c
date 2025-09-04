#include <stdio.h>
#include <assert.h>

int add(int a, int b) {
    return a + b;
}

void test_add() {
    assert(add(2, 3) == 5);
    assert(add(-1, 1) == 0);
    assert(add(0, 0) == 0);
    printf("test_add passed!\n");
}

int main() {
    test_add();
    printf("All tests passed!\n");
    return 0;
}