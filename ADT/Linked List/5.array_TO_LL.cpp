#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node *next;
};

class LL{
private:
    Node *head, *tail;
public:
    LL(){
    head = NULL;
    tail    = NULL;
    }
    ~LL(){
    Node *p = head;
    while( head ){
        head = head->next;
        delete p;
        p = head;
        }
    }
    LL(int A[], int n){

       Node *temp;
       int i=0;

       head = new Node;
       head->data = A[0];
       head->next = NULL;
       tail = head;

       for( i = 1; i<n; i++){

        temp = new Node;
        temp->data = A[i];
        temp->next = NULL;

        tail->next = temp;
        tail = temp;
       }
}

       void display(){
        Node *p = head;
        while(p){
            cout<<p->data<<" " ;
            p = p ->next;
        }
    }

  int sum(){
    Node *p = head;
    int sum = 0;
        while( p != 0){
            sum += p->data;
            p = p->next;
        }
    return sum;
  }

};

int main(){

    int A[] = { 1,2,3,4,5};

    LL l(A, 5);

    l.display();

    cout<<endl<<l.sum();

return 0;
}


