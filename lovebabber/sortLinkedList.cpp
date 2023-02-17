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

Node *segregate(Node *head)
{
    if (head == NULL)
        return false;
    int zero = 0;
    int one = 0;
    int two = 0;
    Node *temp = head;

    while (temp != NULL)
    {
        temp = temp->next;
        if (temp->data == 0)
            zero++;
        else if (temp->data == 1)
            one++;
        else if (temp->data == 2)
            two++;
        temp = temp->next;
    }

    temp = head;

    while (temp != NULL)
    {
        if (zero != 0)
        {
            temp->data = 0;
            zero--;
        }
        else if (one != 0)
        {
            temp->data = 1;
            one--;
        }
        else if (two != 0)
        {
            temp->data = 2;
            two--;
        }
    }
    return head;
}

void insertAtTail(Node* &tail,Node* curr){
    tail->next = curr;
    tail = curr;
}

Node *segregateApproch2(Node *head)
{
    Node *zeroHead = new Node(-1);
    Node *zeroTail = zeroHead;

    Node *oneHead = new Node(-1);
    Node *oneTail = oneHead;

    Node *twoHead = new Node(-1);
    Node *twoTail = twoHead;

    Node* curr = head;

    while (curr != NULL)
    {
        int value = curr->data;

        if (value == 0)
        {
            insertAtTail(zeroTail, curr);
        }
        else if (value == 1)
        {
            insertAtTail(oneTail, curr);
        }
        else if (value == 2)
        {
            insertAtTail(twoTail, curr);
        }
        curr = curr->next;
    }

    // merge
    if(oneHead->next != NULL){
        zeroTail->next = oneHead->next;
    }else{
        zeroTail->next = twoTail->next;
    }


    oneTail->next = twoTail->next;
    twoTail->next = NULL;

    head = zeroHead->next;

    delete zeroHead;
    delete twoHead;
    delete oneHead;
    
    return head;
}

int main()
{
    Node *node1 = new Node(10);
    Node *head = node1;
    print(head);
}
