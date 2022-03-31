#include <iostream>

using namespace std;

#define n 3

class node
{
    public:
        int data;
        node *next;

        node(int val)
        {
            data = val;
            next = NULL;
        }
};

class queue{
    node* front;
    node* back;

public:
    queue(){
        front = NULL;
        back = NULL;
    }

    bool isEmpty(){
        if(front == NULL) return true;
        return false;
    }


    void enQueue(int x){
        node* newNode = new node(x);

        if(front == NULL){
            back = newNode;
            front = newNode;
        }
        back->next = newNode;
        back = newNode;
    }

    void deQueue(){

        if(isEmpty()){
            cout<<"Queue is empty"<<endl;
        }
        node* todelete = front;
        front = front->next;
        cout<<"Pop element is: "<<todelete->data<<endl;
        delete todelete;
    }
    
   void peek(){

        if(isEmpty()){
            cout<<"Queue is empty"<<endl;
        }
        cout<<"Peek element is: "<<front->data<<endl;
    }
    
};


int main()
{
    queue q;
    q.enQueue(20);
    q.enQueue(30);
    q.enQueue(40);
    q.deQueue();
    q.deQueue();
    q.peek();
}
