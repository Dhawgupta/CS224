#include<stdio.h>
#include<cstdlib>
#include<ctime>

/*
0:         0000
1:         0001
2:         0010
3:         0011
4:         0100
5:         0101
6:         0110
7:         0111
8:         1000
9:         1001
+:         1010
-:         1011
*:         1100
/:         1101
*/
using namespace std;
int main()
{
    srand(time(0));
    float rv;

    char a[100][9*4 + 1];
    for(int i=0;i<100;i++)
    {

        for(int j=0;j<=36;j++)
    {
        rv = rand();
        rv = rv/RAND_MAX;
        if(rv >= 0.5)
        {
            a[i][j] = '1';

        }
        else
            a[i][j] = '0';


    }
    a[i][36] = '\0';
    }

    for(int i=0;i<100;i++)
      cout<<a[i]<<endl;
return 0;

}
