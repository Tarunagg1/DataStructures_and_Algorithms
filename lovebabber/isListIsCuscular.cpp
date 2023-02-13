#include <iostream>

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

bool isListIsCircular(Node *head)
{
    if (head == NULL) return true;

    Node* temp = head;

    while (temp != NULL && temp != head)
    {
        temp = temp->next;
    }
    
    if(temp == head){
        return true;
    }else{
        return false;
    }

}

int main()
{
    Node *node1 = new Node(10);
    Node *head = node1;
    print(head);
}

