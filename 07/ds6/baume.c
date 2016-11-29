#include <stdio.h>
#include <stdlib.h>

typedef struct node* tree;
struct node {
	int value;
	tree left;
	tree right;
};

int max(int a, int b)
{
	if(a >= b) return a;
	else return b;
}

int height(tree t)
{
	if(t == NULL) return 0;

	return 1 + max(height(t->left), height(t->right));
}

int isBalanced(tree t)
{
	if(t == NULL) return 1;

	if(abs(height(t->left) - height(t->right)) > 1) return 0;

	return isBalanced(t->left) && isBalanced(t->right);
}


tree makeBalanced(int n)
{
	if(n <= 0) return NULL;

	tree t = malloc(sizeof(*t));

	t->value = 42;

	/* t->left = makeBalanced(n/2); */
	/* t->right = makeBalanced(n - 1 - n/2); */

	n = n - 1;

	t->right = makeBalanced(n / 2);
	t->left = makeBalanced(n - n / 2); // oder mit 	n/2 + n % 2

	return t;
}

int rank(tree t)
{
	if(t == NULL) return 0;

	return rank(t->right) + 1;
}

int isLeftist(tree t)
{
	if(t == NULL) return 1;

	if(rank(t->left) >= rank(t->right))
		return isLeftist(t->left) && isLeftist(t->right);

	return 0;

}

tree cons(int v, tree l, tree r)
{
	tree ret = malloc(sizeof(*ret));

	ret->value = v;
	ret->left = l;
	ret->right = r;

	return ret;
}

void printTreeHelper(tree t, int level, unsigned int branches) {
	int i;
	if (level > 0) {
		for (i = 0; i < level - 1; ++i) {
			if (branches & (1 << i)) {
				printf("│ ");
			} else {
				printf("  ");
			}
		}
		if (branches & (1 << i)) {
			printf("├ ");
		} else {
			printf("└ ");
		}
	}
	if (t == NULL) {
		printf("NULL\n");
	} else {
		printf("%i\n", t->value);
		if (t->left || t->right) {
			printTreeHelper(t->left, level + 1, branches | (1 << level));
			printTreeHelper(t->right, level + 1, branches);
		}
	}
}

void printTree(tree t) {
	printTreeHelper(t, 0, 0);
}


/* int main() */
/* { */
/* 	int n; */

/* 	scanf("%d", &n); */

/* 	if(n < 2) return 0; */

/* 	for(int i = 2; i <= n; i++){ */
/* 		while(n % i == 0) { */
/* 			n = n / i; */
/* 			printf("%d ", i); */
/* 		} */
/* 	} */
/* 	printf("\n"); */

/* } */


int main()
{
 	tree t = makeBalanced(10);

	printTree(t);

	printf("%d\n", isBalanced(t));


}


/* Local Variables: */
/* compile-command: "make baume" */
/* End: */
