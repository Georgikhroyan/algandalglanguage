#include <stdio.h>
#include <time.h>
int rec_fibb(double i)
{
	if(i == 1 || i == 2)
		return 1;
	return rec_fibb(i-1)+rec_fibb(i-2);
}

int int_fibb(double i)
{
	int k;
	double f1=1;
	double f2=1;
	for(k=2; k<i;k++)
	{
		f2 = f1+f2;
		f1 = f2-f1;
	}
	return f2;


}
int main()
{
double a;
char ch;
while(scanf( "%lf%c", &a, &ch ) == 2 && ch != EOF )
{

	clock_t time_start= clock();
	double c = rec_fibb(a);
	clock_t time_start_2= clock();
	double d = int_fibb(a);
	printf("Рекурсивно։ ");
	printf("%lf : выполнено за %f с \n",c,(double)(time_start_2-time_start)/CLOCKS_PER_SEC);
	printf("Без рекурсии։ ");
	printf("%lf : выполнено за %f мс \n",d,(double)(clock()-time_start_2)/CLOCKS_PER_SEC);

}
return 0 ;
}
