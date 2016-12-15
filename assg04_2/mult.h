#include<stdio.h>
#include<stdlib.h>
#include"add.h"
//#include"assg04_3.c"

char* mult(char *s1,char *s2,int n,char *m)
{
	//printf("\nStarting muly");
	if( n==1 )
	{
		if(s1[0] == 1 && s2[0] == 1)
		{   
			m[0]='1';
			return;
		}
		else
		{
			m[0] = '0';
			return;
		}
	}
	char *a1,*a2,*b1,*b2;
	int na1,na2,nb1,nb2;
	int n1 = n/2;
	if(n%2)
	{	//n1++;
	a1 = (char *)malloc(sizeof(char)*(n1+1+1));
	a2 = (char *)malloc(sizeof(char)*(n1+1+1));
	b1 = (char *)malloc(sizeof(char)*(n1+1+1));
	b2 = (char *)malloc(sizeof(char)*(n1+1+1));

	}
	else
	{
		a1 = (char *)malloc(sizeof(char)*(n1+1));
	a2 = (char *)malloc(sizeof(char)*(n1+1));
	b1 = (char *)malloc(sizeof(char)*(n1+1));
	b2 = (char *)malloc(sizeof(char)*(n1+1));

	}
	substr(s1,a2,n1,n);
	substr(s1,a1,0,n1);
	substr(s2,b2,n1,n);
	substr(s2,b1,0,n1);
	printf("%s = %d \n",a1,stobin(a1,n1));
	printf("%s = %d \n",a2,stobin(a2,n-n1));
	printf("%s = %d \n",b1,stobin(b1,n1));
	printf("%s = %d \n",b2,stobin(b2,n-n1));
	//int m1,m2,m3;
	//m1 = mult(a1,b1,n1);
	//m2 = mult(a2,b2,n-n1);
	//m3 = mult((a1+a2),(b1+b2));
	//return m2 + (m3 - m2 - m1) + m1
	
	
	
//printf("ENding");
	return; //0;
	

}