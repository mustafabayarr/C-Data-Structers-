#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
//typedef char * string;

/*MENU*/
/*
void menu(){
    char dataStructureType;

    printf("**************************************************\n");
    printf("Please Select The Data Structure // A or B or C \\\n");
    printf("A - Array Data Structure\n");
    printf("B - BST Data Structure\n");
    printf("C - AVL Data Structure\n");
    printf("D - Exit\n");
    printf("**************************************************\n\n");
    scanf("%c",&dataStructureType);
    printf("%c entered\n\n", dataStructureType);
}

void submenu_array(){
    int subDataStructureType;
    printf("////////////////////////////////////////\n\n");
    printf("Please Select The Sub Data Structure // 1 or 2 \\\n");
    printf("1 - Create Array\n");
    printf("2 - Search a Student\n");
    printf("3 - Return Main Menu\n");
    printf("////////////////////////////////////////\n\n");
    scanf("%d",&subDataStructureType);
    printf("%d entered\n\n", subDataStructureType);
}

void submenu_bst(){
    int subDataStructureType;
    printf("////////////////////////////////////////\n\n");
    printf("Please Select The Sub Data Structure // 1 or 2 \\\n");
    printf("1 - Create BST\n");
    printf("2 - Search a Student in BST\n");
    printf("3 - Height\n");
    printf("4 - Return Main Menu\n");
    printf("////////////////////////////////////////\n\n");
    scanf("%d",&subDataStructureType);
    printf("%d entered\n\n", subDataStructureType);

}*/

/*Array*/
struct ogrenciler{
    int id;
    char name[200];
    char surname[200];
    int year;
    int ECTS;
    float grade;
};
struct ogrenciler ogrenci[10000];

void foo(struct ogrenciler *ogrenci, const int index){
    printf("id : %d\n",ogrenci[index].id);
    printf("Name : %s\n",ogrenci[index].name);
    printf("Surname : %s\n",ogrenci[index].surname);
    printf("Year : %d\n",ogrenci[index].year);
    printf("ECTS : %d\n",ogrenci[index].ECTS);
    printf("Grade : %.1f\n",ogrenci[index].grade);
}
/*End - Array*/

/* BST */
struct node{
    int id;
    char name[200];
    char surname[200];
    int year;
    int ECTS;
    float grade;
    struct node *left;
    struct node *right;
};

void inorder(struct node* root){
    if(root != NULL){
        inorder(root->left);
        printf("%d\t",root->id);
        printf("%s\t",root->name);
        printf("%s\t",root->surname);
        printf("%d\t",root->year);
        printf("%d\t",root->ECTS);
        printf("%.1f\n",root->grade);
        inorder(root->right);
    }
}

struct node* newnode(int id,char name[], char surname[], int year, int ECTS, float grade){
    struct node* p;
    p = (struct node*)malloc(sizeof(struct node));
    p->id = id;
    strcpy(p->name,name);
    //p->name = name;
    strcpy(p->surname,surname);
   // p->surname = surname;
    p->year = year;
    p->ECTS = ECTS;
    p->grade = grade;
    p->left = p->right = NULL;
    return p;
}

struct node* insert(struct node* root,int id,char name[], char surname[], int year, int ECTS, float grade){
    if(root == NULL)
        root = newnode(id,name,surname,year,ECTS,grade);
    else{
        if(id < root->id)
            root->left = insert(root->left,id,name,surname,year,ECTS,grade);
        else
            root->right = insert(root->right,id,name,surname,year,ECTS,grade);
    }
    return root;
}

struct node* searchTree(struct node* root,int id){
    if(root != NULL){
        if(root->id == id)
            return root;
        else if(root->id > id)
            return searchTree(root->left,id);
        else
            return searchTree(root->right,id);
    }
    else
        return NULL;
};

void print_bst_search(struct node* root){
    printf("%d\t%s\t%s\t%d\t%d\t%.1f",root->id,root->name,root->surname,root->year,root->ECTS,root->grade);
}

int height_bst(struct node* root){
    if(root == NULL)
        return -1;
    else{
        int left_height, right_height;
        left_height = height_bst(root->left);
        right_height = height_bst(root->right);

        if(right_height > left_height)
            return right_height + 1;
        else
            return left_height + 1;
    }
}
/* END - BST */

/* START - AVL */

