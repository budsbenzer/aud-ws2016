#include <stdio.h>

/* glob. Var. & Fktsdef */

int main()
{
	/* Dekl. lok. Var. */
	char name[100];

	/* Folge von Statements */
	printf("Namen eingeben!\n");

	scanf("%s", name);

	printf("Hallo %s!\n", name);

	return 0;
}

/* Local Variables: */
/* compile-command: "make aufg2" */
/* End: */
