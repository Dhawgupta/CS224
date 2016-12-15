#include<stdio.h>
#include<stdlib.h>
#include <time.h>

void quicksort(int *,int ,int);
int select_random_pivot(int,int);
int main()
{
	//printf("Enter the Number of elemetns : ");
	int n;
	scanf("%d",&n);
	int *a = (int *)malloc(sizeof(int)*n);
	int i=0;
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	//printf("Entering QUickSort\n");
	quicksort(a,0,n-1);
	printf("\n\n");
	//printf("Printing Quicksort\n");
	//for(i=0;i<n;i++)
		//printf("%d ",a[i]);

	
}
int quicksort_part(int *a, int low,int high)
{

	if(low == high)
	{
		return low;
	}
	 int pivot = select_random_pivot(low,high);
	 int Pivot = a[pivot];
	 a[pivot] = a[high];
	 a[high] = Pivot;
	 int l,j;
	 l = low -1;
	 int i;
	 
	 for(j = low ;j<high;j++)
	 {
	 	if(a[j] <= Pivot)
	 	{
	 		l = l+1;
	 		int temp = a[l];
	 		a[l] = a[j];
	 		a[j] = temp;

        } 	
	 }
	 
	 int temp = a[l+1];	
	 a[l+1] = a[high];
	 a[high] = temp;
	 //for(i=low;i<=high;i++)
		//printf("%d ",a[i]);
	//printf("\n");
	
	 return l+1;
} 

void quicksort(int *a,int low,int high)
{ 

	if(low < high)

{	//printf("In Quicksort\n");
	int x = quicksort_part(a,low,high); 
	quicksort(a,low,x-1);
	quicksort(a,x+1,high);
}
}


int select_random_pivot(int low,int high)
{
	//printf("In Select Random\n");
	srand(time(NULL));
	int r = (high-low)*((float)(rand())/RAND_MAX) + low;
	return r; 

}
