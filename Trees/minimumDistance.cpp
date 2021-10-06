#include <iostream>
#include <conio.h>
#include <bits/stdc++.h>

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

Node *LCA(Node *root, int n1, int n2)
{
    if (root == NULL)
        return NULL;

    if (root->data == n1 || root->data == n2)
        return root;

    Node *left = LCA(root->left, n1, n2);
    Node *right = LCA(root->right, n1, n2);

    if (left != NULL || right != NULL)
        return root;

    if (left == NULL || right == NULL)
        return NULL;

    if (left != NULL)
        return LCA(root->left, n1, n2);

    return LCA(root->right, n1, n2);
}

int findDist(Node *root, int k, int dist)
{
    if (root == NULL)
        return -1;

    if (root->data == k)
        return dist;

    int left = findDist(root->left, k, dist + 1);
    if (left != -1)
        return left;

    return findDist(root->right, k, dist + 1);
}

int distanceBetweenNodes(Node *root, int n1, int n2)
{
    Node *lca = LCA(root, n1, n2);

    int d1 = findDist(root, n1, 0);
    int d2 = findDist(root, n1, 0);
    return d1 + d2;
}

int main()
{
    struct Node *root = createNode(1);

    // linking
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->right->right = createNode(5);

    //        1
    //     2     3
    //  4          5

    cout << distanceBetweenNodes(root, 4, 5) << " ";
}
