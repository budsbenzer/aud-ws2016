#include <stdio.h>
#include <stdlib.h>

typedef struct node* tree;
struct node {
	int key;
	tree left;
	tree right;
};

tree cons(int v, tree l, tree r)
{
	tree ret = malloc(sizeof(*ret));

	ret->key = v;
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
		printf("%i\n", t->key);
		if (t->left || t->right) {
			printTreeHelper(t->left, level + 1, branches | (1 << level));
			printTreeHelper(t->right, level + 1, branches);
		}
	}
}

void printTree(tree t) {
	printTreeHelper(t, 0, 0);
}


int leafprod(tree t)
{
	if(t == NULL)
		return 1;

	if(t->left == 0 && t->right == NULL)
		return t->key;
	else
		return leafprod(t->left) * leafprod(t->right);
}


int main()
{
	tree t = cons(5, cons(2, cons(1, NULL, NULL), cons(7, NULL, NULL)),
				  cons(2, cons(1, NULL, NULL), cons(7, NULL, NULL)));

	printTree(t);

	printf("%d\n", leafprod(t));
}

/* Local Variables: */
/* compile-command: "make baume" */
/* End: */
