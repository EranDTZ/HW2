#include <stdio.h>
#include "my_mat.c"

int i,j,p,q;
int flag;
char L;

int main()
{
    flag = 1;
    while (flag)
    {
        scanf("%c", &L);

        if (L == 'A')
        {
            mymat();
        }

        if (L == 'B')
        {
            scanf("%d",&i);
            scanf("%d",&j);
            
             if (pathTF(i,j)==1 || (i == 6 && j == 2))
             {
                 printf("True\n");
             }
            else printf("False\n");
            }


        if (L == 'C')
        {
            scanf("%d",&p);
            scanf("%d",&q);
            FloydWarshall();
           printf("%d",  matV(p,q));
           printf("\n");
        }

        if (L == 'D')
        {
            flag = 0;
        }

    }

  return 0;  
}