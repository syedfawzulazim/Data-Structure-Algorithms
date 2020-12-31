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
        Front = Rear = 0;
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
    if (isFull()){
        cout << "Queue Overflow" << endl;
    }
    else{
        Rear = (Rear+1) % Size;
        Q[Rear]=x;
    }
}


int Queue :: dequeue(){
    int x = -1;
    if( Front == Rear){
        cout<<"Queue is Empty";
    }
    else{
        Front = (Front+1) % Size;
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
    if( (Rear+1) % Size == Front)
        return true;

    return false;
}

void Queue ::display() {
    int i = Front + 1;
    do {
        cout << Q[i]<<" ";
        i = (i + 1) % Size;
    } while (i != (Rear + 1) % Size);
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
    Queue q(5);

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    //one is left empty for front


    q.enqueue(5);


     q.display();
     cout<<endl;

    q.dequeue();
    q.dequeue();


    q.display();
     cout<<endl;

    q.enqueue(11);
    q.enqueue(12);

     cout<<endl;
    q.display();
     cout<<endl;

    //cout<<q.isEmpty()<<endl;
    //cout<<q.isFull()<<endl;

    cout<<"F: "<<q.first()<<endl;
    cout<<"L: "<<q.last()<<endl;



return 0;
}

