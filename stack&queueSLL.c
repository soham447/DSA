#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
}Node;

Node *top = NULL;
Node *front = NULL;
Node *rear = NULL;

// stack
void push(int value)
{
    Node *newNode = malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = top;
    top = newNode;
}

void pop()
{
    if (top == NULL)
    {
        printf("Stack Underflow\n");
        return;
    }
    Node *temp = top;
    top = (top)->next;
    printf("%d popped from stack\n", temp->data);
    free(temp);
}

void displayStack()
{
    Node* temp = top;
    if (temp == NULL)
    {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack elements: \n");
    while (temp != NULL)
    {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}

// Queue
void enqueue(int value)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    if (rear == NULL)
    {
        front = rear = newNode;
        return;
    }
    (rear)->next = newNode;
    rear = newNode;
}

void dequeue()
{

    if (front == NULL)
    {
        printf("Queue Underflow\n");
        return;
    }
    Node *temp = front;
    front = (front)->next;
    if (front == NULL)
    {
        rear = NULL;
    }
    printf("%d dequeued from queue\n", temp->data);
    free(temp);
}

void displayQueue()
{
    Node* temp = front;
    if (front == NULL)
    {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements: ");
    while (temp != NULL)
    {
        printf("%d, ", temp->data);
        temp = temp->next;
    }
}

int main()
{
    int choice;
    int value;

    while (1)
    {
        printf("\n1. Push to Stack\n2. Pop from Stack\n3. Display Stack\n");
        printf("4. Enqueue to Queue\n5. Dequeue from Queue\n6. Display Queue\n7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value to push: ");
            scanf("%d", &value);
            push(value);
            break;
        case 2:
            pop();
            break;
        case 3:
            displayStack();
            break;
        case 4:
            printf("Enter value to enqueue: ");
            scanf("%d", &value);
            enqueue(value);
            break;
        case 5:
            dequeue();
            break;
        case 6:
            displayQueue();
            break;
        case 7:
            return 0;
        default:
            printf("Invalid choice\n");
        }
    }
}
