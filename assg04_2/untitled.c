#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* string_equa(char *a,char *b);
int main()
{ 
	char * s1 = (char*)malloc(sizeof(char )* 4);
	char * s2 = (char *)malloc(sizeof(char)*7);
	s1 = "101";
	s2 = "101101";
	printf("\n %s and %s",s1,s2);
	int s1l, s2l;
	s1l = strlen(s1);
	s2l = strlen(s2);
	if (s1l>s2l)
		s2 = string_equa(s1,s2);
	else if(s2l > s1l)
		s1 = string_equa(s1,s2);

	printf("\n %s and2 %s",s1,s2);
	

}



char* string_equa(char *a,char *b)
{
	int al,bl;
	al  =strlen(a);
	bl = strlen(b);

	if(al > bl)
	{
		//b = (char*)realloc(b,sizeof(char)*(al+1));
		static char *c;
		c = (char*)malloc(sizeof(char)*(al+1));
		int i=0;
		for(i= al-1;i>=(al-bl);i--)
		{
			c[i] = b[i-(al-bl)];
			printf("%c",c[i]);
		}
		//printf("\n");
		for(;i>=0;i--)
		{
			c[i] = '0';
			//printf("%c",c[i]);
		}
		c[al] = '\0';
		return c;
		//b = realloc(b,sizeof(char)*(al+1));
		//stpcpy(b,c);
		//printf("\n%s\n%s\n",a,b);

		

	}
	else if(al<bl)
	{
		static char* c;
		c  = (char*)malloc(sizeof(char)*(bl+1));
		int i=0;
		for(i= bl-1;i>=(bl-al);i--)
		{
			c[i] = a[i-bl+al];
			//printf("%c",c[i]);
		}
		//printf("\n");
		for(;i>=0;i--)
		{
			c[i] = '0';
			//printf("%c",c[i]);
		}
		c[bl] = '\0';
		return c;
		//a = c;
		//printf("\n%s\n%s\n",a,b);
	}
	
}