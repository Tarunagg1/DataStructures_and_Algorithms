#include<iostream>

using namespace std;

struct Node
{
    int data;
    struct Node *next;
};

Node* reverse(struct Node* head){
    struct Node* cur = head;
    struct Node* prev = NULL;

    while(cur != NULL){
        struct Node* temp  = cur->next;
        cur->next = prev;
        prev = cur;
        cur = temp;
    }
    return prev;
}

int main(){

}