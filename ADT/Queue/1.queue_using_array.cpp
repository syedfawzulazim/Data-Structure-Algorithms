#include<iostream>
using namespace std;

class Queue{

private:
    int Size;
    int Front;
    int Rear;
    int *Q;

public:
    Queue(int Size)
    :Size(Size)
    {
        Front = Rear = -1;
        Q = new int[this->Size];
    }
    ~Queue() {
    delete [] Q;
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

void Queue :: enqueue(int x){
    if( Rear == Size-1){
        cout<<"Queue is Full  ";
    }
    else{
        Rear++;
        Q[Rear]=x;
    }
}


int Queue :: dequeue(){
    int x = -1;
    if( Front == Rear){
        cout<<"Queue is Empty";
    }
    else{
        Front++;
        x = Q[Front];
    }
    return x;
}

bool Queue :: isEmpty(){
    if( Front == Rear)
        return true;

    return false;
}


bool Queue :: isFull(){
    if( Rear == Size-1)
        return true;

    return false;
}


void Queue :: display(){
    for(int i=Front+1; i<=Rear; i++){
        cout<<Q[i]<<" ";
    }
    cout<<endl;
}

int Queue :: first(){
    int x;
    x = Q[Front+1];
    return x;
}

int Queue :: last(){
    int x;
    x = Q[Rear];
    return x;
}





int main(){
    Queue q(4);

    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(5);
    q.enqueue(7);
    q.display();

    cout<<q.isEmpty()<<endl;

    cout<<q.first()<<endl;
    cout<<q.last()<<endl;



return 0;
}
