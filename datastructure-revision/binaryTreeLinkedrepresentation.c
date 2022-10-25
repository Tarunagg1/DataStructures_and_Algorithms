#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *createNewNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void inOrder(struct Node *root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

void preOrder(struct Node *root)
{
    if (root != NULL)
    {

        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void postOrder(struct Node *root)
{
    if (root != NULL)
    {

        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->data);
    }
}

int isBst(struct Node *root)
{
    static struct Node *prev = NULL;
    if (root != NULL)
    {
        if (!isBst(root->left))
        {
            return 0;
        }
        if (prev != NULL && root->data <= prev->data)
        {
            return 0;
        }
        prev = root;
        return isBst(root->right);
    }
    else
    {
        return 1;
    }
}

int searchInBst(struct Node *root){
    
}

int main()
{
    struct Node *p = createNewNode(5);
    struct Node *p1 = createNewNode(3);
    struct Node *p2 = createNewNode(6);
    struct Node *p3 = createNewNode(1);
    struct Node *p4 = createNewNode(4);

    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;

    printf("%d", isBst(p));
    return 0;
}
