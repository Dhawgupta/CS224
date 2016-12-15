#include <stdio.h>
#include <time.h>
#include <stdlib.h>
int main()
{
	srand(time(NULL));
	//printf("Enter no of elements :");
	int n;
	scanf("%d",&n);
	printf("%d ",n);
	int i=0;
	int *a = (int *)malloc(sizeof(int)*n);
	for(i=0;i<n;i++)
		{
		a[i] = 10000*(((float)rand())/RAND_MAX);
		printf("%d ",a[i]);
		}
}
