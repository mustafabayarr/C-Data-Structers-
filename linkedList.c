#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *addfront(struct node *head,int key){
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->data = key;
    temp->next = head;
    head = temp;
    return head;
}
struct node *addlast(struct node *head,int key){
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->data = key;
    temp->next = NULL;
    if(head==NULL)
        head = temp;
    else {
        struct node *last = head;
        while(last->next!=NULL)
            last = last->next;
        last->next = temp;
    }
    return head;
}
void print(struct node *head){
    if(head == NULL)
        printf("List is empty");
    else {
        while(head!=NULL){
            printf("%d\t",head->data);
            head = head->next;
        }
    }
}

int count(struct node *head){
        int i = 0;
        if(head == NULL)
            return 0;
        while(head!=NULL){
            i++;
            head = head->next;
        }
    return i;
}

main(){
    struct node *head = NULL;
    print(head);
    head = addlast(head,6);
    head = addlast(head,16);
    head = addfront(head,8);
    head = addfront(head,12);
    print(head);
    printf("The number of node is %d ",count(head));
}
