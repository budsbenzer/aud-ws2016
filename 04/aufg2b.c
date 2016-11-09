#include <stdio.h>

/* glob. Var. & Fktsdef */

int main()
{
	/* Dekl. lok. Var. */
	int n; 
	int i, j;

	printf("Zahl eingeben!\n");
	scanf("%d", &n);

	for(i = 1; i <= n; i++) {
		for(j = 1; j <= n; j++) {
			printf("%*d ",  5, i*j);
		}
		printf("\n");
	}

	return 0;
}

/* Local Variables: */
/* compile-command: "make aufg2b" */
/* End: */
