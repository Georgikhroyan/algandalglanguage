
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
	printf("\n-------%lf\t%lf-------\n",x0,x1);

}
printf("\n%.10g\n",x1);
return 0;
}
int main()
{	
	double e;
	double x;
	printf("Ввод e : \t");
	scanf("%lf",&e);
	while(getchar() != EOF){
	    printf("Ввод x : \t");
		scanf("%lf",&x);
		nyuton(x,e);
	}  
		
}
	

