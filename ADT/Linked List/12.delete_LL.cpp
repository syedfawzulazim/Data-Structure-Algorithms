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

    int deleteLL(){

        int pos;
        cin>>pos;

        if(pos <= 0 || pos > countNode()){
            return -1;
        }

        Node *p, *q;
        int x=-2;

        if(pos == 1){
            x = head->data;
            p = head;
            head = head->next;
            delete p;
        }
        else{
            p = head;
            q = NULL;

            for(int i=0; i<pos-1; i++){
                q=p;
                p=p->next;
            }
           q->next = p->next;
           x = p->data;
           delete p;
        }
        return x;
    }


};


int main(){

    LL l;
    l.createLL();
    l.display();
    cout<<endl;
    cout<<l.deleteLL();
    cout<<endl;
    l.display();


return 0;
}
