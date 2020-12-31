#include<iostream>
using namespace std;


class Node{
public:
    int data;
    Node *next;
};

class LL{
private:
    Node *Front, *Rear;
public:
    LL(){
        Front = Rear = NULL;
    }
    ~LL() {
    Node* p = Front;
    while (Front){
        Front = Front->next;
        delete p;
        p = Front;
    }
}

    void enqueueF(int);
    void enqueueR(int);
    int dequeueF();
    int dequeueR();
    void display();
    bool isEmpty();
    bool isFull();
    int first();
    int last();
    int countNode();

};

void LL :: enqueueF(int x){

    Node *t =  new Node;
    if( t == NULL){
        cout<<"Queue Full. "<<endl;
    }
    else{
        t->data =x;
        t->next = NULL;
        if( isEmpty()){
            Front = Rear = t;

        }
        else{
           t->next = Front;
           Front = t;
        }
    }
}

void LL :: enqueueR(int x){

    Node *t =  new Node;
    if( t == NULL){
        cout<<"Queue Full. "<<endl;
    }
    else{
        t->data =x;
        t->next = NULL;
        if( isEmpty()){
            Front = Rear = t;

        }
        else{
           Rear->next = t;
           Rear = t;
        }
    }
}

int LL :: dequeueF(){
    int x =-1;
    Node *p = Front;

    if( Front == NULL) {
        cout<<"Queue is Empty."<<endl;
    }
    else{
        x = p->data;
        Front = Front->next;
        delete p;
    }
   return x;
}


//its not possible to set rear in previous node in single Linked list(Not done)
int LL :: dequeueR(){
    int x =-1;
    Node *p = Front;
    Node *t;

    if( Front == NULL) {
        cout<<"Queue is Empty."<<endl;
    }
    else{

    }
   return x;
}


bool LL :: isEmpty(){
    if( Front == NULL)
        return true;

    return  false;
}


bool LL :: isFull(){
    Node *t = new Node;
    if( t == NULL)
        return true;

    return  false;
}


int LL :: countNode(){
        int cn=0;
        Node *p = Front;

        while(p){
            cn++;
            p=p->next;
        }
        return cn;
    }


void LL :: display(){
    Node *p = Front;
    while(p){
        cout<<p->data<<" ";
        p=p->next;
    }
}


int main(){
    LL l;
    l.enqueueF(1);
    l.enqueueF(2);
    l.enqueueF(3);
    l.enqueueF(4);
    l.enqueueF(5);
    l.enqueueR(10);

    l.display();

    cout<<endl<<"Dequeue : "<<l.dequeueF()<<endl;
    cout<<endl<<"Dequeue : "<<l.dequeueF()<<endl;
    l.display();
    l.enqueueF(6);
    l.enqueueF(7);
    cout<<endl;
    l.display();

    //cout<<endl<<"isFull : "<<l.isFull();


return 0;
}

