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

    void concatinateLL(Node *l2_head){
    tail->next = l2_head;
    l2_head = NULL;
    }

friend main();
};




int main(){

    LL l1,l2, *l3;
    l1.createLL();
    l2.createLL();
    cout<<endl;
    l1.display();
    cout<<"---> ";
    l2.display();
    l1.concatinateLL(l2.head);
    cout<<endl;
    l1.display();

return 0;
}


