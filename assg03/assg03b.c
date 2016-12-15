#include<stdio.h>
int main()
{
    int n1[100][3],n2[100][3],no,nt;
    printf("Enter the Number of Elements in Matrix One and Two : ");
    scanf("%d%d",&no,&nt);
    int m;
    printf("\n Enter the Value of m for MxM matrix : ");
    scanf("%d",&m);
    printf(" \n Enter the Values for N1 \n");
    int i=0;
    for(i=0;i<no;i++)
    {
        printf("%d ) ",i+1);
        do
        {
            printf(" r> ");
            scanf("%d",&n1[i][0]);

        }while(n1[i][0] > m);
        do
        {
            printf(" c> ");
            scanf("%d",&n1[i][1]);

        }while(n1[i][1] > m);
        do
        {
                    printf("Value: ");
        scanf("%d",&n1[i][2]);
        }while(n1[i][2] != 0);

    }
    printf(" \n Enter the Values for N2 \n");
    //int i=0;
    for(i=0;i<nt;i++)
    {
        printf("%d ) ",i+1);
        do
        {
            printf(" r> ");
            scanf("%d",&n2[i][0]);

        }while(n2[i][0] > m);
        do
        {
            printf(" c> ");
            scanf("%d",&n2[i][1]);

        }while(n2[i][1] > m);
        do
        {
                    printf("Value: ");
        scanf("%d",&n2[i][2]);
        }while(n2[i][2] != 0);
            }



}
void sum(int a[][3],int b[][3],int n1,int n2)
{
    if(n1>n2)
    {


    }

}
