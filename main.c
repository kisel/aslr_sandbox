#include "stdio.h"

void func1() {
    printf("Hello from func1\n");
}

void func2() {
    printf("Hello from func2\n");
}

void main(int argc, char **argv) {
    int x = 0;
    printf("Hello from main\n");
    printf("func1 addr: %p\n", func1);
    printf("func2 addr: %p\n", func2);
    printf("addr of variable in main: %p\n", &x);

    if (argc >= 2) {
        // has any args
        void *ptr = 0;
        scanf("%p", &ptr);
        printf("---executing %p as void*() func\n", (void*)ptr);
        ((void (*)())(ptr))();
        printf("---done\n");
    }
}

