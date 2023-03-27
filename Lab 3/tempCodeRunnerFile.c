void DeleteAtEnd(struct Node* head)
{
    struct Node* temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    struct Node* tmp = temp->next;
    temp->next = NULL;
    free(tmp);
}