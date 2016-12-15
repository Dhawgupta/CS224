#include<stdio.h>
#include<stdlib.h>
void EnterMatrix(int **,int,int);
void SumMatrix(int **,int **,int **,int,int,int);
int MultMatrix(int **,int **,int **,int,int,int);
void printM(int **,int,int);
int check(int **,int ,int ,int *,int );

int main()
{
    int m1,m2,n;
    printf("Enter the Dimensions of the Matrix i.e. N for(NxN): ");
    scanf("%d",&n);
    printf("Enter the Value No. of elements in matrix 1(m1) and matrix 2(m2) :");
    scanf("%d%d",&m1,&m2);

    int **matrix1;
    matrix1  = (int **)malloc(sizeof(int *) * m1);
    matrix1[0] = (int *)malloc(sizeof(int) * 3 * m1);
    int i;
    for(i = 0; i < m1; i++)
        matrix1[i] = (*matrix1 + 3 * i);

    int **matrix2;
    matrix2  = (int **)malloc(sizeof(int *) * m2);
    matrix2[0] = (int *)malloc(sizeof(int) * 3 * m2);
    for(i = 0; i < m2; i++)
        matrix2[i] = (*matrix2 + 3 * i);

    EnterMatrix(matrix1,m1,n);
    printM(matrix1,m1,n);

    EnterMatrix(matrix2,m2,n);
    printM(matrix2,m2,n);


    int **Sum;
    int k = ((m1+m2)>n*n)?n*n:(m1+m2);
    Sum = (int **)malloc(sizeof(int *) * k);
    Sum[0] = (int *)malloc(sizeof(int) * 3 * k);
    for(i = 0; i < k; i++)
        Sum[i] = (*Sum + 3 * i);
    SumMatrix(matrix1,matrix2,Sum,m1,m2,n);
    printf("\nSUM\n");
    printM(Sum,k,n);

    int **Mult;
    int km = n*n;
    Mult  = (int **)malloc(sizeof(int *) * km);
    Mult[0] = (int *)malloc(sizeof(int) * 3 * km);
    for(i = 0; i < km; i++)
        Mult[i] = (*Mult + 3 * i);

    int length = MultMatrix(matrix1,matrix2,Mult,m1,m2,n);
    printf("\nMultiplucation\n");
    Mult = (int **)realloc(Mult,sizeof(int *)*length);
    printM(Mult,length,n);


    //for(i = 0;i<m1;i++)
    //{
    //   printf("%d \n",matrix1[i][2]);
    //}
    return 0;

}
int MultMatrix(int **m1,int **m2,int **m,int n1,int n2,int n)
{
    int *r1 = (int *)malloc(sizeof(int));
    int *r2 = (int *)malloc(sizeof(int));

    int i=0,j=0,k=0,l=0,sum = 0;
    for(i=0;i < n;i++)
    {
        for(j=0;j<n;j++)
        {
            sum =0;
            for(k=0;k<n;k++)
            {
                    //printf("Doing the stuff ");
                 if(check(m1,i,k,r1,n1) && check(m2,k,j,r2,n2))
                    sum = sum + m1[*r1][2]*m2[*r2][2];

//printf("  THe product and sum :%d and %d  and  %d  %d  \n",*r1,*r2,sum,check(m2,k,j,r2,n2));

            }
            if(sum != 0)
            {
                //printf("Done\n");
                m[l][2] = sum;
                m[l][0] = i;
                m[l][1] = j;
                l++;

            }


        }
    }
    return l;
}
void SumMatrix(int **m1,int **m2,int **s,int n1,int n2,int n)
{
    int i=0,j=0,k=0;
    int *r1 = (int *)malloc(sizeof(int)),*r2 = (int *)malloc(sizeof(int));
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            if(check(m1,i,j,r1,n1) && check(m2,i,j,r2,n2))
            {
                s[k][2] = m1[*r1][2]+m2[*r2][2];
                s[k][0] = i;
                s[k][1] = j;
                k++;
            }
            else if(check(m1,i,j,r1,n1))
            {
                s[k][2] = m1[*r1][2];
                s[k][0] = i;
                s[k][1] = j;
                k++;

            }
            else if(check(m2,i,j,r2,n2))
            {
                s[k][2] = m2[*r2][2];
                s[k][0] = i;
                s[k][1] = j;
                k++;

            }
            else
                continue;



        }
    }

}
void EnterMatrix(int **m,int m1,int n)
{
    int i=0;
    printf("Enter Matrix in no of elements x3 form:\n ");
    printf("s.no row col val Between 0 and n-1\n");
    for(i=0; i<m1; i++)
    {
        do
        {
            printf("%d) ",i);
            scanf("%d%d%d",&m[i][0],&m[i][1],&m[i][2]);
        }
        while((m[i][0] > n-1 || m[i][1] > n-1 ) );

    }
}
int check(int **m,int i,int j,int *r,int n)
{
    int k=0;
    for(k=0; k < n; k++)
    {
        if(m[k][0] == i && m[k][1] == j && m[k][2] != 0)
        {
            *r = k;
            return 1;


        }

    }
    return 0;


}
void printM(int **m,int m1,int n)
{
    int i,j;
    int *r = (int *)malloc(sizeof(int));
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            if(check(m,i,j,r,m1))
                printf("%d ",m[*r][2]);
            else
                printf("0 ");
        }
        printf("\n");



    }
}
