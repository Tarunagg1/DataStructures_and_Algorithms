#include<iostream>

using namespace std;

struct Node
{
    int data;
    struct Node *next;
};


Node* detectNodeCycle(Node* head){
    Node* slow = head;
    Node* fast = head;

    while(slow != fast && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast){
            return slow;
        }
    }
    return NULL;
}

int main(){

}