#include <stdlib.h>
#include <stdio.h>
#include "tree.h"

int main() {
	tree_t tree = {NULL, 3, 4};
	/*
	addVal_it(&tree, 1.0);
	addVal_it(&tree, 2.0);
	addVal_it(&tree, 3.0);
	addVal_it(&tree, 1.1);*/
	tree.root = (node_t *) malloc(sizeof(node_t));
	tree.root-> val = 6;
	tree.root -> l = (node_t *) malloc(sizeof(node_t));
	tree.root -> r = (node_t *) malloc(sizeof(node_t));
	tree.root-> l -> val = 10;
	tree.root-> r -> val = 15;
	tree.root -> l -> r  = (node_t *) malloc(sizeof(node_t));
	tree.root -> l -> r -> val = 21;
	
	print_it(&tree);
	return 0;
}