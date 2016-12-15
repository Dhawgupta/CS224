#include<stdio.h>
void fib(int n)
{
 int x1 = 1;
 int x2 = 1;
 int  i=0;
 for(i=1; i<=n;i++)
 {
 printf(" %d ",x2);
 int temp =x2;
 x2 = x2+x1;
 x1 = temp;
 }
}
void main()
{
int n;
scanf("%d",&n);
fib(n);
return;
}
