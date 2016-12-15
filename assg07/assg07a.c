#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct adjlistnode // Adj List
{
	char word[6];
	int index;
	int visit;
	int color; // 0 - white, 1 - gray, 2 - black
	int parent;
	struct adjlistnode *next;
};
void build_graph(struct adjlistnode *,int ); // To build the graph
int check_difference(char *,char *); //  Check the diffreence between two nodes
void print_graph(struct adjlistnode *, int); // Print the Graph
int connectedcount(struct adjlistnode *graph,int n);
void find_connections(struct adjlistnode * graph,int i,int *visited,int n);	
int *conn_comp_ind;
void try(struct adjlistnode *graph, int n); // To find Cycles
int try_v(struct adjlistnode  *graph, int i); // Recursive function to find cyclic part
void print_cycle2(struct adjlistnode *graph,int end ,int main); // TO print cycles


int main()
{
	printf(">");
	int n;
	scanf("%d", &n);
	struct adjlistnode *graph  = (struct adjlistnode *)malloc(sizeof(struct adjlistnode)*n); // the adj list
	int i=0;
	for(i=0;i<n;i++) // Input for the nodes
	{
		scanf("%s",graph[i].word);
		graph[i].index = i;
		graph[i].next = NULL;
	}
	printf("\nThe list is :\n");
	conn_comp_ind  = (int *)malloc(sizeof(int)*n); // Containig the first component of each connected component list 
	for(i=0;i<n;i++)
		printf("%d %s\n",graph[i].index,graph[i].word);
	build_graph(graph,n); 
	int count = connectedcount(graph,n); // Number of connected components
	printf("\nThe Number of connected components is %d",count);
	conn_comp_ind  = (int *)realloc(conn_comp_ind,sizeof(int)*count);
	printf("Printing Cycle :\n"); 
	try(graph,n); // Printing Cycles
	return 0;
}
struct adjlistnode *temp_parent = NULL;
void try(struct adjlistnode *graph, int n) // Looking for cycles
{
	int i=0;int flag =0;
	for(i =0; i<n;i++) //  Reinitilize all the fals in node to beg
	{
		graph[i].color = 0;
		graph[i].parent = -1;
		graph[i].visit = 0;
	}
	for(i=0;i<n;i++)
	{

		if(graph[i].visit == 0) // Call dfs - check for non visited nodes
			flag = try_v(graph,i);
		if(flag)
			break; // Flag to check for if 1 cycle is printed or not 
	}
	if(flag == 0)
		printf("\nNo cycles in the Graph");
}
int try_v(struct adjlistnode  *graph, int i)//,int f) // f is 0 when coming from try and f - 1 when coming form try_v
{
	graph[i].visit = 1; // Marking node as visited
	struct adjlistnode *temp = graph[i].next;
	while(temp != NULL)
	{
		if(graph[temp->index].visit == 0)
		{
			graph[temp->index].parent = i;
		    return try_v(graph,temp->index); //  Recursive Call
		}
		else
		{
			if(graph[i].parent  != temp->index)
			{	
				//printf("\nGoing Good %d ",temp->index);
				print_cycle2(graph, i,temp->index);
				return 1;
			}	
		}
		temp = temp->next;
	}
	return 0;	
}
// end - the end node of the cycle
// main - the head node of cycle
void print_cycle2(struct adjlistnode *graph,int end ,int main) // Printing the cycle
{
	if( end < 0 || main < 0) // The base condition
		return;
	int i,j,k;
	printf("\n\n");
	printf("%s > ",graph[main].word); // Printing the main node
	printf("%s > ",graph[end].word);
	end = graph[end].parent;
	while(1) // printing the rest of the cycle
	{
		printf("%s > ",graph[end].word);
		struct adjlistnode *temp = graph[end].next;
		while(temp!=NULL)
		{
			if(temp->index == graph[main].index)
			{
				printf("%s > ",graph[main].word);
				return; /// return on finding the main node again
			}
			temp = temp->next;
		}
		end = graph[end].parent;
	}
}
int connectedcount(struct adjlistnode *graph,int n)
{
	int count = 0; // count for connected components
	int *visited  = (int *)malloc(sizeof(int)*n);
	int i=0;
	for(i=0;i<n;i++)
		visited[i] = 0;
	for(i=0;i<n;i++)
	{
		if(visited[i] == 0){
			conn_comp_ind[count] = i;
			count++;
			printf("\nConnected Comp %d: ",count);
			find_connections(graph,i,visited,n); // Running dfs from that node to find the all the coneected nodes
		}	
	}
	return count;
}
void find_connections(struct adjlistnode * graph,int i,int *visited,int n) // find connections 
{
	visited[i] = 1;
	printf("%s > ",graph[i].word);
	struct adjlistnode *temp  = graph[i].next;
	while(temp != NULL)
	{

		if(visited[temp->index] == 0){
			//printf("%s > ",temp->word);	
			find_connections(graph,temp->index,visited,n);
		}
		temp = temp->next;
	}
}
void print_graph(struct adjlistnode *graph,int n) // Print the graph 
{
	int i=0;
	for(i=0;i<n;i++)
	{
		printf("%s > ",graph[i].word);
		struct  adjlistnode *temp = graph[i].next;
		
		while(temp != NULL)
		{
			printf("%s >",temp->word);
			temp = temp->next;
			
		}
		
		printf("\n");
	}
}
void build_graph(struct adjlistnode *graph, int n) // Building the graph for checking the diffenece
{
	int i=0,j=0,k=0;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			int d = check_difference(graph[i].word,graph[j].word);
			if(d==1)
			{
				struct adjlistnode *temp = (struct adjlistnode *)malloc(sizeof(struct adjlistnode));
				for(k=0; k<5;k++){
					temp->word[k] = graph[j].word[k];
					temp->index = graph[j].index;
				}
				temp->word[5] = '\0';
				temp->next = NULL;
				struct adjlistnode *tail = &graph[i];
				while(tail->next != NULL)
					tail = tail->next;
				tail->next = temp;
			}
		}
	}
}
int check_difference(char *a,char *b) // check the difference
{
	int flag =0;
	int i=0;
	for(i=0;i<5;i++)
		if(a[i] != b[i])
			flag++;
	return flag;
}