#include<stdio.h>
#include<math.h>
int Mult(int ,int );
int findLen(int);
int main()
{
	printf("Enter the 2 numbers to multiply: ");
	int a,b;
	scanf("%d%d",&a,&b);
	int al = findLen(a);
	int bl = findLen(b);


	int c= Mult(a,b);
	printf("\nTHe Multipilcatioin of Number's is : %d",c);
	return 0;

}
int findLen(int a)
{
	int n=0;
	while(1)
	{
		if(a/pow(2,n) == 0)
			return n;
		n++;
	}
}
int Mult(int a ,int b)
{
	int a1,a2;
	int b1,b2;
	la = findLen(a);
	lb = findLen(b);
	int la1,la2,lb1,lb2;
	la1 = la/2;
	la2 = la - la1;
	lb1 = lb/2;
	lb2 = lb - lb1;
	a1 = a>>la2;
	a2  = a%pow(2,la2);
	b1 = b>>lb2;
	b2  = b%pow(2,lb2);

	printf("The Value of a1 : %d \n a2 : %d \n b1 : %d \n b2 : %d \n",a1,a2,b1,b2);
	

}