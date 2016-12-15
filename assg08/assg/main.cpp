#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct adjlist
{
	char word[6];
	int index;
	int visit;
}
int main()
{
	printf(">");
	int n;
	scanf("%d", &n);
	struct adjlist *nodes = (struct *adjlist)malloc(sizeof(struct adjlist)*n);
	int i=0;
	for(i=0;i<n;i++){ // Input for the nodes
		scanf("%s",nodes[i].word);
		nodes[i].index = i;
	}
	int **adjmatrix = (int **)malloc(n*sizeof(int *));
	for(i=0;i<n;i++)
		arr[i] = (int *)malloc(n*sizeof(int));
	int j;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			adjmatrix[i][j] = 0;
	build_graph(nodes,adjmatrix,n);

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
void build_graph(struct adjlist *nodes,int **adjm,int n)
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			int val = check_difference(nodes[i].word,nodes[j].word);
			if(val == 4)
				adjm[i][j] = 1;
		}
	}
}
int calc_cost(char *word1 , char *word2)//Function to calucate the cost between 2 words
{


}