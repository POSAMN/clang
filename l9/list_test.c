
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    char* str;
    struct node* next;
} node_t;

typedef struct LinkedList 
{
	struct node* head;
} LinkedList_t;


void addNode(LinkedList_t* ll, char* str)
{
    node_t* new_node = malloc(sizeof(node_t));
    new_node->str = str;
    new_node->next = NULL;
    if (ll->head == NULL){
        ll->head = new_node;
    } else {
        node_t* cur = ll->head;
        while (cur->next != NULL){
            cur = cur->next;
        }
        cur->next = new_node;
    }    
}

void printAllNode(const LinkedList_t* ll)
{
    const node_t* cur = ll->head;
    printf("PRINT LIST\n");
    while (cur != NULL){
       printf("%s\n", cur->str);
       cur = cur->next;
    }
}

void clearList(LinkedList_t* ll)
{
    node_t * cur = ll->head;
    printf("!!!!!!!!!!\n");
    while (ll->head->next != NULL) {
        cur = ll->head;
            printf("cur =%s\n", cur->str);
        ll->head = cur->next;
            printf("head->str =%s\n", ll->head->str);
        free(cur);
    }
    free(ll->head);
    ll->head = NULL;
}

int main()
{
    char* s = "1111";
    char* s2 = "22222";
    char* s3 = "333333";
    LinkedList_t ll = {NULL};
    addNode(&ll, s);
    addNode(&ll, s2);
    addNode(&ll, s3);
    addNode(&ll, s);
    printAllNode(&ll);
     clearList(&ll);
    printAllNode(&ll);
}

