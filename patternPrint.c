#include <stdio.h>

int main()
{
    int i, j, n;

    // Right-angled triangle with numbers
    printf("Right-angled triangle with numbers\n");
    printf("Enter number of rows: ");
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= i; j++)
        {
            printf("%d", j);
        }
        printf("\n");
    }

    // Diamond shape with numbers
    printf("\nDiamond shape with numbers\n");
    printf("Enter number of rows: ");
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n - i; j++)
        {
            printf(" ");
        } 
        for (j = 1; j <= i; j++)
        {
            printf("%d ", i);
        }
        printf("\n");
    }
    for (i = n - 1; i >= 1; i--)
    {
        for (j = 1; j <= n - i; j++)
        {
            printf(" ");
        } 
        for (j = 1; j <= i; j++)
        {
            printf("%d ", i);
        }
        printf("\n");
    }
    // Pyramid with asterisks
    printf("\nPyramid with asterisks\n");
    printf("Enter number of rows: ");
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n - i; j++)
        {
            printf(" ");
        }
        for (j = 1; j <= i ; j++)
        {
            printf("* ");
        }
        printf("\n");
    }
    // Pyramid with alphabets
    printf("\nPyramid with alphabets\n");
    printf("Enter number of rows: ");
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        char ch = 'A';
        for (j = 1; j <= n - i; j++)
        {
            printf(" ");
        }
        for (j = 1; j <= i; j++)
        {
            printf("%c", ch++);
        }
        ch -= 2;
        for (j = 1; j < i; j++)
        {
            printf("%c", ch--);
        }
        printf("\n");
    }
    return 0;
}
