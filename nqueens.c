#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int count=0;
void display(int board[100],int n)
{
    printf("\n\nSolution %d:\n\n",++count);
    int i,j;
    for(i=1;i<=n;i++)
    printf("\t%d",i);

    for(i=1;i<=n;i++)
    {
        printf("\n\n%d",i);
        for(j=1;j<=n;j++)
        {
            if(board[i]==j)
            printf("\tQ"); 
            else
            printf("\t-"); 
        }
    }
   printf("\n");
}


int place(int board[100],int row,int col)
{
    int j;
    for(j=1;j<=row-1;j++)
    {
         if((board[j]==col)||(abs(board[j]-col)==abs(j-row)))
         {
              return 0;
         }
           
    }
    return 1;
}
void nqueen(int board[100],int row,int size)
{
    int i;
    for(i=1;i<=size;i++)
    {
        if(place(board,row,i))
        {
            board[row]=i;
            if(row==size)
            {
                display(board,size);
            }
        else
        {
            nqueen(board,row+1,size);
        }
        }
        
        
    }
}
void main()
{
    int board[100];
    int size,row;
    printf("Enter the size of the board:");
    scanf("%d",&size);
    row=1;
    nqueen(board,row,size);
}