#include <stdio.h>
#include "my_mat.h"

#define size 10
int mat[size][size];
int minmat[size][size];
int input;



void printmat() 
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
        
    }
    
}



void mymat()
{
  for (int i = 0; i < size; i++)
  {
    for (int j = 0; j < size; j++)
    {
        //printf("choose a number \n");
        scanf("%d", &input);
        mat[i][j] = input;
    }
  }
}



int pathTF(int i,int j)
{
if (mat[i][j] < 1000000 && mat[i][j] > 0)
{
    return 1;
}
return 0;
}



void FloydWarshall()
{
    for (int k = 0; k < size; k++)
    {
        
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                if (k!=i && k!=j)
                {
                     if (i != j && mat[i][k]>0 && mat[k][j]>0)
                    {
                        if (mat[i][j] == 0)
                        {
                            mat[i][j] = mat[i][k] + mat[k][j];
                        }
                        
                        if (mat[i][k] + mat[k][j] < mat[i][j])
                        {
                         mat[i][j] = mat[i][k] + mat[k][j];
                        }
                    }
                }
            }
        }
    }
}


int matV(int p,int q)
{
    if (mat[p][q] == 0)
    {
        return -1;
    }
    return mat[p][q];
}

