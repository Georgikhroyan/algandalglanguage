#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#define  MAX_STR_LEN  100
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
double del( int n){
    double res=1;
    while(n!=0)
    {
        res /= 10;
        n++;
    }
    return res;
}
double strToDouble(char str[]){
    if(str[0]=='\0') return 0;
    
    double sum=0;
    int i = 0;
    double pow = 0;
    int k;
    int notoch = 0;
    int flag;
    for(;i < strlen(str);i++){
        if(isdigit(str[i]))
            sum = sum * 10 + str[i] - '0';
        if(str[i] == '.'){
            i++;
            break;
        }
        if(str[i] == 'e'){
            notoch = 1;
            flag = i;
            break;
        }
    }
    printf("---%d",notoch);
    if (notoch != 1){
    double m = 0.1;
    for(;i < strlen(str);i++){
        if(isdigit(str[i])){
            sum = sum + (str[i] - '0') * m;
            m /= 10;
        }
        if(str[i] == 'E' || str[i] == 'e'){i++;break;}
        if(str[i] == 'F' || str[i] == 'f'){return sum;}
    }

    for( k = i+1;k<strlen(str);k++){
        if(isdigit(str[k]))
            {
                pow = pow * 10 + str[k] - '0';
            }
        else{break;}
        }
    if(isdigit(str[i]))
    {
        for( k = i;k<strlen(str);k++){
        if(isdigit(str[k]))
            {
                pow = pow * 10 + str[k] - '0';
            }
        sum = sum * step(10,pow);
        break;
        }
    }
    if(str[i] == '+')
    {
        sum = sum * step(10,pow);
    }
    if(str[i] == '-')
    {
        sum = sum *del(-1*pow);
    }
    if(str[k] == 'f' || str[k] == 'F'){return sum;}

    return sum;
    }
    else{

        for( k = i+2;k<strlen(str);k++){
        if(isdigit(str[k]))
            {
                pow = pow * 10 + str[k] - '0';
            }
        else{break;}
        }
        if (str[i+1] == '+'){
            sum = sum * step(10,pow);
            return sum; 
        }
        if (str[i+1] == '-'){
            sum = sum * del(-1 * pow);
            return sum; 
        }
        if (isdigit(str[i+1])){
            for( k = i+1;k<strlen(str);k++){
                if(isdigit(str[k]))
                    {
                        pow = pow * 10 + str[k] - '0';
                    }
            sum = sum * step(10,pow);
            return sum;
        }
    }
}
}
int main()
{
    char s[MAX_STR_LEN];
    while(gets(s) != NULL)
        printf("\n%.10g\n", strToDouble(s));
    return 0;
}