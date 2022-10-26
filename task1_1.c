#include <stdio.h>
void main()
{
	printf("Под short выделено %d байта памяти\n",sizeof(short));
	printf("Под int выделено %d байта памяти\n",sizeof(int));
	printf("Под long выделено %d байта памяти\n",sizeof(long));
	printf("Под float выделено %d байта памяти\n",sizeof(float));
	printf("Под double выделено %d байта памяти\n",sizeof(double));
	printf("Под long double выделено %d байта памяти\n",sizeof(long double));
}
