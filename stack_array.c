#include <stdio.h>
#define STACK_SIZE 3

typedef struct{
    int data[STACK_SIZE];
    int top;
}stack;

void reset(stack *stk){
    stk->top = -1;
}

void push(stack *stk,int c){
    if(stk->top == STACK_SIZE-1)
        printf("\nStack is full\n");
    else{
        stk->top++;
        stk->data[stk->top] = c;
    }
}

int pop(stack *stk){
    if(stk->top == -1){
        printf("\nstack is empty\t");
        return -100;
    }
    else{
        int x = stk->data[stk->top];
        stk->top--;
        return x;
    }
}

main(){
    stack n;
    reset(&n);
    push(&n,6);
    push(&n,9);
    push(&n,7);
    push(&n,66);
    printf("%d\t",pop(&n));
    printf("%d\t",pop(&n));
    printf("%d\t",pop(&n));
    printf("%d",pop(&n));
}
