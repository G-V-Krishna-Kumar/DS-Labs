#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Node* InsertAtEnd(struct Node* head, int data)
{
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    if(head == NULL)
    {
        node->next = NULL;
        node->prev = NULL;
        head = node;
        return head;
    }
    struct Node* temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    node->next = NULL;
    node->prev = temp;
    temp->next = node;
    
    return head;
}

struct Node* InsertAtBegin(struct Node* head, int data)
{
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = head;
    node->prev = NULL;
    head->next->prev = node;
    head = node;

    return head;
}

void InsertInMiddle(struct Node* head, int data, int index)
{
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    struct Node* temp = head;
    int i = 1;

    while (temp->next != NULL && i<index-1)
    {
        temp = temp->next;
        i++;
    } 

    node->data = data;
    node->next = temp->next;
    temp->next->prev = node;
    node->prev = temp;
    temp->next = node;
}


struct Node* DeleteAtBegin(struct Node* head)
{
    struct Node* temp = head;
    temp->next->prev = NULL;
    head = head->next;
    free(temp);
    
    return head;
}

void DeleteInMiddle(struct Node* head, int index)
{ 
    struct Node* temp = head;
    int i = 1;
    while (temp->next != NULL && i<index)
    {
        temp = temp->next;
        i++;
    }
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    free(temp);
}

void DeleteAtEnd(struct Node* head)
{
    struct Node* temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->prev->next = NULL;        
    free(temp);
}

void Traverse(struct Node* head)
{
    struct Node* temp = head;
    while(temp != NULL)
    {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("NULL");
}

void UpdateAtBegin(struct Node* head, int data)
{
    head->data = data;
}

void UpdateInMiddle(struct Node* head, int data, int index)
{
    struct Node* temp = head;
    int i=1;
    while (temp->next != NULL && i<index)
    {
        temp = temp->next;
        i++;
    }
    temp->data = data;
}

void UpdateAtEnd(struct Node* head, int data)
{
    struct Node* temp = head;

    while(temp->next != NULL)
    {
        temp = temp->next; 
    }
    temp->data = data;
}


void Search(struct Node* head, int data)
{
    struct Node* temp = head;
    int i=1;
    while (temp != NULL)
    {
        if (temp->data == data)
        {
            printf("%d found at position %d", data, i);
            return;
        }
        temp = temp->next;
        i++;
    }
    printf("%d not found in the Doubly Linked List");
}

struct Node* head = NULL;

int main()
{
    int n, data, choice, new_choice, index, flow = 1;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    for (int i=0; i<n; i++)
    {
        printf("Enter data: ");
        scanf("%d", &data);

        head = InsertAtEnd(head, data);
    }

    while (flow)
    {
        printf("\nDoubly Linked List Operations: \n");
        printf("1. Insertion\n");
        printf("2. Deletion\n");
        printf("3. Traversing\n");
        printf("4. Updation\n");
        printf("5. Searching\n");
        printf("6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("Enter element to be inserted: ");
                scanf("%d", &data);
                printf("Insert element: \n");
                printf("1. At the beginning\n");
                printf("2. In the middle\n");
                printf("3. At the end\n");
                printf("Enter choice: ");
                scanf("%d", &new_choice);

                switch (new_choice)
                {
                    case 1:
                        head = InsertAtBegin(head, data);
                        break;
                    case 2:
                        printf("Enter index at which %d needs to be inserted: ", data);
                        scanf("%d", &index);
                        InsertInMiddle(head, data, index);
                        break;
                    case 3:
                        head = InsertAtEnd(head, data);
                        break;
                }
                break;
            case 2:
                printf("Delete element: \n");
                printf("1. At the beginning\n");
                printf("2. In the middle\n");
                printf("3. At the end\n");
                printf("Enter choice: ");
                scanf("%d", &new_choice);

                switch (new_choice)
                {
                    case 1:
                        head = DeleteAtBegin(head);
                        break;
                    case 2:
                        printf("Enter index to be deleted: ");
                        scanf("%d", &index);
                        DeleteInMiddle(head, index);
                        break;
                    case 3:
                        DeleteAtEnd(head);
                        break;
                }
                break;
            case 3: 
                Traverse(head);
                break;
            case 4:
                printf("Enter element to be updated: ");
                scanf("%d", &data);
                printf("Update element: \n");
                printf("1. At the beginning\n");
                printf("2. In the middle\n");
                printf("3. At the end\n");
                printf("Enter choice: ");
                scanf("%d", &new_choice);

                switch (new_choice)
                {
                    case 1:
                        UpdateAtBegin(head, data);
                        break;
                    case 2:
                        printf("Enter index to be updated: ");
                        scanf("%d", &index);
                        UpdateInMiddle(head, data, index);
                        break;
                    case 3:
                        UpdateAtEnd(head, data);
                        break;
                }
                break;
            case 5:
                printf("Enter element to be searched: ");
                scanf("%d", data);
                Search(head, data);
                break;
                
            case 6:
                printf("Program terminated");
                flow = 0;
                break;
        }
    }

    return 0;
}