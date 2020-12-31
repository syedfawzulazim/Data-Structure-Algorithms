#ifndef STACK_H
#define STACK_H
#include "Queue.h"

class Stack
{
    public:
        Stack();
     ~Stack();

        void Push(Node *);
        void Pop();
        void display();
        bool isEmpty();

    private:
        Node *top, *tail;

};

#endif // STACK_H
