#include <stdio.h>
#include <stdlib.h>

struct BST
{
    int data;
    struct BST *left;
    struct BST *right;
};

typedef struct BST node;
node *root = NULL;

node *search(node *root, int key)
{
    if (root == NULL)
    {
        return NULL;
    }
    else
    {
        if (key == root->data)
            return (root);
        else if (key < root->data)
            return search(root->left, key);
        else
            return search(root->right, key);
    }
}

node *insert(node *root, int key)
{
    if (root == NULL)
    {
        node *newnode = (node *)malloc(sizeof(node));
        newnode->left = NULL;
        newnode->right = NULL;
        newnode->data = key;
        return newnode;
    }
    else if (key < root->data)
    {
        root->left = insert(root->left, key);
    }
    else
    {
        root->right = insert(root->right, key);
    }
    return root;
}

void preorder(struct BST *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(struct BST *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void postorder(struct BST *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

int main()
{
    int data, choice;
    printf("\n1.Insert \n2. Inorder Traversal \n3.Pre-Order Traversal \n4.Post-Order Traversal \n5.Exit\n");
    do
    {
        printf("ENTER YOUR CHOICE: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\nENTER THE DATA: ");
            scanf("%d", &data);
            root = insert(root, data);
            break;

        case 2:
            printf("DATA: ");
            inorder(root);
            printf("\n");
            break;

        case 3:
            printf("DATA: ");
            preorder(root);
            printf("\n");
            break;

        case 4:
            printf("DATA: ");
            postorder(root);
            printf("\n");
            break;

        case 5:
            printf("EXITING.....\n");
            break;
        }
    } while (choice != 5);

    return 0;
}
