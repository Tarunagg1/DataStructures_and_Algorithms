#include <iostream>
#include <map>

using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int d)
    {
        this->data = d;
        this->next = NULL;
    }
};

void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

Node *reverse(Node *head)
{
    Node *curr = head;
    Node *prev = NULL;
    Node *next = NULL;

    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

void insertAtTail(Node *&head, Node *&tail, int digit)
{
    Node *temp = new Node(digit);
    if (head == NULL)
    {
        head = temp;
        tail = temp;
        return;
    }
    else
    {
        tail->next = temp;
        tail = temp;
    }
    return;
}

Node *add(Node *first, Node *second)
{
    int carry = 0;
    Node *ansHead = NULL;
    Node *ansTail = NULL;

    while (first != NULL && second != NULL)
    {
        int sum = first->data + second->data + carry;
        int digit = sum % 10;
        insertAtTail(ansHead, ansTail, digit);
        carry = digit / 10;
        first = first->next;
        second = second->next;
    }

    // int sum = ca
    while (first != NULL)
    {
        int sum = carry + first->data;
        int digit = sum % 10;
        insertAtTail(ansHead, ansTail, digit);
        carry = digit / 10;
        first = first->next;
    }
    while (second != NULL)
    {
        int sum = carry + second->data;
        int digit = sum % 10;
        insertAtTail(ansHead, ansTail, digit);
        carry = digit / 10;
        second = second->next;
    }

    while (carry != 0)
    {
        int sum = carry;
        int digit = sum % 10;
        insertAtTail(ansHead, ansTail, digit);
        carry = digit / 10;
    }
    return ansHead;
}

Node *addTwoLists(Node *first, Node *second)
{
    first = reverse(first);
    second = reverse(second);

    Node *ans = addTwoLists(first, second);
    ans = reverse(ans);
    return ans;
}

int main()
{
    Node *node1 = new Node(10);
    Node *head = node1;
    print(head);
}
