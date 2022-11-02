
#include <stdio.h>
double module(double a)
{
	if(a>=0)
	{
		return a;
	}
	else
	{
		return a * (-1.0);
	}
}
double nyuton(double x,double e){
double x0 = 1;
double x1 = (x0+(x/x0))*(0.5) ;
while((module(x1-x0))>=e)
{
	x0 = x1;
	x1 = (0.5)*(x0+(x/x0));

}
return x1;
}
int main()
{	
	double e;
	double x;
	scanf("%lf",&e);
	while(scanf("%lf",&x) == 1){
		printf("%lf\n",nyuton(x,e));
	}  
		
}
	
