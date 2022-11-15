#include <stdio.h>
#include <setjmp.h>

jmp_buf begin; /* точка начала диалога */
char curlex; /* текущая лексема */
void getlex(void); /*выделяет из входного потока очередную лексему */
int expr(void); /* распознает выражение и вычисляет его значение */
int add(void); /* распознает слагаемое и вычисляет его значение */
int mult(void); /* распознает множитель и вычисляет его значение */
int sub(void); /* распознает слагаемое и вычисляет его значние */
int divide(void); /* распознает делитель и вычисляет его значнеие */
void error(); /* сообщает об ошибке в выражении и передает управление в начало функции main(точка begin)*/

main()
{
	int result;
	setjmp(begin);
	printf("==>");
	getlex();
	result = expr();
	if ( curlex != '\n' ) error();
	printf("\n%d\n",result);
	return 0;
}
void getlex()
{
	while ( (curlex = getchar()) == ' ' );
}
void error(void)
{
	printf("\nОшибка\n");
	while(getchar() != '\n');
	longjmp(begin,1);
}
int expr()
{	
	int e = add();
	while (curlex != '\n' && curlex != '*' && curlex != '/' && curlex != '(' && curlex != ')' ) {
	if (curlex == '+')
	{getlex(); e += add();}
	if (curlex == '-')
	{getlex(); e -= sub();}
	}
	return e;
}
int sub()
{
	int a = mult() ;
	while (curlex != '\n' && curlex != '+' && curlex != '-' && curlex != '(' && curlex != ')') {
	if (curlex == '*')
	{getlex(); a*= mult();}
	if (curlex == '/')
	{getlex(); a/= divide();}
	}
	return a;
}
int add()
{	int a = mult();
	while (curlex != '\n' && curlex != '+' && curlex != '-' && curlex != '(' && curlex != ')') {
	if (curlex == '/')
	{getlex(); a/= mult();}
	if (curlex == '*')
	{getlex(); a*= divide();}
	}
	return a;
}
int mult()
{
	int m ;
	switch(curlex){	
		case '0': case '1': case '2': case '3' : case '4' : case '5' : case '6' : case '7' :
		case '8' : case '9' : m = curlex -'0'; break;
		case '(' : getlex() ; m = expr();
		if (curlex == ')') break;
		default : error();
	}
	getlex();
	return m;
}
int divide()
{
	int m;

	switch(curlex)	
	{
		case '0': case '1': case '2': case '3' : case '4' : case '5' : case '6' : case '7' :
		case '8' : case '9' : m = curlex -'0'; break;
		case '(' : getlex() ; m = expr();
		if (curlex == ')') break;
		default: error();
	}

	getlex();

	return m;
}
