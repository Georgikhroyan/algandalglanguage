#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <math.h>
#include <ctype.h>
#define  MAX_STR_LEN  100
double strToDouble(char str[]){
    if(str[0]=='\0') return 0;
    
    double sum=0;
    int i = 0;
    double pow = 0;
    int k;
    for(;i < strlen(str);i++){
        if(isdigit(str[i]))
            sum = sum * 10 + str[i] - '0';
        if(str[i] == '.'){
            i++;
            break;
        }
    }
    //Enter decimal
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
    if(str[i] == '+')
    {
        sum = sum * exp(pow);
    }
    if(str[i] == '-')
    {
        sum = sum * exp(-1 * pow);
    }
    if(str[k] == 'f' || str[k] == 'F'){return sum;}

    return sum;
    }

int main()
{
    char s[MAX_STR_LEN];
    while(gets(s) != NULL)
        printf("\n%.10g\n", strToDouble(s));
    return 0;
}