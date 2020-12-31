#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node *prev;
    Node *next;
};

class dLL{
private:
    Node *head, *tail;
public:
    dLL(){
        head = NULL;
        tail = NULL;
    }
    ~dLL(){
        Node *p = head;
        while(head){
        head = head->next;
        delete p;
        p = head;
        }
    }

    //display from head to tail
    void display_1(){
        Node *p =head;
        while (p){
           // cout<<p->prev<<" "<<p->data<<" "<<p->next<<endl;
            cout<<p->data<<" ";
            p=p->next;
        }
    }

     //display from tail to head
        void display_2(){
        Node *p =tail;
        while (p){
            cout<<p->data<<" ";
            p=p->prev;
        }
    }

    int countNode(){
    Node *p = head;
    int cn = 0;
    while(p){
        cn++;
        p=p->next;
    }
    return cn;
}

    void createDLL(){
        int n;
        cin>>n;

        for(int i=0; i<n; i++){
            int x;
            cin>>x;

            Node *t = new Node;
            t->prev = NULL;
            t->data = x;
            t->next = NULL;

                if(head == NULL){
                    head = tail =t;
                }
                else{
                    t->prev = tail;
                    t->next = tail->next;

                    tail->next = t;
                    tail = t;
                }
        }
    }

void reverseLL(){

    Node *p = head;
    Node *temp= NULL;
    while(p){

        temp = p->next;
        p->next = p->prev;
        p->prev = temp;

        p=p->prev;

        if(p != NULL && p->next == NULL){
            head =p;
        }
    }
}

};

int main(){

    dLL l1;

    l1.createDLL();
    l1.display_1();
    l1.reverseLL();
    cout<<endl;
    l1.display_1();



return 0;
}


