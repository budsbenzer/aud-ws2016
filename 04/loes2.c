#include <stdio.h>

int main()
{
	unsigned int n, i, j;
	
	printf("Bitte Zahl eingeben: ");
	scanf("%u", &n);

	for (i = 1; i <= n; ++i) {
		for (j = 1; j <= n; ++j)
            /* Besser: #Ziffern bestimmen */
			printf("%u\t", i * j); 
		printf("\n");
	}
	
	return 0;
}

/* Local Variables: */
/* compile-command: "make loes2" */
/* End: */
