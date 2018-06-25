#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>
#include<math.h>
double factorial(double x)
{
	if (x == 0 || x == 1)
		return 1;
	double i,fact = 1;
	for ( i = x; i>1 ;i--)	
		fact = fact * i;
	return fact;
}

double power(double a,double b)
{
	double value=1,k;
	if ( b == 0)
		return 1;
	else
	{
		for ( k = 1 ; k<=b;k++)
			value  = value * a;
		return value;  
	}
}
double main( int argc, const char* arg[])
{
	//printf("%d",argc);
	double x = atof(arg[1]);
	double n = atof(arg[2]);
	printf("\nX is %f",x);	
	printf("\nn is %f",n);	
	double j,k,p;
	double value = 0;
	for ( j= 0 ; j<n;j++)
	{
		//p = pow(x,j);
		value = ( value + ( power(x,j) / factorial(j) ) ); 	
	}
	printf("\nValue for x = %f and for 1st %f terms  : %f\n",x,n,value);
	return value;
}
