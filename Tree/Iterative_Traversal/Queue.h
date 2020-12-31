#ifndef QUEUE_H
#define QUEUE_H

class Node{
public:
    int data;
    Node *Lchild;
    Node *Rchild;
};


class Queue
{
    public:
        Queue(int);
     ~Queue();
        void enqueue(Node *x);
        Node* dequeue();
        void display();
        bool isEmpty();


    private:
        int Size;
        int Front;
        int Rear;
        Node **Q; //*Q for array Node * for Node
};

#endif // QUEUE_H
