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

        display(head); // calls the display function here;

        cout<<endl;

        cout<<CountNodeRecursive(head); // counts+sums node by calling recursive function here;

        cout<<endl;

        cout<<CountNodeLoop(head); // counts+sums node by calling loop function here;
    }


// display using recursion : T-> O(n) || S-> O(n)
    void display(Node *p){
        if(p != NULL){

            cout<<p->data<<" ";
            display(p->next);

                  // reverse printing
                 //display(p->next);
                //cout<<p->data<<" ";
        }
    }


// count+sum nodes using recursion : T-> O(n) || S-> O(n)
    int CountNodeRecursive(Node *p){
        if( p == NULL){
            return 0;
        }
        else{
            return CountNodeRecursive(p->next)+1;

            //sum of all nodes
            //return CountNodeRecursive(p->next)+p->data;
        }
    }

    // count+sum nodes using LOOP : T-> O(n) || S-> O(1)
    int CountNodeLoop(Node *p){
       int c =0;
       int sum =0;
            while(p != NULL){
                c++;
                sum =sum + p->data;
                p = p->next;
       }
       return c;
       //return sum;
    }
};



int main(){

LL l;

l.createNode();

return 0;
}
