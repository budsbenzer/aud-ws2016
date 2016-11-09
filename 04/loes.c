#include <stdio.h>

int main()
{
	char name[100];

	printf("Bitte Namen eingeben: ");
	scanf("%99s", name); /* Oder bloss %s */
	printf("Hallo %s!\n", name);
	
	return 0;
}

/* Local Variables: */
/* compile-command: "make loes" */
/* End: */
