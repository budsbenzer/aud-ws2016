#include <stdio.h>
#include <stdlib.h>

int fib(int n)
{
	if(n == 0 ||n ==1)
		return 1;
	else
		return fib(n-1) + fib(n-2);
}

int G(int n)
{
	if(n == 0)
		return 0;
	else
		return n - G(G(n-1));
}

int main()
{
	int n;

	/* printf("Zahl eingeben: "); */
	/* scanf("%u", &n); */

	for(n = 0; n < 20; n++)
		printf("G(%u) = %u\n", n, G(n));
	return 0;
}


/* Local Variables: */
/* compile-command: "make ex01" */
/* End: */
