#include<stdio.h>
#include<stdlib.h>

char *add(char *a , char *b ,char c,int n)
{
	static char *d;
	d = (char*)malloc(sizeof(char)*(n+2));
	if(c=='+')
	{
		int carry = 0;
		int i=0;
		for(i=n-1;i>= 0;i--)
		{
			if(a[i] == '1' && b[i] == '1')
			{
				if(carry)
				{	
					carry = 1;
					d[i+1] = '1';
				}
				else
				{
					carry = 1;
					d[i+1] = '0';

				}
			}
			else if(a[i] == '1' || b[i] == '1')
			{
				if(carry)
				{
					carry = 1;
					d[i+1] = '0';
				}
				else
				{
					carry = 0;
					d[i+1] ='1';
				}
			}
			else
			{
				if(carry)
				{
					d[i+1] = '1';
				}
				else
					d[i+1] = '0';
			}

		}
		d[i+1] = (char)(carry + '0');
		return d;
		




	}
	else 
	{
		return 0;
	}
}