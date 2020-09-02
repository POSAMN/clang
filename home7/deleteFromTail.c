void deleteFromTail(LinkedList_t* ll){
    node_t* cur = ll->head;
    node_t* prev = NULL;
    if (cur == NULL){
        return;
    } else 
        while (cur->next != NULL){
            prev = cur;
            cur = cur->next;
        }
    if (prev != NULL){
        prev->next = NULL;
    } else 
        ll->head = NULL;
    free(cur);
}