#include <stdio.h>
#include <stdlib.h>

int fib(int n)
{
	if(n==0 || n==1)
		return 1;
	else
		return fib(n-2) + fib(n-1);
}

unsigned int G(unsigned int n)
{
	if(n==0)
		return 0;
	else
		return n - G(G(n-1));
}



int main()
{
	unsigned int n;

	for(n = 0; n < 20; n++)
		printf("fib(%u) = %u\n", n, G(n));
	return 0;
}


/* Local Variables: */
/* compile-command: "make ex01" */
/* End: */
