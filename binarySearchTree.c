#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *left;
    struct node *right;
};

typedef struct node *BTREE;

void inorder(BTREE root){
    if(root != NULL){
        inorder(root->left);
        printf("%d\t",root->data);
        inorder(root->right);
    }
}

void postorder(BTREE root){
    if(root != NULL){
        postorder(root->left);
        postorder(root->right);
        printf("%d\t",root->data);
    }
}

void preorder(BTREE root){
    if(root != NULL){
        printf("%d\t",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

BTREE newnode(int data){
    BTREE p;
    p = (BTREE)malloc(sizeof(struct node));
    p->data = data;
    p->left = p->right = NULL;
    return p;
}

BTREE insert(BTREE root,int x){
    if(root == NULL){
        root = newnode(x);
    }
    else{
        if(x<root->data){
            root->left = insert(root->left,x);
        }
        else{
            root->right = insert(root->right,x);
        }
    }
    return root;
}

int leaves(BTREE root){
    if(root == NULL)
        return 0;
    if(root->left == root->right)
        return 1;
    else
        return leaves(root->left)+ leaves(root->right);
}

int main(){
    BTREE myroot = NULL;
    int x;
    printf("Enter a value : ");
    scanf("%d",&x);
    while(x != -1){
        myroot = insert(myroot,x);
        printf("Enter a value : ");
        scanf("%d",&x);
    }
    inorder(myroot);
    printf("\n%d",leaves(myroot));
}
