#include <stdlib.h>
#include <stdio.h>
#include "tree.h"


void addVal_it(tree_t* tree, double val) {
	node_t* new_node = malloc(sizeof(node_t));
	new_node -> val = val;
	new_node -> l = NULL;
	new_node -> r = NULL;
	
	if (tree -> root == NULL) {
		tree->root = new_node;
	} else {
		node_t* cur = tree->root;
		while (1) {
			if (cur->val > val) {
				if (cur->l == NULL) {
					cur->l = new_node;
					return;
				} else {
					cur = cur->l;
				}
			} else if (cur->val < val) {
				if (cur->r == NULL) {
					cur->r = new_node;
					return;
				} else {
					cur = cur->r;
				}
			} else {
				return;
			}
		}
	}
}


void print_it(const tree_t* tree) {
	int cur_lvl = 0;
	
}