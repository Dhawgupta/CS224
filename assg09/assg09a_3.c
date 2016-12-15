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
		adjmatrix[r-1][c-1] = adjmatrix[c-1][r-1] = val;
	}
	for(i=0;i<n;i++){
		for(j=0;j<n;j++)
			printf("%d ",adjmatrix[i][j]);
		printf("\n");
	}
	find_min_path(node,n,adjmatrix,start-1);//Passing start-1 beacuse start is the house number and start-1 is the indice
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
void find_min_path(struct nodes *node,int n,int **adjm,int start) // find the shortest path
{
	int i=0,count=0,max_cost = 0;
	for(i=0;i <n;i++){
		node[i].cost = INT_MAX;
		node[i].parent = -1;
	}
	node[start].cost =0;
	int *heap = (int *)malloc(sizeof(int)*(n+1));
	heap[1] = start;

	int heap_size = 1;
	int **edges = (int **)malloc(sizeof(int *)*(n));
	for(i=0;i<n;i++)
		edges[i] = (int *)malloc(sizeof(int)*3);
	while(heap_size >0  && count < n-1)
	{
		int i,j,k;
		int ind = heap[1];
		
		if(ind != start)
		{
			if(max_cost < node[ind].cost)
				max_cost = node[ind].cost;
			edges[count][0] = ind;
			edges[count][1] = node[ind].parent;
			edges[count][2] = node[ind].cost;
			count++;

		}
		heap[1] = heap[heap_size];
		heap_size--;
		for(i=0;i<n;i++)
		{
			if(adjm[ind][i] != -1 && ind != i)
			{
				if(adjm[ind][i]  < node[i].cost)
				{
					
					if(node[i].cost  == INT_MAX)
						heap[++heap_size] = i;
					node[i].cost = adjm[ind][i] ;
					node[i].parent = ind;
				}
			}
		}
		build_heap(node,heap,heap_size);
	}
	if(count  == n-1){
		printf("Done\n");
		for(i= 0;i<count;i++)
			printf("Node : %d to Node :%d\n",edges[i][1] + 1,edges[i][0] + 1);
		printf("\nThe max Jump need to be taken is : %d \n",max_cost);
	}
	else
		printf("\nSorry Problem \n");
}