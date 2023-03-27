#include <stdio.h>
#include <stdlib.h>


struct Node
{
    int data;
    struct Node* next;
};

struct Node* head = NULL;

struct Node* InsertAtBeginning(struct Node* head, int data)
{
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = head;
    head = node;
    
    return head;
}

void InsertInMiddle(struct Node* head, int data, int index)
{
    int i=1;
    struct Node* temp = head;
    struct Node* node = (struct Node*)malloc(sizeof(struct Node*));
    
    while (temp->next != NULL && i<index-1)
    {
        temp = temp->next;
        i++;
    }
    node->data = data;
    node->next = temp->next;
    temp->next = node;
}

struct Node* InsertAtEnd(struct Node* head, int data)
{
    struct Node* temp = head;
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));

    node->data = data;
    node->next = NULL;
    if (head == NULL)
    {
        head = node;
        return head;
    }
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = node;

    return head;
}

struct Node* DeleteAtBeginning(struct Node* head)
{
    struct Node* temp = head;
    head = head->next;
    free(temp);

    return head;
}

void DeleteInMiddle(struct Node* head, int index)
{
    struct Node* temp = head;
    int i=1;
    while (temp->next!= NULL && i<index-1)
    {
        temp = temp->next;
        i++;
    }
    struct Node* tmp = temp->next;
    temp->next = temp->next->next;
    free(tmp);
}

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

void UpdateAtBeginning(struct Node* head, int data)
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
    while (temp->next !=NULL)
    {
        temp = temp->next;
    }
    temp->data = data;
}


void Search(struct Node* head, int data)
{
    struct Node* temp = head;
    int i=1;
    while (temp!=NULL)
    {
        if (temp->data == data)
        {
            printf("%d found at index %d", data, i);
            return;
        }
        temp = temp->next;
        i++;
    }
    printf("%d not found in the linked list", data);
}

void Traverse(struct Node* head)
{
    struct Node* temp = head;
    while (temp != NULL)
    {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("NULL");
}

int main()
{
    int n, data, choice, new_choice, index, flow = 1;

    printf("Enter the number of elements in the Linked List: ");
    scanf("%d", &n);

    for (int i=0; i<n; i++)
    {
        printf("Enter element: ");
        scanf("%d", &data);
        head = InsertAtEnd(head, data);
    }

    while (flow)
    {
        printf("\nLINKED LIST OPERATIONS\n");
        printf("1. Traversing\n");
        printf("2. Insertion\n");
        printf("3. Deletion\n");
        printf("4. Updation\n");
        printf("5. Searching\n");
        printf("6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                Traverse(head);
                break;
            case 2:
                printf("Enter element to be inserted: ");
                scanf("%d", &data);
                printf("Insert element: \n");
                printf("1. At the beginning\n");
                printf("2. In the middle of the Linked List\n");
                printf("3. At the end\n");
                printf("Enter choice: ");
                scanf("%d", &new_choice);

                switch(new_choice)
                {
                    case 1:
                        head = InsertAtBeginning(head, data);
                        break;
                    case 2: 
                        printf("Enter index at which the elements needs to be inserted: ");
                        scanf("%d", &index);
                        InsertInMiddle(head, data, index);
                        break;
                    case 3:
                        head = InsertAtEnd(head, data);
                        break;
                }
                break;
            case 3:
                printf("Delete element: \n");
                printf("1. At the beginning\n");
                printf("2. In the middle of the Linked List\n");
                printf("3. At the end\n");
                printf("Enter choice: ");
                scanf("%d", &new_choice);

                switch(new_choice)
                {
                    case 1:
                        head = DeleteAtBeginning(head);
                        break;
                    case 2: 
                        printf("Enter index at which the elements needs to be deleted: ");
                        scanf("%d", &index);
                        DeleteInMiddle(head, index);
                        break;
                    case 3:
                        DeleteAtEnd(head);
                        break;
                }
                break;
            case 4:
                printf("Enter the value to be updated: ");
                scanf("%d", &data);
                printf("Update element: \n");
                printf("1. At the beginning\n");
                printf("2. In the middle of the Linked List\n");
                printf("3. At the end\n");
                printf("Enter choice: ");
                scanf("%d", &new_choice);

                switch(new_choice)
                {
                    case 1:
                        UpdateAtBeginning(head, data);
                        break;
                    case 2: 
                        printf("Enter index at which the elements needs to be updated: ");
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
                scanf("%d", &data);
                Search(head, data);
                break;
            case 6:
                printf("Program terminted");
                flow = 0;
                break;
        }
    }

    return 0;
}