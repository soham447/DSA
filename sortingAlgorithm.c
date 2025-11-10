#include <stdio.h>

// Bubble Sort
void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Selection Sort
void selectionSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }
        if (minIndex != i)
        {
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }
}

// Insertion Sort
void insertionSort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Function to print array
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d, ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int n;
    printf("Enter number of products: ");
    scanf("%d", &n);

    int prices[n], temp[n];
    printf("Enter product prices:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &prices[i]);
    }

    // Bubble Sort
    for (int i = 0; i < n; i++)
    {
        temp[i] = prices[i];
    }
    bubbleSort(temp, n);
    printf("Bubble Sort: ");
    printArray(temp, n);

    // Selection Sort
    for (int i = 0; i < n; i++)
    {
        temp[i] = prices[i];
    }
    selectionSort(temp, n);
    printf("Selection Sort: ");
    printArray(temp, n);

    // Insertion Sort
    for (int i = 0; i < n; i++)
    {
        temp[i] = prices[i];
    }
    insertionSort(temp, n);
    printf("Insertion Sort: ");
    printArray(temp, n);

    return 0;
}
