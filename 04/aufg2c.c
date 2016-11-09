#include <stdio.h>

/* glob. Var. & Fktsdef */

int main()
{
	/* Dekl. lok. Var. */
	int s[1001];
	int i, j;

	for(i=0; i < 1001; ++i)
		s[i] = 1;
	
	for(i = 2; i < 33; i++) {
		if(s[i] == 1) {
			j = 2;
			while(j * i <= 1000) {
				s[j*i] = 0;
				j++;
			}
		}
	}

	for(i = 2; i <= 1000; i++)
		if(s[i] == 1)
			printf("%d ", i);

	return 0;
}

/* Local Variables: */
/* compile-command: "make aufg2c" */
/* End: */
