#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define QUEUE_SIZE 100
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


typedef struct{
    int data[QUEUE_SIZE];
    int cnt;
    int front;
    int rear;
}queue;

void initialize(queue *q){
    q->cnt = 0;
    q->front = 0;
    q->rear = -1;
}

int isFull(queue *q){
    if(q->cnt == QUEUE_SIZE)
        return 1;
    else
        return 0;
}

int isEmpty(queue *q){
    if(q->cnt == 0)
        return 1;
    else
        return 0;
}

void enqueue(queue *q,int x){
    if(isFull(q))
        printf("\nQueue is full..");
    else{
        q->rear++;
        q->cnt++;
        if(q->rear == QUEUE_SIZE)
            q->rear = 0;
        q->data[q->rear] = x;
    }
}

int dequeue(queue *q){
    if(isEmpty(q)){
        printf("\nQueue is empty..");
        return -100;
    }
    else{
        int x = q->data[q->front];
        q->front++;
        q->cnt--;
        if(q->front == QUEUE_SIZE)
            q->front = 0;
        return x;
    }
}
int main(){
    queue q;
    stack s;
    reset(&s);
    initialize(&q);
    char str[100];
    int i = 0;
    printf("Enter a sentence");
    gets(str);
    while(i<strlen(str)){
        if(str[i]>= 'a' && str[i]<= 'z' || str[i]>= 'A' && str[i]<= 'Z' ){
            push(&s,tolower(str[i]));
            enqueue(&q,tolower(str[i]));
        }
        i++;
    }
    while(!isEmpty(&q)){
        if(pop(&s) != dequeue(&q)){
            printf("\n it is not polindrome");
            exit(1);
        }
    }
    printf("it is polindrome");
}
