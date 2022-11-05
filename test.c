#include <setjmp.h>
jmp_buf begin; /* òî÷êà íà÷àëà äèàëîãà ñ ïîëüçîâàòåëåì */
har urlex; /* òåêóùàÿ ëåêñåìà */
void getlex(void); /* âûäåëÿåò èç âõîäíîãî ïîòîêà î÷åðåäíóþ ëåêñåìó */
int expr(void); /* ðàñïîçíàåò âûðàæåíèå è âû÷èñëÿåò åãî çíà÷åíèå */
int add(void); /* ðàñïîçíàåò ñëàãàåìîå è âû÷èñëÿåò åãî çíà÷åíèå */
int mult(void); /* ðàñïîçíàåò ìíîæèòåëü è âû÷èñëÿåò åãî çíà÷åíèå */
void error(); /* ñîîáùàåò îá îøèáêå â âûðàæåíèè è ïåðåäàåò óïðàâëåíèå
â íà÷àëî óíêöèè main (òî÷êà begin) */
main()
{
int result;
setjmp(begin);
printf("==>");
getlex();
result=expr();
if (urlex != '\n') error();
printf("\n%d\n",result);
return 0;
}
void getlex()
{
while ( (urlex=gethar()) == ' ');
}
void error(void)
{
printf("\nÎØÈÁÊÀ!\n");
while(gethar()!='\n');
longjmp(begin,1);
}
int expr()
{
int e=add();
while (urlex == '+')
{ getlex(); e+=add();}
return e;
}
int add()
{
int a=mult();
while (urlex == '*')
{ getlex(); a*=mult();}
return a;
}
int mult()
{
int m;
swith(urlex){
ase '0': ase '1': ase '2': ase '3': ase '4': ase '5':
ase '6': ase '7': ase '8': ase '9': m=urlex-'0'; break;
ase '(': getlex(); m=expr();
if (urlex == ')') break;
/* èíà÷å îøèáêà - íåò çàêðûâàþùåé ñêîáêè */
default : error();
}
getlex();
return m;
}
/* Ñðàâíèòå ïðîòîòèïû (â íà÷àëå ïðîãðàììû) è çàãîëîâêè óíêöèé
* (â ñîîòâåòñòâóþùèõ îïðåäåëåíèÿõ) error() è getlex() : èíîðìàöèþ
* î ïàðàìåòðàõ (â äàííîì ñëó÷àå ïóñòûå ñïèñêè ïàðàìåòðîâ - void) ìîæíî
* îïóñêàòü â çàãîëîâêå, åñëè îíà åñòü â îáúÿâëåíèè ïðîòîòèïà (êàê â ñëó÷àå
* ñ getlex) èëè íå óêàçûâàòü â ïðîòîòèïå, à óêàçàòü òîëüêî â çàãîëîâêå
* (êàê â ñëó÷àå ñ error). Òèï îáåõ óíêöèé - "óíêöèÿ, íå âîçâðàùàþùàÿ
* çíà÷åíèÿ ñ ïóñòûì ñïèñêîì àðãóìåíòîâ"
*/