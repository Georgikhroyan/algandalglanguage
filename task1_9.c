#include <stdio.h>
#include <limits.h>

int main()
{
	char a = CHAR_MIN;
	char b = CHAR_MAX;
	printf("%d\t%d\n",a,b);
    printf("CHAR_MIN = %d CHAR_MAX = %d\n", CHAR_MIN, CHAR_MAX);
    printf("То есть char - signed");
}