struct node2{
    int id;
    char name[200];
    char surname[200];
    int year;
    int ECTS;
    float grade;
    struct node2 *left;
    struct node2 *right;
    int height;
};

int maxValue(int x,int y){
    return x>=y?x:y;
}

struct node2* newnode2(int id,char name[], char surname[], int year, int ECTS, float grade){
    struct node2* p;
    p = (struct node2*)malloc(sizeof(struct node2));
    p->id = id;
    strcpy(p->name,name);
    //p->name = name;
    strcpy(p->surname,surname);
   // p->surname = surname;
    p->year = year;
    p->ECTS = ECTS;
    p->grade = grade;
    p->left = p->right = NULL;
    p->height = 0;
    return p;
}

struct node2 *RightRotate(struct node2 *z){
    struct node2* y = z->left;
    z->left = y->right;
    y->right = z;
    z->height = maxValue(z->left==NULL?-1:z->left->height,z->right==NULL?-1:z->right->height)+1;
    y->height = maxValue(y->left==NULL?-1:y->left->height,y->right==NULL?-1:y->right->height)+1;
    return y;
}


struct node2 *LeftRotate(struct node2 *z){
    struct node2* y = z->right;
    z->right = y->left;
    y->left = z;
    z->height = maxValue(z->left==NULL?-1:z->left->height,z->right==NULL?-1:z->right->height)+1;
    y->height = maxValue(y->left==NULL?-1:y->left->height,y->right==NULL?-1:y->right->height)+1;
    return y;
}

struct node2 *leftRightRotate(struct node2 *z){
    z->left=LeftRotate(z->left);
    return RightRotate(z);
}

struct node2 *rightLeftRotate(struct node2 *z){
    z->right=RightRotate(z->right);
    return LeftRotate(z);
}

int height(struct node2 *root){
    if(root == NULL)
        return -1;
    else{
        int lheight,rheight;
        rheight = height(root->right);
        lheight = height(root->left);
        if(rheight>lheight)
            return rheight + 1;
        else
            return lheight + 1;
    }
}

struct node2* insertToAVL(struct node2* tree, int id,char name[], char surname[], int year, int ECTS, float grade){
    if(tree != NULL){
        if(id < tree->id)
            tree->left = insertToAVL(tree->left,id,name,surname,year,ECTS,grade);
        else
            tree->right = insertToAVL(tree->right,id,name,surname,year,ECTS,grade);
       // tree->height = maxValue(height(tree->left),height(tree->right));
        tree->height=maxValue(tree->left==NULL?-1:tree->left->height, tree->right==NULL?-1:tree->right->height)+1;

        if((tree->left==NULL?-1:tree->left->height)-(tree->right==NULL?-1:tree->right->height)>1 && id< tree->left->id)
            return RightRotate(tree);
        if((tree->left==NULL?-1:tree->left->height)-(tree->right==NULL?-1:tree->right->height)>1 && id> tree->left->id)
            return leftRightRotate(tree);
        if((tree->left==NULL?-1:tree->left->height)-(tree->right==NULL?-1:tree->right->height)< -1 && id> tree->right->id)
            return LeftRotate(tree);
        if((tree->left==NULL?-1:tree->left->height)-(tree->right==NULL?-1:tree->right->height)< -1 && id< tree->right->id)
            return rightLeftRotate(tree);

    }else
        tree = newnode2(id,name,surname,year,ECTS,grade);
    return tree;
}

void inorder2(struct node2* root){
    if(root != NULL){
        inorder2(root->left);
        printf("%d\t",root->id);
        printf("%s\t",root->name);
        printf("%s\t",root->surname);
        printf("%d\t",root->year);
        printf("%d\t",root->ECTS);
        printf("%.1f\n",root->grade);
        inorder2(root->right);
    }
}

struct node2* searchAVL(struct node2* root,int id){
    if(root != NULL){
        if(root->id == id)
            return root;
        else if(root->id > id)
            return searchAVL(root->left,id);
        else
            return searchAVL(root->right,id);
    }
    else
        return NULL;
}

void print_AVL_search(struct node2 *root){
    printf("%d\t%s\t%s\t%d\t%d\t%.1f",root->id,root->name,root->surname,root->year,root->ECTS,root->grade);
}

/* END - AVL */

