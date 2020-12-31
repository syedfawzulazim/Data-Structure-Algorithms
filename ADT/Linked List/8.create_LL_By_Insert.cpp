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
        while(head){
            head = head->next;
            delete p;
            p = head;
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

    void createByInsert(){
        cout<<endl;
        int n, x;
        cin>>n;

        if( n < 0 || n > countNode() ){
                cout<<"Wrong Index "<<endl;
            return;
        }

        cin>>x;

        Node *t;

        t = new Node;
        t->data = x;
        t->next = NULL;


        if( n == 0){
            t->next= head;
            head = t;
        }
        else{
            Node *p = head;
                for(int i=0; i<n-1; i++){
                    p = p->next;
            }
            t->next = p->next;
            p->next = t;
        }
    }


};



int main(){

    LL l;

    l.createByInsert(); // first index must be zero and then index should be valid
    l.createByInsert();
    l.createByInsert();
    l.createByInsert();

    l.display();




return 0;
}

