
#include <stdio.h>
int main()
{
    double x;
    double a;
    char ch;
    double res=0;
    scanf("%lf",&x);
    while(scanf( "%lf%c", &a, &ch ) == 2 && ch != EOF ){
        res = (res + a)*x;
    }
    res /= x;
    printf("res : %lf ",res);
}
