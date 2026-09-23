#include<stdio.h>
#include<stdlib.h>
void display(int **arr,int row,int col)
{
    int i,j;
    printf("The elements of the 2D array are:\n");
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        {
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
}

void sumdiagonal(int **arr,int row,int col)
{
    int i,j,sum=0;
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        {
            if(i==j)
            {
                sum+=arr[i][j];
            }
        }
    }
    printf("The sum of the diagonal elements is: %d\n",sum);
}
void sumrow(int **arr,int row,int col)
{
    int i,j,sum=0;
    for(i=0;i<row;i++)
    {
        sum=0;
        for(j=0;j<col;j++)
        {
            sum+=arr[i][j];
        }
        printf("The sum of the elements of row %d is: %d\n",i,sum);
    }
}

void sumcol(int **arr,int row,int col)
{
    int i,j,sum=0;
    for(j=0;j<col;j++)
    {
        sum=0;
        for(i=0;i<row;i++)
        {
            sum+=arr[i][j];
        }
        printf("The sum of the elements of column %d is: %d\n",j,sum);
    }
}
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
    while(1)
    {
        printf(" 1 display the array\n");
        printf(" 2 sum diagonal elements\n");
        printf(" 3 sum row elements\n");
        printf(" 4 sum column elements\n");
        printf(" 5 exit\n");
        int choice;
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                display(arr,row,col);
                break;
            case 2:
                sumdiagonal(arr,row,col);
                break;
            case 3:
                sumrow(arr,row,col);
                break;
            case 4:
                sumcol(arr,row,col);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}