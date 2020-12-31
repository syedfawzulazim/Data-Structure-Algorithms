
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


    Node *merginLL(Node *l2_head){

    Node *New, *last;

    if(head->data < l2_head->data){
        New = last = head;
        head = head->next;
        last->next = NULL;
    }
    else{
        New = last = l2_head;
        l2_head = l2_head->next;
        last->next = NULL;
    }

    while( head !=NULL && l2_head != NULL){
        if(head->data < l2_head->data){
            last->next = head;
            last = head;
            head = head->next;
            last->next = NULL;
        }
        else{
            last->next = l2_head;
            last = l2_head;
            l2_head = l2_head->next;
            last->next =NULL;
        }
    }

    if( head != NULL){
        last->next = head;
    }
    else{
        last->next = l2_head;
    }

        return New;
}

    friend main();
};


  void Display(Node *p){

    while(p){
        cout<<p->data<<" ";
         p=p->next;
        }
    }

int main(){

    LL l1,l2;

    Node *l3;

    l1.createLL();
    l2.createLL();

    l1.display();
    cout<<"--> ";
    l2.display();
    cout<<endl;

    l3 = l1.merginLL(l2.head);
    cout<<endl;
    Display(l3);


    cout<<endl;
    l1.display();


return 0;
}
