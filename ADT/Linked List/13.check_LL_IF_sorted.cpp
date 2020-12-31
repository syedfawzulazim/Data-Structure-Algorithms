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

    bool checkForSort(){
        Node *p  = head;
        int x = INT_MIN;

        while(p != NULL){
            if(p->data < x){
                return false;
            }
            x = p->data;
            p = p->next;
        }
        return true;
    }

};


int main(){

    LL l;
    l.createLL();
    l.display();
    cout<<endl<<l.checkForSort(); //1 = true, 0 = false


return 0;
}

