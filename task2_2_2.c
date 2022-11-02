
#include <stdio.h>

int main()
{
    double x;
    double a;
    char ch;
    double proizv = 0;
    double res=0;
    int s = 0;
    int flag = 0;
    scanf("%lf",&x);
    while(scanf( "%lf%c", &a ) ==  1){      
        res = res*x   +  a;
        proizv += res;
        }

    printf("proizv : %lf ", proizv);
    printf("res : %lf ",res);
        
}