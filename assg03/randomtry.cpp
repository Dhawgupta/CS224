//include<stdio.h>
#include<iostream>
//#include<stdlib>
#include<cstdlib>
#include<ctime>
using namespace std;
int  main(){
srand(time(0));
float rv  = rand();
rv = rv/RAND_MAX;

cout<<"The random varibale is"<<rv<<"And this is between "<<rv/RAND_MAX;


return 0;
}
