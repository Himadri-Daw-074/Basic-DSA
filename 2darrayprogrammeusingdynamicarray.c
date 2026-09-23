#include<stdio.h>
#include<stdlib.h>
int main()
{
    int i,j,row,col;
    printf("Enter the number of rows and columns: ");
    scanf("%d %d",&row,&col);
    int **arr;
    arr=(int **)malloc(row*sizeof(int *));
    for(i=0;i<row;i++)
    {
        arr[i]=(int *)malloc(col*sizeof(int));
        for(j=0;j<col;j++)
        {
            printf("Enter element [%d][%d]: ",i,j);
            scanf("%d",&arr[i][j]);
        }
    
    }
    return 0;
}