#include <iostream>
#include <conio.h>

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

struct Node *insertNodeInBst(struct Node *root, int key){
    if(root == NULL) return createNode(key);

    if(root->data > key){
        root->left = insertNodeInBst(root->right, key);
    }else if(root->data < key){
        root->right = insertNodeInBst(root->right, key);
    }

    return root;
}


int main()
{
    struct Node *root = createNode(5);

    // linking
    root->left = createNode(3);
    root->right = createNode(6);
    root->left->left = createNode(1);
    root->left->right = createNode(10);

    if (isBst(root))
    {
        cout << "Yupss!! it is bst!" << endl;
    }
    else
    {
        cout << "Not Bst" << endl;
    }
}
