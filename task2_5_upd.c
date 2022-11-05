#include <stdio.h>
#include <stdlib.h>


typedef  struct Node *link; /*  pointer to list node */
typedef  char* elemtype; /*  list item type */
typedef struct Node { /* list node type */
    elemtype elem; /*    item */
    link next; /*  pointer to the next node */
}
node;

typedef link list; /* list type (pointer to the first node) */

void print (list p)
{
    while (p!=NULL) {
        putchar (p->elem);
        p=p->next;
    }
    putchar ('\n');
}

void push(list *pl, elemtype el){ /* put item on stack */
    link tmp = malloc(sizeof(node));
    tmp->elem = el;
    tmp->next = *pl;
    *pl = tmp;
}


int empty (list p){
    return p==NULL;
}


void del_first(list *p){
    link t;
    
    if(empty(*p)) return;
   
    t = *p;
    *p = (*p)->next;
    free(t);
}
void del_befor_a (list * lp) { /* delete list element before 'a' */
    link q;
    if (*lp==NULL || (*lp)->next == NULL) return;
    while( (*lp)->next != NULL) {
        if ((*lp)->next->elem == 'a') {
            q=*lp; *lp=(*lp)->next;
            free(q);
        }
        else  lp=&((*lp)->next);
    } 
}


int main()
{	list cur;
	empty(cur);
	push(&cur,'bsab');
	printf("%s",(*cur)->elem);
	push(&cur,'bsab');
	print(cur);
}

