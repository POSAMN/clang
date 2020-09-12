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

int powInt(int mantissa, int power) {
	int result = 1;
	for (int i = 0; i < power; i++) {
		result *=mantissa;
	}
	return result;
}

void print_it(const tree_t* tree) {
	node_t* cur = NULL;
	for (int cur_lvl = 0; cur_lvl < tree-> height; cur_lvl++) {
		for (int i = 0; i < powInt(2, cur_lvl); i++) {//обходим внутри одного уровня
			cur = tree->root; 
			for (int j = 0; j < cur_lvl; j++){
				int right = (i >> (cur_lvl - j  - 1)) & 1;
				if (right) {
					if (cur != NULL){
						cur = cur->r;
					}
				} else {
					if (cur != NULL) {
						cur = cur->l;
					}
				}
			}
			if (cur != NULL) {
				printf("%.2lf ", cur->val);
			} else {
				printf("___ ");
			}
		}
		printf("\n");
	}
}