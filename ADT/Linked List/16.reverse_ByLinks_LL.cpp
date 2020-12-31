#include<iostream>
using namespace std;

class Node{
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
    Node *p = head;
    while(p){
        delete p;
        p = p->next;
        }
    }

    void display(){
    Node *p = head;
    while(p){
        cout<<p->data<<" ";
         p=p->next;
        }
    }

    int countNode(){
        int cn=0;
        Node *p = head;

        while(p){
            cn++;
            p=p->next;
        }
        return cn;
    }

    void createLL(){
        int n,x;
        cin>>n;

        for(int i=0; i<n; i++){
            cin>>x;

            Node *t = new Node;
            t->data = x;
            t->next = NULL;

            if(head == NULL){
                head = tail = t;
            }
            else{
                tail->next = t;
                tail = t;
            }
        }
    }

   void reverseLL(){

   Node *p, *q, *r;

   p = head;
   q = NULL;
   r = NULL;

   while(p){
    r = q;
    q = p;
    p = p->next;
    q->next = r;
   }
   head = q;
   }
};


int main(){

    LL l;
    l.createLL();
    l.display();
    l.reverseLL();
    cout<<endl;
    l.display();



return 0;
}

