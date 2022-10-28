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

int searchInBst(struct Node *root, int val)
{
    if (root == NULL)
        return 0;

    if (root->data == val)
    {
        return 1;
    }
    else if (val < root->data)
    {
        searchInBst(root->left, val);
    }
    else
    {
        searchInBst(root->right, val);
    }
}

int searchInBstIterative(struct Node *root, int key)
{
    while (root != NULL)
    {
        if (key == root->data)
        {
            return 1;
        }
        else if (key < root->data)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
    return 0;
}

void insertIntoBst(struct Node *root, int key)
{
    struct Node *prev = NULL;
    while (root != NULL)
    {
        prev = root;
        if (key == root->data)
        {
            printf("Can't insert allready in bst \n");
            return;
        }
        else if (key < root->data)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
    struct Node *newNode = createNewNode(key);
    if (key < prev->data)
    {
        prev->left = newNode;
    }
    else
    {
        prev->right = newNode;
    }
}

struct Node *inorderPredecessor(struct Node *root)
{
    root = root->right;
    while (root->right != NULL)
    {
        root = root->right;
    }
    return root;
}

struct Node *deleteIntoBst(struct Node *root, int key)
{
    struct Node *ipre;
    if (root == NULL)
    {
        return NULL;
    }

    if (root->left == NULL && root->right == NULL)
    {
        free(root);
        return NULL;
    }

    if (key < root->data)
    {
        root->left = deleteIntoBst(root->left, key);
    }
    else if (key > root->data)
    {
        root->right = deleteIntoBst(root->right, key);
    }
    else
    {
        ipre = inorderPredecessor(root);
        root->data = ipre->data;
        root->left = deleteIntoBst(root->left, ipre->data);
    }
    return root;
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

    inOrder(p);
    deleteIntoBst(p, 3);
    printf("\n");
    inOrder(p);
    // printf("%d", searchInBstIterative(p, 6));
    return 0;
}
