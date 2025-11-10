#include <stdio.h>
#include <stdlib.h>

#define MAX 50

int visited[MAX];
int queue[MAX], front = -1, rear = -1;

void enqueue(int node)
{
    if (rear == MAX - 1)
    {
        printf("Queue Overflow\n");
        return;
    }
    if (front == -1)
    {
        front = 0;
    }
    rear++;
    queue[rear] = node;
}

int dequeue()
{
    if (front == -1 || front > rear)
    {
        printf("queue is empty!");
        return -1; 
    }
    return queue[front++];
}

// BFS
void BFS(int n, int adj[MAX][MAX], int start)
{
    for (int i = 0; i < n; i++)
    {
        visited[i] = 0;
    }

    enqueue(start);
    visited[start] = 1;
    printf("BFS traversal starting from building %d: ", start);

    while (front <= rear)
    {
        int node = dequeue();
        printf("%d ", node);

        for (int i = 0; i < n; i++)
        {
            if (adj[node][i] && !visited[i])
            {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
    printf("\n");
}

// DFS 
void DFS(int n, int adj[MAX][MAX], int node)
{
    visited[node] = 1;
    printf("%d ", node);

    for (int i = 0; i < n; i++)
    {
        if (adj[node][i] && !visited[i])
        {
            DFS(n, adj, i);
        }
    }
}

int main()
{
    int n, start;
    int adj[MAX][MAX];

    printf("Enter number of buildings: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix (%dx%d):\n", n, n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &adj[i][j]);
        }
    }

    printf("Enter starting building for BFS and DFS (0 to %d): ", n - 1);
    scanf("%d", &start);

    BFS(n, adj, start);

    for (int i = 0; i < n; i++)
    {
        visited[i] = 0;
    }
    printf("DFS traversal starting from building %d: ", start);
    DFS(n, adj, start);
    printf("\n");

    return 0;
}
