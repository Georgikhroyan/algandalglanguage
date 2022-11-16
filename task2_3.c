#include <stdio.h>
#include <time.h>
int rec_fibb(double i)
{
	if(i == 1){
		return 0;
	}
	if(i == 2){
		return 1;
	}
	return rec_fibb(i-1)+rec_fibb(i-2);
}

int int_fibb(double i)
{
	int k;
	double f1=0;
	double f2=1;
	if(i == 1){
		return f1;
	}
	if(i == 2){
		return f2;
	}
	else{
	for(k=2; k<i;k++)
	{
		f2 = f1+f2;
		f1 = f2-f1;
	}
	}
	return f2;


}
int main()
{
double a;
char ch;
while(scanf( "%lf", &a) == 1 )
{

	clock_t time_start= clock();
	double d = int_fibb(a);
	printf("Без рекурсии։ ");
	printf("%lf : выполнено за %f мс \n",d,(double)(time_start_2-time_start)/CLOCKS_PER_SEC);
	clock_t time_start_2= clock();
	double c = rec_fibb(a);
	printf("Рекурсивно։ ");
	printf("%lf : выполнено за %f с \n",c,(double)(clock()-time_start_2)/CLOCKS_PER_SEC);
	

}
return 0 ;
}