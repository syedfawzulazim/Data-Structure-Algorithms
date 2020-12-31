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
    while( head ){
        head = head->next;
        delete p;
        p = head;
        }
    }

    void createNode(){
        int n;
        cin>>n;


        for(int i=0; i<n; i++){

            int value;
            cin>>value;

            Node *temp = new Node;
            temp->data = value;
            temp->next = NULL;

        if(head == NULL){
            head = temp;
            tail = temp;
            //temp = NULL;
        }
        else{
                tail->next = temp;
                tail = temp;
            }
        }
    }




    friend main();

};

    int sum(Node *p){
        int sum = 0;
        while(p){

            sum = sum + p->data;
            p = p ->next;

        }
        return sum;
    }




int main(){

LL l;

l.createNode();

cout<<sum(l.head);

return 0;
}

