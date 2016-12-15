#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char* add(char *a , char *b ,char c,int n)
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
					carry = 0;
					d[i+1] = '1';
				}
				else
					d[i+1] = '0';
			}

		}

		d[i+1] = (char)(carry + '0');
		d[i+1] = (char)(carry + '0');
		d[n+1] = '\0';
		return d;
		




	}
	else 
	{
		int i=0;
		for(i=0;i<n;i++)
		{
			if(b[i] == '0')
				b[i] = '1';
			else
				b[i] = '0';
		}
		//printf("%s\n",b);
		char *e = add(a,b,'+',n);
		//printf("%s\n",e);
		for(i=0 ; i<n;i++)
			e[i] =e[i+1];
		//e[] ='\0';
		e[n] = '\0';
		//printf("%s\n",e); // e is the sum of a + ~b
		char *f;
		f=  (char*)malloc(sizeof(char)*(n+1));
		for(i=0;i<n;i++)
			f[i] ='0';
		f[n] = '\0';
		f[n-1] = '1';

		printf("%s\n",f);// 0000001
		//int a1 = strlen(e);
		//int a2 =strlen(f);
		//printf("%d  %d \n", a1,a2);
		char *h = add(e,f,'+',n);
		//printf("%s\n",h);
		for(i=0 ; i<n;i++)
			h[i] =h[i+1];
		h[n] ='\0';
		//printf("%s\n",h);
		return h;






		//return 0;
	}
}