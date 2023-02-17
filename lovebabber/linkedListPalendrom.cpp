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

Node* getMid(Node* head){
    Node* slow = head;
    Node* fast = head->next;

    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

Node* reverse(Node* head){
    Node* curr = head;
    Node* prev = NULL;
    Node* next = NULL;

    while(curr != NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

bool isPalindrome(Node* head)
{
    if(head == NULL || head->next == NULL){
        return true;
    }
    Node* mid = getMid(head);

    Node* temp = mid->next;
    mid->next = reverse(temp);

    Node* head1 = head;
    Node* head2 = mid->next;

    while (head2 != NULL)
    {
        if(head1->data != head2->data){
            return false;
        }
        head1 = head1->next;
        head2 = head2->next;
    }
    return true;
}



int main()
{
    Node *node1 = new Node(10);
    Node *head = node1;
    print(head);
}
