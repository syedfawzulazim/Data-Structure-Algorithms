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

    //linear search literation
    Node * searchNode(){
        int s;
        cin>>s;

        Node *p = head;
        while(p){
            if(s == p->data){
                return p;
            }
            p = p->next;
        }
        return NULL;
    }


    //linear search recursive
    Node *searchR(Node *p, int key){
        if(p == NULL)
            return NULL;
        if(key == p->data)
            return p;
        return searchR(p->next, key);
    }

    //improved linear search by changing position to head
    Node * improvedSearch(){
        int s;
        cin>>s;

        Node *p = head;
        Node *q = NULL;

        while(p !=NULL){
            if(s == p->data){
            q->next = p->next;
            p->next = head;
            head = p;
            return p;
            }
            q= p;
            p = p->next;
        }

        return NULL;

    }



friend main();
};





int main(){

    LL l;

    l.createNode();
    l.display();

    cout<<endl;
    Node *l1;

//    l1 = l.searchNode();
//    if( l1 !=NULL){
//    cout<<l1->data;
//    }
//    else{
//        cout<<"Not present";
//    }


//    l1 = l.searchR(l.head, 3);
//    cout<<l1<<endl;
//    cout<<l1->data;


    l1 = l.improvedSearch();
    if( l1 !=NULL){
    cout<<l1->data;
    }
    else{
        cout<<"Not present";
    }

    cout<<endl;
      l.display();


return 0;
}

