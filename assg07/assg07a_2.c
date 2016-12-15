#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//#define char [5] wordn
struct adjlistnode
{
	char word[6];
	int index;
	int visit;
	int color; // 0 - white, 1 - gray, 2 - black
	struct adjlistnode *parent;
	struct adjlistnode *next;
};
//int connectedcomponent_count = 0;
void build_graph(struct adjlistnode *,int );
int check_difference(char *,char *);
void print_graph(struct adjlistnode *, int);
int connectedcount(struct adjlistnode *graph,int n);
void find_connections(struct adjlistnode * graph,int i,int *visited,int n);	
int *conn_comp_ind;
void try(struct adjlistnode *graph, int n);
void try_v(struct adjlistnode  *graph, int i);
void print_cycle(struct adjlistnode *graph,int,int);


int main()
{
	
	printf(">");
	int n;
	scanf("%d", &n);
	struct adjlistnode *graph  = (struct adjlistnode *)malloc(sizeof(struct adjlistnode)*n);
	int i=0;
	for(i=0;i<n;i++)
	{
		scanf("%s",graph[i].word);
		graph[i].index = i;
		graph[i].next = NULL;
	}
	printf("\nThe list is :\n");
	conn_comp_ind  = (int *)malloc(sizeof(int)*n);
	for(i=0;i<n;i++)
		printf("%d %s\n",graph[i].index,graph[i].word);
	build_graph(graph,n);
	
	print_graph(graph,n);
	int count = connectedcount(graph,n);
	printf("\nThe Number of connected components is %d  : ",count);
	conn_comp_ind  = (int *)realloc(conn_comp_ind,sizeof(int)*count);
	try(graph,n);
}
struct adjlistnode *temp_parent = NULL;
void try(struct adjlistnode *graph, int n)
{
	int i=0;
	for(i =0; i<n;i++)
	{
		graph[i].color = 0;
		graph[i].parent = NULL;
		graph[i].visit = 0;
	}
	for(i=0;i<n;i++)
	{
		if(graph[i].visit == 0)
			try_v(graph,i);
	}
}
void try_v(struct adjlistnode  *graph, int i)//,int f) // f is 0 when coming from try and f - 1 when coming form try_v
{
	graph[i].visit = 1;
	struct adjlistnode *temp = graph[i].next;
	while(temp != NULL)
	{
		if(graph[temp->index].visit == 0)
		{
			graph[temp->index].parent = &graph[i];
			try_v(graph,temp->index);
		}
		else
		{
			if(strcmp(graph[i].parent->word  ,graph[temp->index].word))
				print_cycle(graph, i,temp->index);			
		}
		temp = temp->next;
	}	
}
void print_cycle(struct adjlistnode *graph,int end,int main)
{
	printf("\n\n");
	printf("%s > ", graph[main].word );
	printf("%s > ", graph[end].word);
	int i=0;
	for(i=0;i<(1<<30);i++);
	end  = graph[end].parent->index;
	while(1)
	{	
	    printf("%s > ",graph[end].word);
		struct adjlistnode *temp = graph[end].next;
		while(temp != NULL)
		{
			if(temp  == &graph[main])
			{
				printf("%s > ", graph[main].word );
				return;

			}
			temp = temp->next;
		}
		end  = graph[end].parent->index;	
	}
}
int connectedcount(struct adjlistnode *graph,int n)
{
	int count = 0;
	int *visited  = (int *)malloc(sizeof(int)*n);
	int i=0;
	for(i=0;i<n;i++)
		visited[i] = 0;
	for(i=0;i<n;i++)
	{
		if(visited[i] == 0){
			conn_comp_ind[count] = i;
			count++;
			find_connections(graph,i,visited,n);
		}	
	}
	return count;
}
void find_connections(struct adjlistnode * graph,int i,int *visited,int n)
{
	visited[i] = 1;
	struct adjlistnode *temp  = graph[i].next;
	while(temp != NULL)
	{
		if(visited[temp->index] == 0)
			find_connections(graph,temp->index,visited,n);
		temp = temp->next;
	}

}

void print_graph(struct adjlistnode *graph,int n)
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
void build_graph(struct adjlistnode *graph, int n)
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
int check_difference(char *a,char *b)
{
	int flag =0;
	int i=0;
	for(i=0;i<5;i++)
		if(a[i] != b[i])
			flag++;
	return flag;
}