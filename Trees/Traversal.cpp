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

void LevelOrder(struct Node *root)
{
    if (root == NULL)
    {
        return;
    }

    queue<Node *> q;

    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Node *node = q.front();
        q.pop();

        if (node != NULL)
        {
            cout << node->data << " ";

            if (node->left)
                q.push(node->left);

            if (node->right)
                q.push(node->right);
        }
        else if (!q.empty())
        {
            q.push(NULL);
        }
    }
}

int sumAtK(struct Node *root, int k)
{
    if (root == NULL)
        return -1;

    queue<Node *> q;
    int currentLevel = 0;
    q.push(root);
    q.push(NULL);
    int sum = 0;

    while (!q.empty())
    {
        Node *node = q.front();
        q.pop();

        if (node != NULL)
        {
            if (currentLevel == k)
            {
                sum += node->data;
            }

            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
        }
        else if (!q.empty())
        {
            q.push(NULL);
            currentLevel++;
        }
    }
    return sum;
}

int countNodesInBinaryTree(struct Node *root)
{
    if (root == NULL)
        return 0;
    return countNodesInBinaryTree(root->left) + countNodesInBinaryTree(root->right);
}

int sumOfNodesInTree(struct Node *root)
{
    if (root == NULL)
        return 0;
    return sumOfNodesInTree(root->left) + sumOfNodesInTree(root->right) + root->data;
}

int calcHeight(struct Node *root)
{
    if (root == NULL)
        return 0;

    int lheight = calcHeight(root->left);
    int rheight = calcHeight(root->right);

    return max(lheight, rheight) + 1;
}

void sumReplaceMent(Node *root)
{

    if (root == NULL)
        return;

    sumReplaceMent(root->left);
    sumReplaceMent(root->right);

    if (root->left != NULL)
    {
        root->data += root->left->data;
    }

    if (root->right != NULL)
    {
        root->data += root->right->data;
    }
}

void rightView(Node *root)
{
    if (root == NULL)
        return;

    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        int n = q.size();
        for (int i = 0; i < n; i++)
        {
            Node *curr = q.front();
            q.pop();

            if (i == n - 1)
            {
                cout << curr->data << " ";
            }

            if (curr->left != NULL)
            {
                q.push(curr->left);
            }
            if (curr->right != NULL)
            {
                q.push(curr->right);
            }
        }
    }
}

void leftView(Node *root)
{
    if (root == NULL)
        return;

    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        int n = q.size();

        for (int i = 1; i <= n; i++)
        {
            Node *temp = q.front();
            q.pop();

            if (i == 1)
            {
                cout << temp->data << " ";
            }

            if (temp->left != NULL)
                q.push(temp->left);
            if (temp->right != NULL)
                q.push(temp->right);
        }
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

    // preorder(root);
    // LevelOrder(root);

    // cout << sumAtK(root, 3);
    // cout << countNodesInBinaryTree(root);

    // cout << sumOfNodesInTree(root);

    // cout << calcHeight(root);

    // preorder(root);
    // cout << endl;
    // sumReplaceMent(root);
    // preorder(root);
    // cout << endl;
}
