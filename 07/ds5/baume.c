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
	if(a > b) return a;
	return b;
}

int height(tree t)
{
	if(t == NULL) return 0;

	return 1 + max(height(t->left), height(t->right));
}

int abs(int x)
{
	if(x < 0) return -x;
	else return x;
}

int isBalanced(tree t)
{
	if(t == NULL)
		return 1;

	if(abs(height(t->left) - height(t->right)) > 1)
				return 0;

	return isBalanced(t->left) && isBalanced(t->right);
}

tree makeBalanced(int n)
{
	tree l, r, t;

	if(n == 0) return NULL;

	n--;
	l = makeBalanced(n/2);
	r = makeBalanced(n-n/2);

	t = malloc(sizeof(struct node));

	t->value = 1;
	t->left = l;
	t->right = r;

	return t;
}

int rank(tree t)
{
	if(t == NULL) return 0;

	return 1 + rank(t->right);
}


int isLeftist(tree t)
{
	if(t == NULL) return 1;

	if(rank(t->left) < rank(t->right)) return 0;

	return isLeftist(t->left) && isLeftist(t->right);
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


int main()
{
	int n;

	/* scanf("%d", &n); */

	/* if(n >=2) { */
	/* 	int k = 2; */
	/* 	while(n != 1) { */
	/* 		if(n % k == 0) { */
	/* 			printf("%d ", k); */
	/* 			n = n / k; */
	/* 		} else */
	/* 			k++; */
	/* 	} */
	/* } */

	/* tree t = cons(5, cons(2, cons(1, NULL, NULL), cons(7, NULL, NULL)), */
	/* 			  /\* cons(2, cons(1, NULL, NULL), cons(7, NULL, NULL)) *\/NULL); */

	tree t  = makeBalanced(20);

	printTree(t);

	printf("%d\n", height(t));

	
	printf("%d\n", isBalanced(t));

}

/* Local Variables: */
/* compile-command: "make baume" */
/* End: */
