#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void string_equa(char *a,char *b)
{
	int al,bl;
	al  =strlen(a);
	bl = strlen(b);

	if(al > bl)
	{
		//b = (char*)realloc(b,sizeof(char)*(al+1));
		char* c = (char*)malloc(sizeof(char)*(al+1));
		int i=0;
		for(i= al-1;i>=(al-bl);i--)
		{
			c[i] = b[i-al+bl];
			printf("%c",c[i]);
		}
		printf("\n");
		for(;i>=0;i--)
		{
			c[i] = '0';
			printf("%c",c[i]);
		}
		c[al] = '\0';
		b = c;
		printf("\n%s\n%s\n",a,b);

		

	}
	else if(al<bl)
	{
		char* c = (char*)malloc(sizeof(char)*(bl+1));
		int i=0;
		for(i= bl-1;i>=(bl-al);i--)
		{
			c[i] = b[i-bl+al];
			printf("%c",c[i]);
		}
		printf("\n");
		for(;i>=0;i--)
		{
			c[i] = '0';
			printf("%c",c[i]);
		}
		c[bl] = '\0';
		a = c;
		printf("\n%s\n%s\n",a,b);
	}
	return;
}

int main()
{
	 char *a,*b;
	 a = (char*)malloc(sizeof(char)*10);
	 b = (char*)malloc(sizeof(char)*6);
	 a = "THis8isy7";
	 b = "10110";
	 printf("\n%s\n%s\n",b,a);
	 string_equa(a,b);

}