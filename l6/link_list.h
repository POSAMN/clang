typedef struct node {
	int data;
	struct node* next;
} node_t;


void addToTail(node_t* head, int data);
void print(const node_t* head);
//функция возвращает указатель на новую голову
node_t* addToHead(node_t* oldHead, int data);
node_t* findByValue(node_t* head, int value);
void deleteByValue(node_t* head, int value);