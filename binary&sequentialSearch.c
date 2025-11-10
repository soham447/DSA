#include <stdio.h>
#include <string.h>

int n;
char contacts[50][50], key[50];

int sequentialSearch()
{
    for (int i = 0; i < n; i++)
    {
        if (strcmp(contacts[i], key) == 0)
        {
            return i;
        }
    }
    return -1;
}

int binarySearch()
{
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        int cmp = strcmp(contacts[mid], key);
        if (cmp == 0)
        {
            return mid;
        }
        else if (cmp < 0)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
}

void sortContacts(char contacts[][50], int n)
{
    char temp[50];
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (strcmp(contacts[i], contacts[j]) > 0)
            {
                strcpy(temp, contacts[i]);
                strcpy(contacts[i], contacts[j]);
                strcpy(contacts[j], temp);
            }
        }
    }
}

int main()
{
    printf("Enter number of contacts: ");
    scanf("%d", &n);

    printf("Enter contact names:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%s", contacts[i]);
    }
    

    printf("Enter name to search: ");
    scanf("%s", key);

    // Sequential Search
    int index = sequentialSearch(contacts, n, key);
    if (index != -1)
    {
        printf("Sequential Search: %s found at position %d\n", key, index + 1);
    }
    else
    {
        printf("Sequential Search: %s not found\n", key);
    }

    sortContacts(contacts, n);

    // Binary Search
    index = binarySearch(contacts, n, key);
    if (index != -1)
    {
        printf("Binary Search: %s found at position %d\n", key, index + 1);
    }
    else
    {
        printf("Binary Search: %s not found\n", key);
    }

    return 0;
}
