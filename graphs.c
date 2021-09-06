#include<stdio.h>

int indegree(int matrix[][5],int v){
    int degree = 0;
    int i;
    for(i = 0;i<5;i++)
        degree += matrix[i][v]; //column
    return degree;
}

int outdegree(int matrix[][5],int v){
    int degree = 0;
    int i;
    for(i = 0;i<5;i++)
        degree += matrix[v][i]; //row
    return degree;
}

int nedges(int matrix[][5]){
    int result;
    int i,j;
    for(i=0;i<5;i++){
        for(j=0;j<5;j++)
            if(matrix[i][j] == 1) // indegree or outdegree ... it does not matter
                result++;
    }
    return result;
}

int main(){

    int matrix[5][5] = {{0,1,0,0,1},{0,0,1,0,1},{0,0,0,1,0},{0,0,0,0,1},{0,1,1,0,0}};
    int i,j;

    for(i=0;i<5;i++){
        for(j=0;j<5;j++)
            printf("%5d",matrix[i][j]);
        printf("\n");
    }

    printf("\nIn-Degree of the vertex 5 is %d",indegree(matrix,4)); //count column
    printf("\nOut-Degree of the vertex 5 is %d",outdegree(matrix,4)); //count row
    printf("\nThe number of edges is %d",nedges(matrix));

    return 0;
}
