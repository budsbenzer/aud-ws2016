#include <stdio.h>
#include <stdlib.h>

int main()
{
	unsigned int guess, number, n;
	
	scanf("%u", &n);
	number = 1 + rand() % n;

	while(1) {
		printf("Zahl raten: ");
		scanf("%u", &guess);

		if (guess == number){
			printf("Sehr gut!\n");
			return 0;
		} else if (guess > number){
			printf("Meine Zahl ist kleiner!\n");
		} else {
			printf("Meine Zahl ist groesser!\n");
		}
	}

	/* Die optimale Ratestrategie ist Bisektionssuche.  
     * Also vergleichen mit log2(n) */
	
	return 0;
}

/* Local Variables: */
/* compile-command: "make loes4" */
/* End: */
