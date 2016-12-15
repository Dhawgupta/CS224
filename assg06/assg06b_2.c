#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int m1[100][100],split[100][100];
// m1[pegs][disks]
// split[pegs][disk]
void modified_toh(int disk, int peg)
{
	for(int i=1;i<=disk;i++)
		m1[3][i] = (1<<i) -1;
	for(int i=3;i<=peg;i++)
		m1[i][1] = 1;

	for(int j=4;j<=peg;j++) // The Pegs
	{
		for(int i=2;i<=disk;i++) // The Disks considered 
		{
			unsigned int q = 1<<30;
			for(int k=1;k<i;k++) // Splitting of the disks
			{
				int t = 2*m1[j][k] + m1[j-1][i-k];
				if(t<q)
				{
					q = t;
					split[j][i] = k;
				}
			}
			m1[j][i] = q;
		}
	}
}
int main()
{
	memset(m1,-1,sizeof(m1));
	memset(split,-1,sizeof(split));
	
	int disk,peg;
	printf("Enter the value of disks and pegs : "); // Entering the value of disks and pegs
	scanf("%d%d",&disk,&peg);
	modified_toh(disk,peg);
	printf("	TABLE FOR NO OF STEPS \n"); // printing the table of steps

	printf("Disks > ");
	for(int i=1;i<=disk;i++)
		printf(" %d",i);
	printf("\n");
	for(int i=3;i<=peg;i++)
	{
		printf("peg(%d)>  ",i);
		for(int j=1;j<=disk;j++)
		{
			printf("%d ",m1[i][j]);
		}
		printf("\n");
	}
	printf("	TABLE FOR NO OF SPLITTING \n"); // prining the splitiing table

	printf("Disks > ");
	for(int i=2;i<=disk;i++)
		printf(" %d",i);
	printf("\n");
	for(int i=4;i<=peg;i++)
	{
		printf("peg(%d)>  ",i);
		for(int j=2;j<=disk;j++)
		{
			printf("%d ",split[i][j]);
		}
		printf("\n");
	}
	printf("\nSplit : %d\nSoln : %d\n",split[peg][disk],m1[peg][disk]);

}	