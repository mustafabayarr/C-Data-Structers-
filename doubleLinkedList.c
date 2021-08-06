#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
    struct node *prev;
};

struct node *addfront(struct node *head, int key){
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->data = key;
    temp->next = head;
    temp->prev = NULL;
    if(head != NULL)
        head->prev = NULL;
    head = temp;
    return head;
}

struct node *addlast(struct node *head, int key){
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->data = key;
    temp->next = NULL;
    if (head != NULL){
        struct node *last = head;
        while(last->next != NULL){
            last = last->next;
        }
        last->next = temp;
        temp->prev = last;
    }
    return head;
}

void print(struct node *head){
    if(head == NULL)
        printf("List is empty\n");
    else {
        while(head!=NULL){
            printf("%d\t",head->data);
            head = head->next;
        }
    }
}

main(){
    struct node *head = NULL;
    print(head);
    head = addfront(head,16);
    head = addfront(head,9);
    head = addlast(head,19);
    head = addfront(head,29);
    print(head);
}
