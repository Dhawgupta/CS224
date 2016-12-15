/* Working with 4 Pegs */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
int m1[100][100],split[100][100];
// m1[pegs][disks]
// split[pegs][disk]
void modified_toh(int disk, int peg)
{
	int i,j,k;
        for( i=1;i<=disk;i++)
                m1[3][i] = (1<<i) -1;
        for( i=3;i<=peg;i++)
                m1[i][1] = 1;

        for( j=4;j<=peg;j++) // The Pegs
        {
                for( i=2;i<=disk;i++) // The Disks considered 
                {
                        unsigned int q = 1<<30;
                        for( k=1;k<i;k++) // Splitting of the disks
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
void tower_of_hanoi(char source,char destination,char misc,int n,int start)
{
       
	int i;
        if(n ==1)
        { 
 		printf("Move from %c to %c\n",source,destination); 
                return;
        }
        tower_of_hanoi(source,misc,destination,n-1,start);
        printf("Move from %c to %c \n",source,destination);
        
        tower_of_hanoi(misc,destination,source,n-1,start);
         // Returning the steps
}
char splitting(int p,int d,char *pegs,int start) // return the character containing the tower in the end
{	
	int i,j;        
        if(p<4)
	{	
		tower_of_hanoi(pegs[0] , pegs[2], pegs[1], d,start);
                return pegs[2];
	}

        if(d<2)
	{
		printf("%d from %c to %c\n",start, pegs[0] , pegs[2]);               
		return pegs[2];
	}
	 //printf("split at > %d \n",split[p][d]);
	int splt = split[p][d];
	char rm = splitting(p ,splt, pegs,start);
	char *pegs2 = (char *)malloc(sizeof(char)*(p-1));
	for(i =0, j=0 ; i<p ; i++)
		if(rm == pegs[i])
			continue;
		else
			pegs2[j++] = pegs[i];
	char rm2 = splitting(p-1,d -splt,pegs2, splt + 1);
	char rm3 = splitting(p,splt, pegs,start);
	
	 

}
char print_moves(int peg, int disk, char *pegs, char startpeg, int startdisk , char finalpeg)
{
	int i,j; int k1,k2;        
	for(i= 0;i < peg; i++)
	{	if(pegs[i] == startpeg)
			k1= i;
		if(pegs[i] == finalpeg)
			k2 = i;
	}
			
		
    if(peg<4)
	{	
		tower_of_hanoi( startpeg, finalpeg,pegs[peg -k1-k2], disk,startdisk);
                return finalpeg;
	}
	if(disk<2)
	{	
		
		printf("Move from %c to %c\n",startpeg ,finalpeg);               
		return finalpeg;
	}
	int splt = split[peg][disk];
	srand(time(NULL));
	int r;	
	do{
    r = (peg-1)*((float)(rand())/RAND_MAX);
	}while(r == k1 || r == k2);
	char endpeg1 = print_moves(peg,splt, pegs, startpeg, startdisk,pegs[r]);
	char *pegs2 = (char *)malloc(sizeof(char)*(peg-1));
	for(i =0, j=0 ; i<peg ; i++)
		if(i == r)
			continue;
		else
			pegs2[j++] = pegs[i];

	char endpeg2 = print_moves(peg -1 ,disk - splt, pegs2, startpeg, splt+1,finalpeg);
	char endpeg3 = print_moves(peg , splt, pegs, pegs[r], startdisk, finalpeg);
}		
int main()
{
        memset(m1,-1,sizeof(m1));
        memset(split,-1,sizeof(split));
        int i,j,k;
        int disk,peg;
        printf("Enter the value of disks and pegs : "); // Entering the value of disks and pegs
        scanf("%d%d",&disk,&peg);
        modified_toh(disk,peg);
        printf("        TABLE FOR NO OF STEPS \n"); // printing the table of steps
	
    char *pegs = (char *)malloc(sizeof(char)*peg);
	for(i=0; i< peg; i++)
		pegs[i] = 'a' + i;        
	

    printf("Disks > ");
        for( i=1;i<=disk;i++)
                printf(" %d",i);
        printf("\n");
        

        for( i=3;i<=peg;i++)
        {
                printf("peg(%d)>  ",i);
                for( j=1;j<=disk;j++)
                {
                        printf("%d ",m1[i][j]);
                }
                printf("\n");
        }
      

        printf("        TABLE FOR NO OF SPLITTING \n"); // prining the splitiing table
        printf("Disks > ");
        for( i=2;i<=disk;i++)
                printf(" %d",i);
        printf("\n");
        for( i=4;i<=peg;i++)
        {
                printf("peg(%d)>  ",i);
                for( j=2;j<=disk;j++)
                {
                        printf("%d ",split[i][j]);
                }
                printf("\n");
        }
        
        printf("\nSplit : %d\nSoln : %d\n",split[peg][disk],m1[peg][disk]);
        //splitting(peg,disk,pegs,1);
		
        char startpeg = 'a';
		int startdisk = 1;
		char finalpeg = 'a'+ peg-1;
		
        char fpeg = print_moves(peg,disk, pegs, startpeg,startdisk ,finalpeg);
		printf("\nThe Final peg is : %c\n",finalpeg);
}        


