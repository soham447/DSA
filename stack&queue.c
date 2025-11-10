#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

int stack[SIZE], queue[SIZE];
int top = -1;
int front = -1, rear = -1;

// Stack 
void push(int item)
{
    if (top == SIZE - 1)
    {
        printf("Stack Overflow!\n");
    }
    else
    {
        stack[++top] = item;
        printf("Pushed: %d\n", item);
    }
}

void pop()
{
    if (top == -1)
    {
        printf("Stack Underflow!\n");
    }
    else
    {
        printf("Popped: %d\n", stack[top--]);
    }
}

void displayStack()
{
    if (top == -1)
    {
        printf("Stack is empty!\n");
    }
    else
    {
        printf("Stack: ");
        for (int i = 0; i <= top; i++)
        {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

// Queue 
void enqueue(int item)
{
    if (rear == SIZE - 1)
    {
        printf("Queue Overflow!\n");
    }
    else
    {
        if (front == -1)
        {
            front = 0;
        }
        rear++;
        queue[rear] = item;
        printf("Enqueued: %d\n", item);
    }
}

void dequeue()
{
    if (front == -1 || front > rear)
    {
        printf("Queue Underflow!\n");
    }
    else
    {
        printf("Dequeued: %d\n", queue[front++]);
    }
}

void displayQueue()
{
    if (front == -1 || front > rear)
    {
        printf("Queue is empty!\n");
    }
    else
    {
        printf("Queue: ");
        for (int i = front; i <= rear; i++)
        {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

// main
int main()
{
    int choice, model, item;
    printf("Choose Model:\n1. Stack\n2. Queue\n");
    scanf("%d", &model);

    do
    {
        if (model == 1)
        {
            printf("\nStack Menu\n1. Push\n2. Pop\n3. Display\n4. Exit\n");
            scanf("%d", &choice);
            switch (choice)
            {
            case 1:
                printf("Enter item: ");
                scanf("%d", &item);
                push(item);
                break;
            case 2:
                pop();
                break;
            case 3:
                displayStack();
                break;
            case 4:
                exit(0);
            }
        }
        else if (model == 2)
        {
            printf("\nQueue Menu\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
            scanf("%d", &choice);
            switch (choice)
            {
            case 1:
                printf("Enter item: ");
                scanf("%d", &item);
                enqueue(item);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                displayQueue();
                break;
            case 4:
                exit(0);
            }
        }
    } while (1);

    return 0;
}
