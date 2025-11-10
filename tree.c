#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
    char name[50];
    struct Node *left;
    struct Node *right;
};

struct Node *createNode(char name[])
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    strcpy(newNode->name, name);
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node *insert(struct Node *root, char name[])
{
    if (root == NULL)
    {
        return createNode(name);
    }
    if (strcmp(name, root->name) < 0)
    {
        root->left = insert(root->left, name);
    }
    else if (strcmp(name, root->name) > 0)
    {
        root->right = insert(root->right, name);
    }
    return root;
}

void inorder(struct Node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%s ", root->name);
        inorder(root->right);
    }
}

void preorder(struct Node *root)
{
    if (root != NULL)
    {
        printf("%s ", root->name);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct Node *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%s ", root->name);
    }
}

struct Node *search(struct Node *root, char name[])
{
    if (root == NULL || strcmp(root->name, name) == 0)
    {
        return root;
    }
    if (strcmp(name, root->name) < 0)
    {
        return search(root->left, name);
    }
    else
    {
        return search(root->right, name);
    }
}

int main()
{
    struct Node *root = NULL;
    int n, i;
    char name[50], searchName[50];

    printf("Enter the number of names to insert: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Enter name %d: ", i + 1);
        scanf("%s", name);
        root = insert(root, name);
    }

    printf("\nInorder traversal:\n");
    inorder(root);

    printf("\nPreorder traversal:\n");
    preorder(root);

    printf("\nPostorder traversal:\n");
    postorder(root);

    printf("\nEnter name to search: ");
    scanf("%s", searchName);

    struct Node *result = search(root, searchName);
    if (result != NULL)
    {
        printf("%s found in the directory.\n", searchName);
    }
    else
    {
        printf("%s not found in the directory.\n", searchName);
    }

    return 0;
}
