#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

struct nodes
{
	int index;
	struct nodes* next;
};

int bfs(int **amatrix,int n,int start,int target,int *parent);
int ford_fulkerson(int **amatrix, int n, int start,int target,int *S,int *T);

int main()
{
	int n,start,i,exit=1,r,c,val,count=0,j,target;
 	printf("Nodes: "); scanf("%d",&n);
	
	printf("\nStart Node: ");scanf("%d",&start); // start is the node number i.e. index +1 
	printf("\nEnd Node: ");scanf("%d",&target);// target = index + 1
	int **adjmatrix = (int **)malloc(n*sizeof(int *));
	for(i=0;i<n;i++)
		adjmatrix[i] = (int *)malloc(n*sizeof(int));
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			adjmatrix[i][j] = 0;	
	while(1)
	{
		scanf("%d",&r);
		if(r == -1)
			break;
		scanf("%d%d",&c,&val);
		adjmatrix[r-1][c-1]  = val;
	}

	int *S = (int *)malloc(sizeof(int)*n);
	int *T = (int *)malloc(sizeof(int)*n);
	memset(T,0,sizeof(T));
	memset(S,0,sizeof(S));
	int max_flow = ford_fulkerson(adjmatrix, n, start,target,S,T);
	printf("The Maximum Flow is : %d \n ",max_flow);
	i=0;
	
	while(i<n)
		if(S[i++] ==1)
		printf("S : %d\n",i);
	i=0;
	while( i<n)
		if(T[i++] ==1)
		printf("T : %d\n",i);


}
int bfs(int **amatrix,int n,int start,int target,int *parent)
{
	//start and target are not the index value i.e.
	// start -1 and target -1 are the index values
	int i,j,k;
	int *visited = (int *)malloc(sizeof(int)*n);
	memset(visited,0,sizeof(visited));
	struct nodes *queue_head = NULL;
	struct nodes *temp = (struct nodes *)malloc(sizeof(struct nodes));
	temp->index = start -1;
	temp->next = NULL;
	queue_head = temp;
	visited[start-1] = 1;
	while(queue_head != NULL)
	{
		
		int ind = queue_head->index;
		queue_head = queue_head->next;
		for(i=0;i<n;i++)
		{
			if(visited[i] == 0 && amatrix[ind][i] != 0)
			{
				
				struct nodes *temp = (struct nodes *)malloc(sizeof(struct nodes));
				temp->index = i;
				temp->next = NULL;
				if 	(queue_head == NULL)
					queue_head = temp;
					
				else
				{
					struct nodes *end = queue_head;
					while(end->next != NULL)
						end = end->next;
					end->next = temp;
				}
				parent[i] = ind;
				visited[i] = 1;

			}

		}

	}

return visited[target-1];

}
int ford_fulkerson(int **amatrix, int n, int start,int target,int *S,int *T)
{
	int i,j,k;
	int s=0,t=0;

	S[start-1] = 1;
	T[target-1] = 1;

	
	
	int **residual = (int **)malloc(sizeof(int *)*n);
	for(i=0;i<n;i++)
		residual[i] = (int *)malloc(sizeof(int)*n);
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			residual[i][j] = amatrix[i][j];
	int *parent = (int *)malloc(sizeof(int)*n);
	memset(parent,-1,sizeof(parent));
	int max_flow = 0;
	while(bfs(residual,n,start,target,parent) != 0)
	{
		int min_flow_path = INT_MAX;
		for(k = target-1;k != start-1;k =parent[k])
		{
			int l = residual[parent[k]][k];
			if(l<min_flow_path){
				min_flow_path = l;
				S[parent[k]] = 1;
				S[k] =0;
				T[k] = 1;
				T[parent[k]] = 0;
			}
			

		}
		for(k = target-1;k != start-1;k =parent[k])
		{
			int p = parent[k];
			residual[p][k] -= min_flow_path;
			residual[k][p] += min_flow_path;


		}
		max_flow += min_flow_path;
		s++;
		t++;


	}
return max_flow;
}