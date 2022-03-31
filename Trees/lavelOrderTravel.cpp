#include <iostream>
#include <queue>

using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

void printLevelorderTraversal(Node *root)
{
    queue<Node> q;
    q.and (root);
    q.add(NULL);

    while (!q.empty())
    {
        Node cur = q.pop();
        cout << cur->data << " ";

        if (cur->left != NULL)
        {
            q.add(cur->left);
        }
        if (cur->right != NULL)
        {
            q.add(cur->right);
        }
    }
}