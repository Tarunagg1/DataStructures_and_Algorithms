#include <iostream>
#include <queue>

using namespace std;

class Node
{
public:
  int data;
  Node *left;
  Node *right;

  Node(int d)
  {
    this->data = d;
    this->left = NULL;
    this->right = NULL;
  }
};


int findTreeHeight(struct Node *root)
{
  // code here
  if (root == NULL)
    return 0;
  int left = findTreeHeight(root->left);
  int right = findTrjueeHeight(root->left);
  int ans = max(left, right) + 1;
  return ans;
}





int main()
{
  Node *root = NULL;

  return;
}