int main(){
    struct node* myroot = NULL;
    struct node2* myroot2 = NULL;
    struct node p1;
    struct node2 p2;
    int index = 0;

    int i;

    int id;
    FILE *my;

    clock_t begin;
    clock_t end;
    double time_spent;

    int x;
    int find;

    char dataStructureType;
    int subDataStructureType;
   // menu();
    printf("**************************************************\n");
    printf("Please Select The Data Structure // A or B or C \\\n");
    printf("A - Array Data Structure\n");
    printf("B - BST Data Structure\n");
    printf("C - AVL Data Structure\n");
    printf("D - Exit\n");
    printf("**************************************************\n\n");
    scanf("%c",&dataStructureType);
    printf("%c entered\n\n", dataStructureType);

    switch(dataStructureType){
        case 'A':
           // submenu_array();
            printf("////////////////////////////////////////\n\n");
            printf("Please Select The Sub Data Structure // 1 or 2 \\\n");
            printf("1 - Create Array\n");
            printf("2 - Search a Student\n");
            printf("3 - Return Main Menu\n");
            printf("////////////////////////////////////////\n\n");
            scanf("%d",&subDataStructureType);
            printf("%d entered\n\n", subDataStructureType);
            switch(subDataStructureType){
                case 1:
                    /*Create/Show Array*/
                    begin = clock();
                    my = fopen("my.txt","r");
                    if(my == NULL){
                        printf("File does not exist");
                    }
                    else{
                        for(i = 0; i < 9492; i++){
                            fscanf(my, "%d", &ogrenci[i].id);
                            fscanf(my, "%s", ogrenci[i].name);
                            fscanf(my, "%s", ogrenci[i].surname);
                            fscanf(my, "%d", &ogrenci[i].year);
                            fscanf(my, "%d", &ogrenci[i].ECTS);
                            fscanf(my, "%f", &ogrenci[i].grade);
                        }
                        for(i = 0; i < 9492; i++){
                            printf("%d\t", ogrenci[i].id);
                            printf("%s\t", ogrenci[i].name);
                            printf("%s\t", ogrenci[i].surname);
                            printf("%d\t", ogrenci[i].year);
                            printf("%d\t", ogrenci[i].ECTS);
                            printf("%.1f\n", ogrenci[i].grade);
                        }
                        fclose(my);
                    }
                    end = clock();
                    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
                    printf("\n\nArray Created.. Process time : %.2f s\n", time_spent);
                   // menu();

                break;
                case 2:
                    /*Search a Student*/
                    my = fopen("my.txt","r");
                    if(my){
                        while(!feof(my)){
                            fscanf(my,"%d%s%s%d%d%f",&ogrenci[index].id,
                                   ogrenci[index].name,ogrenci[index].surname,
                                   &ogrenci[index].year,&ogrenci[index].ECTS,&ogrenci[index].grade);
                                   index++;
                        }
                    }

                    while(1){
                        printf("Enter ID:");
                        scanf("%d",&id);
                        begin = clock();

                        for(i=0;i<index;i++){
                            if(id == ogrenci[i].id)
                                break;
                        }
                        foo(ogrenci,i);

                        end = clock();
                        time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
                        printf("\nFound in : %.2f s\n", time_spent);

                        exit(0);
                    }
                    fclose(my);
                   // menu();
                break;
                case 3:
               //     menu();

                break;
            }
        break;
        case 'B':
            //submenu_bst();
            printf("////////////////////////////////////////\n\n");
            printf("Please Select The Sub Data Structure // 1 or 2 \\\n");
            printf("1 - Create BST\n");
            printf("2 - Search a Student in BST\n");
            printf("3 - Height\n");
            printf("4 - Return Main Menu\n");
            printf("////////////////////////////////////////\n\n");
            scanf("%d",&subDataStructureType);
            printf("%d entered\n\n", subDataStructureType);
            switch(subDataStructureType){
                case 1:
                    /*BST CREATE*/
                    begin = clock();
                    my = fopen("my.txt","r");
                    if(my){
                        while(!feof(my)){
                            fscanf(my,"%d%s%s%d%d%f",&p1.id,p1.name,p1.surname,&p1.year,&p1.ECTS,&p1.grade);
                            myroot = insert(myroot,p1.id,p1.name,p1.surname,p1.year,p1.ECTS,p1.grade);
                        }
                        inorder(myroot);

                    }
                    else{
                        printf("File does not exist");
                    }

                    fclose(my);
                    end = clock();
                    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
                    printf("\n BST Created.. Process Time : %.2f s\n", time_spent);
                break;
                case 2:
                    my = fopen("my.txt","r");
                    printf("Enter ID:");
                    scanf("%d",&id);
                    begin = clock();
                     if(my){
                        while(!feof(my)){
                            fscanf(my,"%d%s%s%d%d%f",&p1.id,p1.name,p1.surname,&p1.year,&p1.ECTS,&p1.grade);
                            myroot = insert(myroot,p1.id,p1.name,p1.surname,p1.year,p1.ECTS,p1.grade);
                            if(id != p1.id)
                                myroot = searchTree(myroot,id);
                        }
                        print_bst_search(myroot);
                        end = clock();
                        time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
                        printf("\n Found in : %.2f s\n", time_spent);
                    }
                    else{
                        printf("File does not exist");
                    }
                break;
                case 3:
                    begin = clock();
                    my = fopen("my.txt","r");
                    if(my){
                        while(!feof(my)){
                            fscanf(my,"%d%s%s%d%d%f",&p1.id,p1.name,p1.surname,&p1.year,&p1.ECTS,&p1.grade);
                            myroot = insert(myroot,p1.id,p1.name,p1.surname,p1.year,p1.ECTS,p1.grade);
                        }
                        //inorder(myroot);
                        printf("The Height of the Tree : %d", height_bst(myroot));
                     }
                    end = clock();
                    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
                    printf("\n Found in : %.2f s\n", time_spent);
                    //menu();
                break;
                case 4:
                   // menu();
                break;
            }
        break;
        case 'C':
            printf("////////////////////////////////////////\n\n");
            printf("Please Select The Sub Data Structure // 1 or 2 \\\n");
            printf("1 - Create AVL\n");
            printf("2 - Search a Student in AVL\n");
            printf("3 - Height AVL\n");
            printf("4 - Return Main Menu\n");
            printf("////////////////////////////////////////\n\n");
            scanf("%d",&subDataStructureType);
            printf("%d entered\n\n", subDataStructureType);
            switch(subDataStructureType){
                case 1:
                    begin = clock();
                    my = fopen("my.txt","r");
                    if(my){
                        while(!feof(my)){
                                fscanf(my,"%d%s%s%d%d%f",&p2.id,p2.name,p2.surname,&p2.year,&p2.ECTS,&p2.grade);
                                myroot2 = insertToAVL(myroot2,p2.id,p2.name,p2.surname,p2.year,p2.ECTS,p2.grade);

                        }
                        inorder2(myroot2);
                    }
                    else{
                        printf("File does not exist");
                    }
                    end = clock();
                    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
                    printf("\n AVL Created.. Process Time : %.2f s\n", time_spent);
                    fclose(my);
                break;
                case 2:
                    my = fopen("my.txt","r");
                    printf("Enter ID:");
                    scanf("%d",&id);
                    begin = clock();
                     if(my){
                        while(!feof(my)){
                            fscanf(my,"%d%s%s%d%d%f",&p2.id,p2.name,p2.surname,&p2.year,&p2.ECTS,&p2.grade);
                            myroot2 = insertToAVL(myroot2,p2.id,p2.name,p2.surname,p2.year,p2.ECTS,p2.grade);
                            if(id != p2.id)
                                myroot2 = searchAVL(myroot2,id);
                        }
                        print_AVL_search(myroot2);
                        end = clock();
                        time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
                        printf("\n Found in : %.2f s\n", time_spent);
                    }
                    else{
                        printf("File does not exist");
                    }
                break;
                case 3:
                    begin = clock();
                    my = fopen("my.txt","r");
                    if(my){
                        while(!feof(my)){
                                fscanf(my,"%d%s%s%d%d%f",&p2.id,p2.name,p2.surname,&p2.year,&p2.ECTS,&p2.grade);
                                myroot2 = insertToAVL(myroot2,p2.id,p2.name,p2.surname,p2.year,p2.ECTS,p2.grade);
                        }
                        printf("The Height of the AVL Tree : %d", height(myroot2));

                    }
                    else{
                        printf("File does not exist");
                    }
                    end = clock();
                    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
                    printf("\n Process Time : %.2f s\n", time_spent);
                    fclose(my);
                break;
            }

        break;
        case 'D':
            exit(1);
        break;
    }
}
