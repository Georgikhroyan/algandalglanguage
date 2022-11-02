
#include <stdio.h>
int main()
{
    double x;
    double a;
    double res=0;
    scanf("%lf",&x);
    while(scanf( "%lf", &a  ) == 1){
        res = res*x + a;
    }
    printf("res : %lf ",res);
}
