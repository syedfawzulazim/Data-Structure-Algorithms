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
        cout<<endl;
        int n;
        cin>>n;

        Node *t;

        t = new Node;
        t->data = n;
        t->next = NULL;


        if( head == NULL){
           head = tail = t;
        }
        else{
          tail->next = t;
          tail = t;
        }
    }


};



int main(){

    LL l;

    l.createByLastInsert();
    l.createByLastInsert();
    l.createByLastInsert();
    l.createByLastInsert();


    l.display();




return 0;
}


