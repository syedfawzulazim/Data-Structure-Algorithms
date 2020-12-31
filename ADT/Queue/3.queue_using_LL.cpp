#include<iostream>
using namespace std;

    static int cn = 0;

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

    void enqueue(int);
    int dequeue();
    void display();
    bool isEmpty();
    bool isFull();
    int first();
    int last();
    int Count();

};

void LL :: enqueue(int x){

    Node *t =  new Node;
    if( t == NULL){
        cout<<"Queue Full. "<<endl;
    }
    else{
        t->data =x;
        t->next = NULL;
        if( isEmpty()){
            Front = Rear = t;
            cn++;
        }
        else{
            Rear->next = t;
            Rear = t;
            cn++;
        }
    }
}

int LL :: dequeue(){
    int x =-1;
    Node *p = Front;

    if( Front == NULL) {
        cout<<"Queue is Empty."<<endl;
    }
    else{
        cn--;
        x = p->data;
        Front = Front->next;
        delete p;
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




void LL :: display(){
    Node *p = Front;
    while(p){
        cout<<p->data<<" ";
        p=p->next;
    }
}



int main(){
    LL l;
    l.enqueue(1);
    l.enqueue(2);
    l.enqueue(3);
    l.enqueue(4);
    l.enqueue(5);
    l.display();
    cout<<endl<<"Dequeue : "<<l.dequeue()<<endl;
    cout<<endl<<"Dequeue : "<<l.dequeue()<<endl;
    l.display();
    l.enqueue(6);
    l.enqueue(7);
    cout<<endl<<"isFull : "<<l.isFull();
    cout<<endl<<"Count : "<<cn;

return 0;
}
