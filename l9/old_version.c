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

 
void addNode(LinkedList_t* ll, char* arr)
{
    node_t* new_node = (node_t*)malloc(sizeof(node_t));
    new_node->str = arr;
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
    while (cur != NULL){
       printf("%s\n", cur->str);
       cur = cur->next;
    }
    printf("NULL\n");
}

char* addLenArr(char* arr, int size)
{
    char* arr1 = (char*)malloc(sizeof(char)*size*2);
    for (int i = 0; i < size; i++){
        arr1[i] = arr[i];
    }
    return arr1;
}

int main ()
{
    char* s;
    int i = 0;
    int j = 0;
    LinkedList_t ll = {NULL};
    char* arr = (char*)malloc(sizeof(char)*10);
    scanf("%s", s);
    while (s[i] != '\0'){
        if (s[i] == ' ') {
            i++;
           printf("%ch", s[i]);
        } else {
            printf(".");
            while (s[i] != ' ') {
                arr[j] = s[i];
                j++;
                i++;
            }
            arr[j] = '\0';
//             addNode(&ll, arr);
            j = 0;
        }
    }
//     printAllNode(&ll);

}