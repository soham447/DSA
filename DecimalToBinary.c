#include <stdio.h>
#define MAX 32

int stack[MAX];
int top = -1;

void push(int n)
{
    if (top < MAX - 1)
    {
        stack[++top] = n;
    }
}

int pop()
{
    if (top == -1)
    {
        return -1;
    }
    return stack[top--];
}

int main()
{
    int decimal, remainder;

    printf("Enter a decimal number: ");
    scanf("%d", &decimal);

    if (decimal == 0)
    {
        printf("Binary: 0\n");
        return 0;
    }

    while (decimal > 0)
    {
        remainder = decimal % 2;
        push(remainder);
        decimal /= 2;
    }

    printf("Binary: ");
    while (top != -1)
    {
        printf("%d", pop());
    }
    printf("\n");

    return 0;
}
