#include "Stack.h"
#include<iostream>
using namespace std;

Stack::Stack()
{
    top = tail = nullptr;
}

Stack::~Stack()
{

}

void Stack::Push(Node *p){
    Node *t = new Node;
    if(!t){
        cout<<"Stack is Full";
    }

    t = p;
    t->Rchild = NULL;
    t->Lchild = NULL;

    if( top == nullptr){
        top= tail = t;
    }
    else{
        t->Lchild = tail;
        t->Rchild = tail->Rchild;

        tail->Rchild = t;
        tail = t;
    }
}


void Stack::Pop(){
    Node * p = tail;
    p->Lchild->Rchild = p->Rchild;
    p->Lchild = tail;
    delete p;
}



void Stack::display(){
    Node * p = top;
    while(p)
        {
            cout<<p->data<<" ";
            p = p->Rchild;
        }
}
