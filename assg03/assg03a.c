#include<stdio.h>
int count =1; // Not relevant right now
int sols[100][100]; // The Different Slutions
int solsize[100]; // The Sizes of Different Solutions
int solno =0; // Number of Solutions
int smallest=1000000; // stores the value of smallest Legnth
void Comb(int a[],int small[],int n,int C,int j)// Comb is the recursive function to call
// A -  is the matrix of original items
// small is the current array or combination of numbers
// n is the last elemet to choose from A
// C is the sum up of the elements
// j is the number of elements in small
{
    if(n < 0 && C>0)
    {
        //printf("%d)   ",count++);
        //printf("Not Possible\n");
        return;

    }
    else if(C==0) // Check for the Solution
    {

        /*printf("%d)   ",count++);
        printf("Solution Possible\n");
        int i=0;
        for(i=0;i<j;i++)
            printf("%d ",small[i]);
            */
        int i=0;
        solsize[solno] = j;
        for(i=0; i<j; i++)
            sols[solno][i] = small[i]; // Copy the solution(small) to Sols with the size in solsize
        solno++;
        if(smallest > j) // Updates the value of smallest to check wehter the new solution is smallest or not
            smallest =j;

        //printf("\n");
        for(i=0; i<j; i++)
            return;
    }
    // This is the end case
    else if(C<0) // this is an error case
    {

        //printf("%d)   ",count++);
        //printf("XX\n");

        return;
    }

    else // the recursive part
    {
        int s = a[n];  // Extracts the next value of A
        int small2[100]; // THe Extra to pass on the function to others an also
        int i=0;
        for(i=0; i<j; i++)
        {
            small2[i] = small[i];
        }

        Comb(a,small2,n-1,C,j);//the part where the term is not included
        small2[j] = s;
        Comb(a,small2,n-1,C-s,j+1); // the part where term is included
    }



}

int main()
{
    printf("Enter the value of N : ");
    int n;
    scanf("%d",&n);
    printf("Enter the denominations : \n");
    int i=0;
    int a[100];
    for(i=0; i<n; i++)
        scanf("%d",&a[i]);
    for(i=0; i<n; i++)
        printf("%d ",a[i]);

    int C;
    printf("Enter the Value of C");
    scanf("%d",&C);
    int small[100];
    int j=0;
    Comb(a,small,n-1,C,j);
    if(solno == 0)
        printf("No solution Possible ");
    else
    {

        printf("\n--------------------------------------------\n ");
        printf("The smallest Possible Cases are of length %d",smallest);
        int k=0;
        printf("\n----------------------------------\n");
        for(i=0; i<solno; i++)
        {
            if(solsize[i]== smallest)
            {
                for(k=0; k<solsize[i]; k++)
                    printf("%d ",sols[i][k]);
                printf("\n");
            }

        }
    }
}



