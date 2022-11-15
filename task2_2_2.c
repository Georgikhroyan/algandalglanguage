
#include <stdio.h>

int main()
{
    double x;
    double a;
    double B0,B1;
    double proizv = 0;
    double res=0;
    int s = 0;
    int flag = 0;
    scanf("%lf",&x);
    while(scanf( "%lf%c", &a ) ==  1){      
        res = res*x   +  a;
       	if (flag == 0 )
	{
		B0 = a;
	        flag++;	
        }
	else{
		B1 = a + B0*x;
		proizv = proizv*x+B0;
		B0 = B1;
	}
    }

    printf("proizv : %lf ", proizv);
    printf("res : %lf ",res);
        
}
