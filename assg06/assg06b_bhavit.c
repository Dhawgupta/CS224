#include <stdio.h>
#include <stdlib.h>
#include  <string.h>

int arr[100][100];

int try(int disk, int pegs)
{	
	unsigned int min  = 1<<30;
	 if(disk == 1)
		return 1;
	if(pegs == 3)
		return (1<<disk)-1;
	if(arr[disk][pegs] != -1) return arr[disk][pegs];
	
	for (int i = 1; i < disk; ++i)
	{
		int t = 2*try(i,pegs) + try(disk -i, pegs -1);
		if(min > t)
			min = t;

		/* codzye */
	}

	return arr[disk][pegs] = min;

}
int main()
{
	memset(arr,-1,sizeof(arr));
	int n,p;
	scanf("%d%d",&n,&p);
	int min = try(n,p);
	printf("%d\n", min);

	
}