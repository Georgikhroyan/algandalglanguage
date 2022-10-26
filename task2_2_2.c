
#include <stdio.h>

int main()
{
    double x;
    double a;
    char ch;
    double B0;
    double B1;
    double proizv = 0;
    double res=0;
    int flag = 0;
    scanf("%lf",&x);
    while(scanf( "%lf%c", &a, &ch ) == 2 && ch != EOF ){
        /*x, An , An-1 An-2 */
        res = (res + a)*x;
        if(flag == 0){
            B0 = a;
            flag++;
        }
        else{
            B1 = a + B0*x;
            proizv = (proizv + B0)*x;
            B0 = B1;
        }
        }
    proizv = proizv/x;
    res = res/x;
    printf("proizv : %lf ", proizv);
    printf("res : %lf ",res);
        
}


