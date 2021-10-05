#include <iostream>
#include <conio.h>
#include <cstdlib>

using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void inorder(struct Node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

void preorder(struct Node *root)
{
    if (root != NULL)
    {
        cout << root->data << " ";
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
        cout << root->data << " ";
    }
}

int height(Node *root)
{
    if (root == NULL)
        return 0;

    int lh = height(root->left);
    int rh = height(root->right);
    return max(lh, rh) + 1;
}

bool isBalenced(Node *root)
{
    if (root == NULL)
        return true;

    if (isBalenced(root->left) == false)
        return false;
    if (isBalenced(root->right) == false)
        return false;

    int lh = height(root->left);
    int rh = height(root->right);

    if (abs(lh - rh) <= 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    struct Node *root = createNode(1);

    // linking
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);

    //        1
    //     2     3
    //  4    5
}
