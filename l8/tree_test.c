#include <stdlib.h>
#include "tree.h"

int main() {
	tree_t tree = {NULL, 0, 0};
	addVal_it(&tree, 1.0);
	addVal_it(&tree, 2.0);
	addVal_it(&tree, 3.0);
	addVal_it(&tree, 1.1);
	return 0;
}