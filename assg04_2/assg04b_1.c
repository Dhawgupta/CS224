// !SOMETIMES THE WHILE RUNNING THE SHELL SCRIPT THE MEMORY WAS NOT ALLOCATING PROPERLY
/*
myqort1: malloc.c:2395: sysmalloc: Assertion `(old_top == initial_top (av) && old_size == 0) || ((unsigned long) (old_size) >= MINSIZE && prev_inuse (old_top) && ((unsigned long) old_end & (pagesize - 1)) == 0)' failed.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void quicksort(int *,int ,int);
int median_pivot(int*,int,int);
int nn;
int main()
{
	scanf("%d",&nn); // Enter the number of values
	int *a = (int *)malloc(sizeof(int)*nn); // allocate the memory
	int i=0;
	for(i=0;i<nn;i++)
		scanf("%d",&a[i]); // taking in the values
	
	quicksort(a,0,nn-1);	//calling the quicksort function 
}
int quicksort_part(int *a, int low,int high) // Partition function for quicksort
{

	if(low == high) //Base Case
	{
		return low;
	}
	 int Pivot = median_pivot(a,low,high); // Return the indice of median
	 int h = 0;
	 // The Partition part 
	 //printf("the Median is %d \n",Pivot);
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
	 return l+1; // Return the place of the Pivot
}
int find_pos(int *a, int low,int high,int Pivot) // Partition function for quicksort
{

	 // Return the indice of median
	 int h = 0;
	 // The Partition part 
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
	 return l+1; // Return the place of the Pivot
}
void quicksort(int *a,int low,int high)
{ 
	if(low < high)
	{
		int x = quicksort_part(a,low,high); 
		quicksort(a,low,x-1);
		quicksort(a,x+1,high);
	}
}
int median_pivot(int *a,int low,int high)
{	
	int n = high -low + 1;
	if(n  <= 2) // Base Case
	{
		return a[low];
	}
	int i=0;
	for (i=0;i< n/5;i++) // Runnning the N/5 Partition of this
	{
		int j=0;
		for(j=1;j<5;j++)
		{
			int  k= a[i*5 + j + low]; // insertion Sort
			int l = j-1;
			while(l >= 0 && a[i*5 +l+ low] > k)
			{
				a[i*5 +l+1+ low] = a[i*5 +l+ low]; 
				l = l-1;
			}
			a[i*5 +l+1+ low] = k;
		}
	}
	int f = 0; //  THe resukting array has median of n/5 sybgroups in middle
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
	int *b; // B is the new array containg the n/5 medians

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
	// Checking for if med is median
	int pos = find_pos(a,low,high,med);
	if(pos < nn/2)
		med = median_pivot(a,pos+1,high);
	else if(pos > nn/2)
		med = median_pivot(a,low,pos-1);// Finding the median
	return med;
}
