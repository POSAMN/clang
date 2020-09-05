typedef struct node {
	double val;
	struct node* l;
	struct node* r;
} node_t;

typedef struct tree_def {
	node_t* root;
	int height;
	int size;
} tree_t;


void addVal_it(tree_t* tree, double val);
void print_it(const tree_t* tree);