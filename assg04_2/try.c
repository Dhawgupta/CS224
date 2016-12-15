#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include<string.h>

int select_random_pivot(int low,int high)
{
	printf("In Select Random\n");
	srand(time(NULL));
	int r = (high-low)*((float)(rand())/RAND_MAX) + low;
	return r; 

}

int main()
 {
 	while(1)
 	printf("Value between 50 and 100 is : %d", select_random_pivot(50,100));

 	return 0;


 }
