#include <stdio.h>

#define LEN 1001

int main()
{
	unsigned int sieve[LEN];
	unsigned int i, j;
	
	sieve[0] = 0, sieve[1] = 0;

	for(i = 2; i < LEN; ++i)
		sieve[i] = 1;

	for (i = 2; i < LEN; ++i) 
		if (sieve[i] != 0)
			for (j = 2 * i; j < LEN; j = j + i)
				sieve[j] = 0;

	for (i = 0; i < LEN; ++i)
		if(sieve[i] != 0) printf("%u\n", i);
	
	return 0;
}

/* Local Variables: */
/* compile-command: "make loes3" */
/* End: */
