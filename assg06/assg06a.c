#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int a[100];
int tower_of_hanoi(char source,char destination,char misc,int n)
{
	int steps = 0;
	if(n ==1)
	{	
		for(int i=0;i<a[n];i++){
		printf("1 from %c to %c\n",source,destination); // For multiple same disk we repeat the operation 
		steps++;										// again and again
		}
			return steps;
	}
	steps+=tower_of_hanoi(source,misc,destination,n-1);
	for (int i = 0; i < a[n];++i)
	printf("%d from %c to %c \n",n,source,destination);
	steps+=a[n];
	steps+=tower_of_hanoi(misc,destination,source,n-1);
	return steps; // Returning the steps
}

int main() 
{
	printf("Enter the Number of disk : ");
	int n;
	scanf("%d",&n);
	int steps;
	for (int i = 1; i < n+1; ++i)
	{
		printf("\nNo. of disk type %d > ",i); // input of varide no of disks
		scanf("%d",&a[i]);
	}
	steps = tower_of_hanoi('a','c','b',n); // Calling the tower of hanoi
	printf("Number of Steps are : %d\n",steps);
}