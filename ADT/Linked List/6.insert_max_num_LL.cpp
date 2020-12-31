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

    void createNode(){
            int n;
            cin>>n;

            for(int i=0; i<n; i++){
                    int value;
                    cin>>value;
                Node *t = new Node;
                t->data = value;
                t->next = NULL;

                if(head == NULL){
                    head = t;
                    tail   =  t;
                }
                else{
                    tail->next = t;
                    tail = t;
                }
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

    void insertNode(){
        cout<<endl;
        int n, x;
        cin>>n>>x;
        Node *t;

        t = new Node;
        t->data = x;
        t->next = NULL;

        if( n < 0 || n > countNode()){
            return;
        }

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

    int maxNode(){
        Node *p = head;
        int m = INT_MIN;

        while(p){
            if(m < p->data){
                m = p->data;
            }
            p= p->next;
        }
        return m;
    }




    friend main();
};


//recursive function for max element
    int maxNodeR(Node *p){

        int x =0;

        if(p==0){
            return INT_MIN;
        }
        else{
            x = maxNodeR(p->next);

            if(x > p->data){
                return x;
            }
            else
                return p->data;
        }

        //return x > p->data? x : p->data;

    }



int main(){

    LL l;
    l.createNode();
    l.display();
    cout<<endl<<l.countNode();
    cout<<endl;

//    l.insertNode();
//    cout<<endl;

//    l.display();
//    cout<<endl<<l.countNode();

//    cout<<endl;
//    cout<<l.maxNode();

    cout<<endl;
    cout<<maxNodeR(l.head);




return 0;
}
