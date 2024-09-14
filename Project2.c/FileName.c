#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"
#include "ItrTreeTrv.h"

void LinkPreOrder(TreeNode* root) {
	LinkedStackType s;
	TreeNode* nptr = root;

	init(&s);

	while (nptr != NULL || !is_empty(&s)) {
		while (nptr != NULL) {
			printf("push(%d)\n", nptr->data);
			push(&s, nptr);
			nptr = nptr->left;
		}

		nptr = pop(&s);
		printf("pop(%2d)\n", nptr->data);
		printf("visit(%d)\n", nptr->data);
		nptr = nptr->right;
	}
}

void LinkInOrder(TreeNode* root) {
	LinkedStackType s;
	TreeNode* nptr = root;

	init(&s);

	while (nptr != NULL || !is_empty(&s)) {
		while (nptr != NULL) {
			push(&s, nptr);
			printf("push(%d)\n",nptr->data);
			nptr = nptr->left;
			
		}

		nptr = pop(&s);
		printf("pop(%2d)\n", nptr->data);
		printf("visit(%d)\n", nptr->data);

		nptr = nptr->right;
	}
}
void LinkPostOrder(TreeNode* root) {
	LinkedStackType s1, s2;
	TreeNode* nptr = root;

	init(&s1);
	init(&s2);

	if (nptr != NULL) {
		push(&s1, nptr);
		printf("push(%d)\n", nptr->data);
	}

	while (!is_empty(&s1)) {
		nptr = pop(&s1);
		printf("pop(%2d)\n", nptr->data);
		push(&s2, nptr);
		printf("push(%d)\n", nptr->data);

		if (nptr->left != NULL) {
			push(&s1, nptr->left);
			printf("push(%d)\n", nptr->left->data);
		}
		if (nptr->right != NULL) {
			push(&s1, nptr->right);
			printf("push(%d)\n", nptr->right->data);
		}
	}

	while (!is_empty(&s2)) {
		nptr = pop(&s2);
		printf("pop(%2d)\n", nptr->data);
		printf("visit(%d)\n", nptr->data);
	}
}
