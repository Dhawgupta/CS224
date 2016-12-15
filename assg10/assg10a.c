#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
struct nodes
{	
	int index; // one greater than the index of the array i.e. house numbre
	unsigned int cost;
	int parent;
};
void find_min_path(struct nodes *node,int n,int **adjm,int start); // find the shortest path

int main()
{
	int n,start,i,exit=1,r,c,val,count=0,j;
 	printf("Nodes: "); scanf("%d",&n);
	struct nodes *node = (struct nodes *)malloc(sizeof(struct nodes)*n);
	for(i=0;i<n;i++)
		node[i].index = i+1;
	printf("\nStart Node: ");scanf("%d",&start);
	//printf("\nStarting Matrix initisilaixtion\n");
	int **adjmatrix = (int **)malloc(n*sizeof(int *));
	for(i=0;i<n;i++)
		adjmatrix[i] = (int *)malloc(n*sizeof(int));
	//printf("\n Finished Creating MAtrix now intiilazing");
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			adjmatrix[i][j] = -1;
	//printf("\nEnding Matrix Initialzaion");
	while(1)
	{
		scanf("%d",&r);
		if(r == -1)
			break;
		scanf("%d%d",&c,&val);
		adjmatrix[r-1][c-1]  = val;
	}
	for(i=0;i<n;i++){
		for(j=0;j<n;j++)
			printf("%d ",adjmatrix[i][j]);
		printf("\n");
	}
}

int left(int i)
{
	return 2*i;
}
int right(int i)
{
	return 2*i +1 ;
}
int parent(int i)
{
	return i/2;
}
void min_heapify(struct nodes *node,int *heap,int i, int heap_size) // function to heapify a ceratin node of th heap 
{
	int l,r;
	l = left(i);
	r = right(i);
	int smallest;
	if(l <= heap_size && node[heap[l]].cost < node[heap[i]].cost )
		smallest = l;
	else
		smallest = i;
	if(r <= heap_size && node[heap[r]].cost < node[heap[smallest]].cost )
		smallest = r;
	if(smallest !=i)
	{
		int temp = heap[i];
		heap[i] = heap[smallest];
		heap[smallest] = temp;
		min_heapify(node,heap,smallest,heap_size);
	}	
}
void build_heap(struct nodes *node,int *heap,int heap_size)// function to build heap
{
	int i=0;
	for(i=heap_size/2;i>=1;i--)
		min_heapify(node,heap,i,heap_size);
}
