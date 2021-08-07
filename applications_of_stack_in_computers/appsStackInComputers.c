#include <stdio.h>
#include <stdlib.h>
#define STACK_SIZE 100

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

int main(){
    stack n;
    char key;
    reset(&n);
    FILE *fptr;
    if ( ( fptr = fopen("code.txt","r") ) == NULL){
        printf("File can not opened\n");
        exit(1);
    }
    else{
        while( !feof(fptr)){
            key = getc(fptr);
            switch(key){
                case '(':
                    push(&n,key);
                    break;

                case '{':
                    push(&n,key);
                    break;

                case '[':
                    push(&n,key);
                    break;

                case ')':
                    if(pop(&n) == '(')
                        continue;
                    else{
                        printf("\n Error for ()");
                        exit(1);
                    }
                    break;

                case '}':
                    if(pop(&n) == '{')
                        continue;
                    else{
                        printf("\n Error for {}");
                        exit(1);
                    }
                    break;

                case ']':
                    if(pop(&n) == '[')
                        continue;
                    else{
                        printf("\n Error for []");
                        exit(1);
                    }
                    break;
            }
        }
    }
    if(n.top == -1)
        printf("\n There is no paranthesis error in code");
    else
        printf("\n There is at least one opening paranthesis which is not closed");
    fclose(fptr);


}

