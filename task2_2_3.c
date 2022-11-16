
#include <stdio.h>
double step(double x,int n)
{
    if (n == 0)
    {
        return 1;
    }
    if (n>0)
    {
        return x * step(x,n-1);
    }
    return 0;
}
int main()
{
    int n;
    double x;
    double a;
    char ch;
    double B0;
    double B1;
    double integral = 0;
    double proizv = 0;
    double res=0;
    int flag = 0;
    scanf("%d",&n);
    while(scanf( "%lf", &a ) == 1 ){
        /*x, An , An-1 An-2 */
    	if(flag == 0){
    		x = a;
            flag++;
        }
        
        else
        {
            res = (res)*x + a;
        }
        
        if(flag <= 2)
        {
        	B0 = a;
        	flag++;
        }
        else{
            B1 = a + B0*x;
            proizv = (proizv + B0)*x;
            B0 = B1;
        }
        if(flag>2)
            if(n>=0){
                integral = integral + (a/(n+1))*(step(x,n+1));
                n--;
            }
        }
    proizv = proizv/x;
    printf(" integral : \t%lf\n ", integral);
    printf("proizv : \t%lf\n ", proizv);
    printf("res : \t%lf\n ",res);
    
        
}
