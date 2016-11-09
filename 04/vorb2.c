#include <stdio.h>

int main()
{
	/* char name[100]; */

	/* printf("Bitte Namen eingeben!\n"); */
	/* scanf("%s", name); */

	/* printf("Hallo %s!\n", name); */

	/* unsigned int n, i, j; */

	/* printf("n: "); */
	/* scanf("%u", &n); */

	/* for(i = 1; i <= n; ++i) { */
	/* 	for(j = 1; j <= n; ++j) */
	/* 		printf("%3u ", i*j); */
	/* 	printf("\n"); */
	/* } */

	unsigned int units[] = {500, 200, 100, 50, 20, 10, 5, 2, 1};

	unsigned int input, i;

	printf("Betrag eingeben: ");
	scanf("%u", &input);

	for (i = 0; i < sizeof(units) / sizeof(*units); i++) {
		printf("%u * %u\n", input / units[i], units[i]);
		input = input % units[i];
	}

	return 0;
}

/* Local Variables: */
/* compile-command: "make vorb2" */
/* End: */
