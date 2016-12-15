#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define INT_MAX 1<<31

struct adjlist
{
	char word[6];
	int index;
	int visit;
	unsigned int  cost;
	int parent;
	int left;
	int right;
};

void build_graph(struct adjlist *nodes,int **adjm,int n);
void print_shortest_path(struct adjlist *nodes,int n,int **adjm,int i1,int i2);
int calc_cost(char *word1 , char *word2);

int main()
{
	printf(">");
	int n;
	scanf("%d", &n);
	struct adjlist *nodes = (struct adjlist *)malloc(sizeof(struct adjlist)*n);
	int i=0;
	for(i=0;i<n;i++){ // Input for the nodes
		scanf("%s",nodes[i].word);
		nodes[i].index = i;
	}
	int **adjmatrix = (int **)malloc(n*sizeof(int *));
	for(i=0;i<n;i++)
		adjmatrix[i] = (int *)malloc(n*sizeof(int));
	int j;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			adjmatrix[i][j] = 0;
	
	build_graph(nodes,adjmatrix,n);
	int k=0;
	/*
	for(i=0;i<n;i++){
		for(j=0;j<n;j++)
			printf("%d ",adjmatrix[i][j]);
		printf("\n");
	}
	*/
	do
	{

		printf("Enter the 2 words\n >");
		char a[6],b[6];
		scanf("%s%s",a,b);
		int ind1 = -1,ind2 = -1;
		for(i=0;i<n;i++)
		{
			if(strcmp(a,nodes[i].word) == 0)
				ind1 = i;
			if(strcmp(b,nodes[i].word) == 0)
				ind2 = i;
		}
		if(ind1 == -1 || ind2 == -1){
			printf("\nOnes of Words Doesnt exist in the list");
			continue;
		}
		

		print_shortest_path(nodes,n,adjmatrix,ind1,ind2);
		printf("\nContinue (1/-1) : ");scanf("%d",&k);
	}while(k != -1);
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
void max_heapify(struct adjlist *nodes,int *heap,int i, int heap_size)
{
	int l,r;
	l = left(i);
	r = right(i);
	int smallest;
	if(l <= heap_size && nodes[heap[l]].cost < nodes[heap[i]].cost )
		smallest = l;
	else
		smallest = i;
	if(r <= heap_size && nodes[heap[r]].cost < nodes[heap[smallest]].cost )
		smallest = r;
	if(smallest !=i)
	{
		int temp = heap[i];
		heap[i] = heap[smallest];
		heap[smallest] = temp;
		max_heapify(nodes,heap,smallest,heap_size);
	}	
}
void build_heap(struct adjlist *nodes,int *heap,int heap_size)
{
	int i=0;
	for(i=heap_size/2;i>=1;i--)
		max_heapify(nodes,heap,i,heap_size);
}

void print_path(struct adjlist * nodes, int n1,int n2)
{
	if (n1 == n2)
	{
		printf("\n%s",nodes[n1].word);
		return;
	}
	print_path(nodes,n1,nodes[n2].parent);
	printf(" -> %s",nodes[n2].word);
}
void print_shortest_path(struct adjlist *nodes,int n,int **adjm,int i1,int i2)
{
	int i=0;
	for(i=0;i <n;i++){
		nodes[i].cost = INT_MAX;
		nodes[i].parent = -1;
	}
	nodes[i1].cost =0;
	int *heap = (int *)malloc(sizeof(int)*(n+1));
	heap[1] = i1;

	int heap_size = 1;
	while(heap_size >0  && heap[1] != i2)
	{
		int i,j,k;
		int ind = heap[1];
		heap[1] = heap[heap_size];
		//max_heapify(nodes,heap,1,heap_size-1);
		heap_size--;
		for(i=0;i<n;i++)
		{
			if(adjm[ind][i] != 0 && ind != i)
			{
				if(adjm[ind][i] + nodes[ind].cost < nodes[i].cost)
				{
					
					if(nodes[i].cost  == INT_MAX)
						heap[++heap_size] = i;
					nodes[i].cost = adjm[ind][i] + nodes[ind].cost;
					nodes[i].parent = ind;
				}
			}
		}
		build_heap(nodes,heap,heap_size);
		//printf("\nNodes %s",nodes[ind].word);

	}
	if(heap[1] == i2){
		print_path(nodes,i1,i2);
		int k =i2;
		while(k != i1)
		{
			printf("%s ->",nodes[k].word);
			k = nodes[k].parent;
		}
		printf("%s \n",nodes[k].word);
		printf("\nTHe cost is %d \n",nodes[i2].cost);
	}
	else
		printf("\nSorry No Path found \n");
}
int check_difference(char *a,char *b) // check the difference
{
	int flag =0;
	int i=0;
	for(i=0;i<5;i++)
		if(a[i] == b[i])
			flag++;
	return flag;
}
void build_graph(struct adjlist *nodes,int **adjm,int n)
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
		
				int val = check_difference(nodes[i].word,nodes[j].word);
			
				if(val == 4)
					adjm[i][j] = calc_cost(nodes[i].word,nodes[j].word);
				

		}

	}
}
int calc_cost(char *word1 , char *word2)//Function to calucate the cost between 2 words
{
	int i=0,j=0;
	for(i=0;i<5;i++)
		j += word1[i] - word2[i];
	if(j<0)
		return -j;
	else 
		return j;

}