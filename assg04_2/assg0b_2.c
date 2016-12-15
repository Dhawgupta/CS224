#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void quicksort(int *,int ,int);
int median_pivot(int*,int,int);
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
	//printf("\n\n");
	//printf("Printing Quicksort\n");
	for(i=0;i<n;i++)
		printf("%d ",a[i]);

	
}
int quicksort_part(int *a, int low,int high)
{

	if(low == high)
	{
		return low;
	}
	 int Pivot = median_pivot(a,low,high);
	 int h = 0;

	 for(h=low;h<= high;h++)
	 {
	 	if(a[h] == Pivot)
	 		break;
	 }
	
	 a[h] = a[high];
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
	 for(i=low;i<=high;i++)
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


int median_pivot(int *a,int low,int high)
{	
	int n = high -low + 1;
	if(n ==1)
	{
		return a[low];

	}

	int i=0;
	for (i=0;i< n/5;i++)
	{
		int j=0;
		for(j=1;j<5;j++)
		{
			int  k= a[i*5 + j + low];
			int l = j-1;
			while(l >= 0 && a[i*5 +l+ low] > k)
			{
				a[i*5 +l+1+ low] = a[i*5 +l+ low];
				l = l-1;
			}
			a[i*5 +l+1+ low] = k;
		}
	}
	int f = 0;
	if(n%5)
	{
		f = 1;
		 int m= n%5;
		 int j=0;
		for(j=1;j<m;j++)
		{
			int  k= a[n/5 + j+ low];
			int l = j-1;
			while(l >= 0 && a[n/5 +l+ low] > k)
			{
				a[n/5 +l+1 + low] = a[n/5 +l + low];
				l = l-1;
			}
			a[n/5 +l+1 + low] = k;
		}

	}
	int *b;

	b = (int *)malloc(sizeof(int)*(n/5 + f));
	for(i =0 ; i< n/5; i++)
		 b[i] = a[i*5 +2 + low];
	int p = n%5;
	if(p)
		if(p%2)
			b[i] = a[n/5 + p/2 + 1 + low];
		else
			b[i] = a[n/5 + p/2 + low];
	int med = median_pivot(b,0,n/5);

		return med;



}