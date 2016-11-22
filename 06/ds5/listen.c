#include <stdio.h>
#include <stdlib.h>


typedef struct element* list;
struct element {
	int value;
	list next;
};

void printList(list);
list cons(int,list);

int sum(list l)
{
	int erg = 0;

	while(l != NULL) {
		erg += l->value;
		l = l->next;
	}

	return erg;
}

int sum_rec(list l)
{
	if(l == NULL) return 0;
	else return l->value + sum_rec(l->next);
	
}

void rmEvens(list* l)
{
	while(*l != NULL) {
		if((*l)->value % 2 == 0) {
			list tmp = *l;
			*l = (*l)->next;
			free(tmp);
		} else {
			l = &(*l)->next;
		}
	}
}

int main()
{
	list l = cons(8, cons(1, cons(2,
              cons(3, cons(
					   7, cons(2, NULL))))));

	printList(l);

	printf("%d\n", sum_rec(l));
	rmEvens(&l);

	printList(l);
	return 0;
}

list cons(int n, list next)
{
	list l = malloc(sizeof(*l));
	l->value = n;
	l->next = next;
	return l;
}

void printList(list l)
{
	printf("[");
	while(l != NULL){
		printf("%d", l->value);
		if(l->next != NULL) printf(", ");
		l = l->next;
	}
	printf("]\n");
}


/* Local Variables: */
/* compile-command: "make listen" */
/* End: */
