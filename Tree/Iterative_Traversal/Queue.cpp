#include "Queue.h"
#include<iostream>
using namespace std;

Queue::Queue(int Size)
:Size(Size)
{
    Front = Rear = -1;
    Q = new Node *[this->Size];
}
Queue::~Queue()
{
    delete [] Q;
}

void Queue::enqueue(Node *x )
{
    if( Rear == Size-1){
        cout<<"FULL";
    }
    else{
        Rear++;
        Q[Rear] = x;
    }
}

Node * Queue::dequeue(){
    Node * x =NULL;
    if( Front == Rear){
        cout<<"Empty";
    }
    else{
        Front++;
        x = Q[Front];
    }
    return x;
}


bool Queue::isEmpty(){
    if(Front == Rear){
        return true;
    }
    return false;
}
