#include<stdio.h>
int count=0;
void print_perm(char a[],char small[],int n,int r,int small_r) // a is the array from which we take alphabet
// small is the array in which we store the rinting alphabet
// n is the no of elements in a
// r is the size of the combination
//small_r is the size of small
{
    if(r == small_r)
    {
        int i=0;
        printf("%d  ",++count);
        for(i=0; i<r; i++)
            printf("%c",small[i]);
        printf("\n");

        //return;
    }
    else
    {
        int i=0;
        for(i=0; i<n; i++)
        {
            char a1[100];
            if(a[i] != 10)
            {
                small[small_r] = a[i];
                //for(i=0;i<n;i++)
                //a1[i] = a[i];
                //a1[i] = 10;
                int j=0;
                for(j=0; j<n; j++)
                {
                    if(i!=j)
                        a1[j] = a[j];
                    else
                        a1[j] = 10;
                }
            }
            else
                continue;

print_perm(a1,small,n,r,small_r+1);
        }
    }
}

void main()
{
    count =0;
    int n,r;
    char a[100];
    printf("Enter the Value of n and r");
    scanf("%d",&n);
    scanf("%d",&r);
    int i=0;
    printf("Enter Sequence \n");
    for(i=0; i<n; i++)
    {
        fseek(stdin,0,SEEK_END);
        printf("Enter the %d element",i);
        scanf("%c",&a[i]);
    }
    for(i=0; i<n; i++)
        printf("%c",a[i]);
    printf("\n %d and %d \n",n,r);
    char small[100];
    int small_r = 0;
    print_perm(a,small,n,r,small_r);

}
