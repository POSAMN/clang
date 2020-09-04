int size(LinkedList_t* ll){
    node_t* cur = ll->head;
    int i = 0;
    while (cur != NULL){
        cur = cur->next;
        i++;
    }
    return i;
}