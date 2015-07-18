#include <stdio.h>

void print_array(int *p,int RowSize,int LineSize)
{
    int i,j;
    for(i=0 ; i<RowSize ;i++)
    {
     for(j=0 ; j<LineSize ;j++)
      printf("%d ",*(p+i*LineSize+j));
     printf("\n");
    }
}
int main()
{
    int i,j,a[3][3]={ {1,0,0} , {0,1,0} , {0,0,1} };
    print_array( (int *)a ,3,3);
    printf("------\n");
    for(i=0;i<3;i++)
    {
     for(j=0;j<3;j++)
      printf("%d ",*(*(a+i)+j));
     printf("\n");
    }
    return 0;
}
