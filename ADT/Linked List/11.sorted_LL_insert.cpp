#include<iostream>
using namespace std;

class Node {
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
    tail = NULL;
    }
    ~LL(){
        Node * p = head;
        while(p){
            delete p;
            p = p->next;
        }
    }

    void display(){
        Node *p = head;
        while(p){
            cout<<p->data<<" ";
            p = p->next;
        }
    }

    int countNode(){
        int l = 0;
        Node *p = head;
        while(p){
            l++;
            p = p->next;
        }
        return l;
    }

    void createByLastInsert(){
        int n, x;
        cin>>n;

        Node *t;

        for(int i =0; i<n; i++){

        cin>>x;

        t = new Node;
        t->data = x;
        t->next = NULL;


        if( head == NULL){
           head = tail = t;
        }
        else{
          tail->next = t;
          tail = t;
        }
      }
    }

    void stortedInsert(){

        int x;
        cin>>x;

        Node *t, *q;


        q = NULL;

        t = new Node;
        t->data = x;
        t->next = NULL;

        if(head == NULL){
            head = t;
        }
        else{
                Node * p = head;
            while( p && p->data < x ){  // 1 2 3 4  (6)
                q = p;
                p = p->next;
            }
            if( p == head){
                t->next = head;
                head = t;
            }
            else{
                t->next = q->next;
                q->next = t;
            }
        }
    }


};



int main(){

    LL l;

    l.createByLastInsert();
    l.display();
    cout<<endl;
    l.stortedInsert();
        l.display();
        cout<<endl;
    l.stortedInsert();
        l.display();








return 0;
}



