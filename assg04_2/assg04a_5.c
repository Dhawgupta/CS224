#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//#include"add.h"
char * add_at_end(char *,int);
char* string_equa(char *,char *);
char* add(char * , char * ,char  );
int stobin(char*,int);
void substr(char *,char *,int,int);
char* mult(char *,char *,int n);
void bintos(int,char *);
void sum(char *,char *,char *,char);
//int strlen(char *);
int main()
{
	 printf("Enter the Number of elements in Both Number's : ");
	 int n;
	 // Taking in  the N bit integer
	 scanf("%d",&n);   
	 char *s1= (char *)malloc(sizeof(char)*n);
	 char *s2 = (char *)malloc(sizeof(char)*n);
	 printf("\nEnter the String : \n");
	 scanf("%s%s",s1,s2);
	 printf("\n%s\n%s",s1,s2);
	 //debug step
	 printf("\n\n%d\n%d\n",stobin(s1,n),stobin(s2,n));
	 char * m  = mult(s1,s2,n);
	 int l = strlen(m);
	 printf("\n-------------------------------\n");
	 printf("%s\n%d\n",m,stobin(m,l));
	 printf("\n-------------------------------\n");
	 return 0;
}	
char* mult(char *s1,char *s2,int n)
{

	printf("\nStarting mulyn\n %s and %s", s1,s2);
	//int k=0;
	//for(k=0;k<1000000000;k++);

	int s1l, s2l;
	s1l = strlen(s1);
	s2l = strlen(s2);
	if (s1l>s2l)
	{
		s2 = string_equa(s1,s2);
		n = s1l;
	}
	else if(s2l > s1l)
	{
		s1 = string_equa(s1,s2);
		n = s2l;
	}
	else
		n = s2l;
	//int n = (strlen(s1)>strlen(s2)?strlen(s1):strlen(s2));
	static char *m;
	
	if( n <= 2 )
	{
		m = (char *)malloc(sizeof(char)*(n+1));
		if(n<2)
		{			
		if(s1[0] == '1' && s2[0] == '1')
		{   
			m[0]='1';
			//m[1] = '\0';
			return m;
		}
		else
		{
			m[0] = '0';
			//m[1] = '\0';
			return m;
		}
		}
		else
		{
			if (s1[0] == '0' && s2[0] == '0')
			{
				m = (char*)malloc(sizeof(char)*2);
				if(s1[1] == '1')
				{
					if (s2[1] == '1')
					{
						m[0] = '1';
						m[1] = '\0';
						return m;
					}
					else 
					{
						m[0] = '0';
						m[1] = '\0';
						return m;
					}
				}
				else
				{
					m[0] = '0';
					m[1] = '\0';
					return m;
				}
		}
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
	char *m1,*m2,*m3;
	m1 = mult(a1,b1,n1);
	m2 = mult(a2,b2,n-n1);
	//m3 = mult(add(a1,a2,'+',n-n1),add(b1,b2,'+',n-n1),n-n1+1);
	m3 = mult(add(a1,a2,'+'),add(b1,b2,'+'),n1+1);
	printf("\n m3 %s \n",m3);
	char *m4 = add(m3,m1,'-');
	m4 = add(m4,m2,'-');
	printf("\nm4 %s \n",m4);

	m = (char *)malloc(sizeof(char)*(2*n+1));
	int i;
	for(i=0;i<2*n;i++)
		m[i] = '0';
	m = add(m,m2,'+');
	int z = n/2;
	if(n%2)
		z++;
	printf("\n\n\n m %s %d\nm1 %s %d\nm2 %s %d\nm3 %s %d",m,stobin(m,3),m1,stobin(m1,3),m2,stobin(m2,3),m3,stobin(m3,3));
	m3 = add_at_end(m3,z+1);
	m1 = add_at_end(m1,n);
	printf("\n\n\n m %s %d\nm1 %s %d\nm2 %s %d\nm3 %s %d",m,stobin(m,3),m1,stobin(m1,3),m2,stobin(m2,3),m3,stobin(m3,3));
	m  = add(m,m2,'+');
	printf("\n%s %d",m,stobin(m,3));
	m  = add(m,m1,'+');
	printf("\n%s %d",m,stobin(m,3));

	return m;

}
char* add_at_end(char *a,int n)
{ 
	int l = strlen(a);
	static char *b;
	b = (char *)malloc(sizeof(char)*(l+n+1));
	int i=0;
	for(i=0;i<l;i++)
		b[i] = a[i];
	for(i=0;i<n;i++)
		b[i+l] = '0';
	b[i+l] = '\0';
	return b;

}
void bintos(int a,char *s)
{
	int i=0;
	while(a>0)
	{
		s[i++] = (char)('0' + a%2);
		a = a/2;
	}

	s[i] = '\0';
	int n = strlen(s);
	printf("\n%d \n",n);
	printf("\n%s\n",s);
	for(i=0;i <= n/2;i++)
	{
		char t = s[i];
		s[i] = s[n-i-1];
		s[i] = t;
	}
	printf("\n%s\n",s);

}
void substr(char *s1,char *a,int a1,int a2)
{
	int i=0;
	for(i=0;a1<a2;a1++,i++)
	{
		a[i] = s1[a1];
	}
	a[i]  = '\0';
}

int strlen1(char *a)
{
	int i=0;
	for(i=0;a[i]!='\0';i++);
		return i;


}

int stobin(char *a,int n)
{
	 n= strlen(a);
	 int val=0;
	 int i=0;
    // int n = strlen1(a);
	 for(i=0;i<n && a[i]!='\0';i++)
	 {
	 	val +=  (a[i] - '0')<<(n-i);

	 }
	return val/2;

}
char* add(char *a , char *b ,char c)//nt n=0)
{
	
		int n = (strlen(a)>=strlen(b)?strlen(a):strlen(b));
	
	static char *d;
	int s1l, s2l;
	s1l = strlen(a);
	s2l = strlen(b);
	if (s1l>s2l)
		b = string_equa(a,b);
	else if(s2l > s1l)
		a = string_equa(a,b);
	d = (char *)malloc(sizeof(char)*(n+2));
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
		if(carry)
			{d[i+1] = (char)(carry + '0');
			
			}	
			else
				d++;
				 	d[n+1] = '\0';
		return d;
	}
	else 
	{
		n = (strlen(a)>=strlen(b)?strlen(a):strlen(b));

		int i=0;
		for(i=0;i<n;i++)
		{
			if(b[i] == '0')
				b[i] = '1';
			else if(b[i] == '1')
				b[i] = '0';
		}
		//printf("%s\n",b);
		char *e = (char *)malloc(sizeof(char)*(n+1));
		e = add(a,b,'+');//,n);
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

		printf("%s\n",f);
		char *h = add(e,f,'+');//,n);
		//printf("%s\n",h);
		for(i=0 ; i<n;i++)
			h[i] =h[i+1];
		h[n] ='\0';
		//printf("%s\n",h);
		return h;
	}
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
	}
	
}