#include <stdio.h>
#define QUEUE_SIZE 4

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
    initialize(&q);
    enqueue(&q,10);
    enqueue(&q,8);
    enqueue(&q,9);
    enqueue(&q,21);
    enqueue(&q,14);
    printf("\n%d",dequeue(&q));
    printf("\n%d",dequeue(&q));
    printf("\n%d",dequeue(&q));
    printf("\n%d",dequeue(&q));
    printf("\n%d",dequeue(&q));

}
