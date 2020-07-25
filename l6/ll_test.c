#include <stdlib.h>
#include "link_list.h"

int main() {
	node_t head = {42, NULL};
	addToTail(&head, 12);
	addToTail(&head, 22);
	addToTail(&head, -1);
	print(&head);
	
}