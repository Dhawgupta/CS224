#include<stdio.h>
#include<time.h>
#include<stdlib.h>
int main(int argc,char* argv[])
{
	if(argc!=2)return 0;
	
	srand(time(NULL));
	int i;
	int n = atoi(argv[1]);
	printf("%d\n",n);
	for(i = 0;i < n;i++)
	{
		printf("%d\n",rand()%10000);
	}
	return 0;
}