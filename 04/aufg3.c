#include <stdio.h>

/* glob. Var. & Fktsdef */

int main()
{
	int n;
	int i;
	int fak;

	scanf("%d", &n);

	for(i = 1, fak = 1; i <= n; i++) {
		fak *= i;
	}

	printf("%d", fak);

	return 0;
}

/* Local Variables: */
/* compile-command: "make aufg3" */
/* End: */
