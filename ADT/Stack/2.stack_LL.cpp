#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node *next;
};

class LL{
private:
    Node *top, *tail;
public:
    LL(){
        top = tail = nullptr;
    }
    ~LL(){
        Node *p = top;
            while(p){
            top = top->next;
            //cout<<endl<<p->data;
            delete p;
            p = top;
        }
    }

/////
    void display(){
        Node * p =  top;
        while(p){
            cout<<p->data<<" " ;
            p = p->next;
        }
    }

/////
    void push_create(){
    cout<<"How many numbers want to push : " ;
    int n;
    cin>>n;

    for(int i=0; i<n;i++){
            int x; cin>>x;

            Node *t;
            t= new Node;

            if(t==NULL){
                cout<<"Stack is full.";
            }
            else{
                    t->data = x;
                    t->next = top;
                    top = t;
            }
        }
    }

    int countStack(){
        int cn =0;
        Node *p = top;
        while(p){
            cn++;
            p=p->next;
        }
        return cn;
    }

///////
    int pop(){
        int x= -1;
        if(top == nullptr){
            cout<<"Empty!!!";
        }
        else{
            Node *p = top;
            x = top->data;
            top = top->next;
            delete p;
        }
        return x;
    }

/////////
    int peck (){
        int pos, x = -1;
        cout<<"Enter the position : ";
        cin>>pos;

        Node *p = top;

        for(int i=0; p != nullptr && i<pos-1; i++){
            p = p->next;
        }
        if(p != nullptr){
            return p->data;
        }
        else{
            return x;
        }
    }

///////
    int stackTop(){
        if(top){
            return top->data;
        }
     else{
        return -1;
        }
    }

///////
    bool isEmpty(){
        return top?0:1;
    }

    bool isFull(){
       Node *t = new Node;
      int r = t?0:1;
      delete t;
      return r;
    }


};




int main(){
    LL l1;

    l1.push_create();
    cout<<"Display from top : ";
    l1.display();

    cout<<endl;
    cout<<"Number of elements : "<<l1.countStack();

    cout<<endl;
    cout<<"Poped value : "<<l1.pop();

    cout<<endl<<"Display after pop : ";
    l1.display();

    cout<<endl;
    cout<<"Peck value : "<<l1.peck();

    cout<<endl;
    cout<<"Top value : "<<l1.stackTop();

    cout<<endl;
    cout<<"Empty : "<<l1.isEmpty();

     cout<<endl;
    cout<<"IsFuLL : "<<l1.isFull();

return 0;
}

