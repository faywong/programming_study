/**
 * Copyright (C) faywong<philip584521@gmail.com>
 * Date: 2013-10-10
 */

#include <stdio.h>
#include <stdlib.h>

#include "common.h"

struct node {
	int val;
	struct node* p; // parent node
	struct node* l_c; // greater than val
	struct node* r_c; // smaller than val
};

struct node* new_node(int val, struct node* l, struct node* r, struct node* p) {
	struct node* node = (struct node*)malloc(sizeof(struct node));
	printf("new node 0x%p\n", node);
	if (node != NULL) {
		node->val = val;
		node->l_c = l;
		node->r_c = r;
		node->p = p;
	} else {
		printf("out of memory!\n");
	}
	return node;
}

void insert_node(struct node* node, int val) {
	if (NULL == node) {
		printf("node NULL!\n");
		return;
	}
	
	if (node->val <= val) {
		if (node->l_c) {
			insert_node(node->l_c, val);
		} else {
			node->l_c = new_node(val, NULL, NULL, node->l_c);
			return;
		}
	} else {
		if (node->r_c) {
			insert_node(node->r_c, val);
		} else {
			node->r_c = new_node(val, NULL, NULL, node->r_c);
			return;
		}
	}
}

void iterator_node(struct node* node) {
	if (node != NULL) {
		iterator_node(node->r_c);
		printf("%d, ", node->val);
		iterator_node(node->l_c);
	}
}

void destroy_node(struct node* node) {
	if (NULL == node) {
		return;
	}
	destroy_node(node->r_c);
	destroy_node(node->l_c);
	printf("destroy node 0x%p\n", node);
	free(node);
}

int main(void)
{
	int a[] = { 8, 4, 1, 5, 6, 8, 10, 23, 26 };
	struct node* root = new_node(a[0], NULL, NULL, NULL);
	int i, length = sizeof(a) / sizeof(a[0]);
	dump(a, length, "before tree sort, array:");
	
	for (i = 1; i < length; ++i) {
		insert_node(root, a[i]);
	}
	
	printf("\n");
    printf("after sort, array:\n");
	iterator_node(root);
	printf("\n\n");
	destroy_node(root);
	return 0;
}