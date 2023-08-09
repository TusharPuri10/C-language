#include<stdio.h>
#include<stdlib.h>
void setZeroes(int** matrix, int rows, int cols)
{
    int* z_rows = (int*) calloc(rows,sizeof(int));
    int* z_cols = (int*) calloc(cols,sizeof(int));
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<cols;j++)
        {
            if(matrix[i][j]==0)
            {
                z_rows[i]++;
                z_cols[j]++;
            }
        }
    }

    // setting all the rows zeroes
    for(int i=0;i<rows;i++)
        if(z_rows[i]>0)
            for(int j=0;j<cols;j++)
                matrix[i][j]=0;


    // setting all the cols zeroes
    for(int i=0;i<cols;i++)
        if(z_cols[i]>0)
            for(int j=0;j<rows;j++)
                matrix[j][i]=0;
}
int main()
{
    int rows,cols;
    scanf("%d",&rows);
    scanf("%d",&cols);

    int** matrix = (int**) malloc(rows*sizeof(int*));
    for(int i=0;i<rows;i++)
    {
        *(matrix+i) = (int*) malloc(cols*sizeof(int));
    }

    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<cols;j++)
        {
            scanf("%d",&matrix[i][j]);
        }
    }

    setZeroes(matrix, rows, cols);

    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<cols;j++)
        {
            printf("%d,",matrix[i][j]);
        }
        printf("\n");
    }
    return 0;
}