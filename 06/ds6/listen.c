#include <stdio.h>
#include <stdlib.h>

typedef struct element* list;
struct element {
	int value;
	list next;
};

list cons(int n, list next)
{
	list l = malloc(sizeof(struct element));
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

int sum(list l)
{
	int ret = 0;

	while(l != NULL) {
		ret = ret + l->value;
		l = l->next;
	}

	return ret;
}

int sum_rec(list l)
{
	if(l == NULL)
		return 0;
	return sum_rec(l->next) + l->value;
}

list rmEvens(list l)
{
	while(l != NULL && l->value % 2 == 0) {
		list zuLoeschen = l;
		l = l->next;
		free(zuLoeschen);
	}
	list h = l;

	while(l != NULL){
		list p = l->next;
		
		while(p != NULL && p->value % 2 == 0){
			list zuLoeschen = p;
			p = p->next;
			free(zuLoeschen);
		}
		l->next = p;
		l = l->next;
	}

	return h;
}

void rmEvens2(list *p)
{
	while(*p != NULL) {
		if((*p)->value % 2 == 0) {
			list tmp = *p;
			*p = (*p)->next;
			free(tmp);
		}
		else 
			p = &(*p)->next;
	}
}


int main()
{
	list l = cons(8, cons(1, cons(2, cons(3, cons(7, cons(2, NULL))))));

	printList(l);

	/* printf("%d\n", sum(l)); */
	rmEvens2(&l);

	printList(l);
	return 0;
}

/* Local Variables: */
/* compile-command: "make listen" */
/* End: */
