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

bool removeDuplicateSortedList(Node *head)
{
    if (head == NULL)
        return false;

    Node *curr = head;

    while (curr != NULL)
    {
        if ((curr->next != NULL) && curr->data == curr->next->data)
        {
            // duplicate found
            Node *tobeDelet = curr->next;
            curr->next = tobeDelet->next;
            delete (tobeDelet);
        }
        else
        {
            curr = curr->next;
        }
    }
    return head;
}

bool removeDuplicateUnsortedList(Node *head)
{
    if (head == NULL)
        return false;

    Node *curr = head;

    while (curr != NULL)
    {
        if ((curr->next != NULL) && curr->data == curr->next->data)
        {
            // duplicate found
            Node *tobeDelet = curr->next;
            curr->next = tobeDelet->next;
            delete (tobeDelet);
        }
        else
        {
            curr = curr->next;
        }
    }
    return head;
}

int main()
{
    Node *node1 = new Node(10);
    Node *head = node1;
    print(head);
}
