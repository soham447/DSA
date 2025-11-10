#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int num;
    struct Node *next;
}Node;

Node *head = NULL;

Node *createNode(int choice)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->num = choice;
    newNode->next = NULL;
    return newNode;
}

void insertFront(int choice)
{
    Node *newNode = createNode(choice);
    newNode->next = head;
    head = newNode;
}

void insertEnd(int choice)
{
    Node *newNode = createNode(choice);
    if (!head)
    {
        head = newNode;
        return;
    }
    Node *temp = head;
    while (temp->next)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}

void insertMiddle(int choice, int pos)
{
    if (pos == 1)
    {
        insertFront(choice);
        return;
    }
    Node *temp = head;
    for (int i = 1; temp && i < pos - 1; i++)
    {
        temp = temp->next;
    }
    if (!temp)
    {
        printf("Invalid position!\n");
        return;
    }
    Node *newNode = createNode(choice);
    newNode->next = temp->next;
    temp->next = newNode;
}

void deleteFront()
{
    if (!head)
    {
        printf("List Empty!\n");
        return;
    }
    Node *temp = head;
    head = head->next;
    free(temp);
}

void deleteEnd()
{
    if (!head)
    {
        printf("List Empty!\n");
        return;
    }
    if (!head->next)
    {
        free(head);
        head = NULL;
        return;
    }
    Node *temp = head;
    while (temp->next->next)
    {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
}

void deleteMiddle(int pos)
{
    if (!head)
    {
        printf("List Empty!\n");
        return;
    }
    if (pos == 1)
    {
        deleteFront();
        return;
    }
    Node *temp = head;
    for (int i = 1; temp->next && i < pos - 1; i++)
    {
        temp = temp->next;
    }
    if (!temp->next)
    {
        printf("Invalid position!\n");
        return;
    }
    Node *del = temp->next;
    temp->next = del->next;
    free(del);
}

void display()
{
    if (!head)
    {
        printf("List Empty!\n");
        return;
    }
    Node *temp = head;
    printf("Display (Normal): ");
    while (temp)
    {
        printf("%d -> ", temp->num);
        temp = temp->next;
    }
    printf("\n");
}

void displayReverse(Node *node)
{
    if (!node)
    {
        return;
    }
    displayReverse(node->next);
    printf("%d -> ", node->num);
}

void reverseList()
{
    Node *prev = NULL, *curr = head, *next = NULL;
    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
}

int main()
{
    int choice, pos;

    while (1)
    {
        printf("MENU\n");
        printf("1. Insert Front\n2. Insert End\n3. Insert at Position\n");
        printf("4. Delete Front\n5. Delete End\n6. Delete at Position\n");
        printf("7. Display Normal\n8. Display Reverse\n9. Reverse List\n10. Exit\n");
        printf("Enter option: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter number: ");
            scanf("%d", &choice);
            insertFront(choice);
            continue;
        case 2:
            printf("Enter number: ");
            scanf("%d", &choice);
            insertEnd(choice);
            continue;
        case 3:
            printf("Enter number: ");
            scanf("%d", &choice);
            printf("Enter position: ");
            scanf("%d", &pos);
            insertMiddle(choice, pos);
            continue;
        case 4:
            deleteFront();
            continue;
        case 5:
            deleteEnd();
            continue;
        case 6:
            printf("Enter position: ");
            scanf("%d", &pos);
            deleteMiddle(pos);
            continue;
        case 7:
            display();
            continue;
        case 8:
            printf("Display (Reverse): ");
            displayReverse(head);
            printf("\n");
            continue;
        case 9:
            reverseList();
            continue;
        case 10:
            return 0;
        default:
            printf("Invalid choice!\n");
        }
    }
}
