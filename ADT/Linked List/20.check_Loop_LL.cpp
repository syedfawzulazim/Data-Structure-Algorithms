
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
    ~LL(){ //not done
            Node *temp = head;
            int flag = 0;

        while( temp->next != head->next->next  || flag == 0){
            if( temp->next == head->next->next){
            flag = 1;
            }

            cout<<temp->data<<" ";
            Node *t = temp;
            temp = temp->next;
            delete t;

        }
            cout<<temp->data<<" ";
            delete temp;
            flag=0;
    }

    void display(){
    Node *p = head;
    int flag = 0;
    do{
        if( p == head->next->next){
            flag = 1;
        }
        cout<<p->data<<" ";
         p=p->next;
        }while( p != head->next->next  || flag == 0);
    }

    int countNode(){
        int cn=0;
            Node *p = head;
            int flag = 0;
    do{

        if( p == head->next->next){
            flag = 1;
        }
        cn++;
         p=p->next;
        }while( p != head->next->next  || flag == 0);
        flag =0;
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
        tail->next = head->next->next; // makes a LL loop
    }

    bool checkLoop(){
        Node *p , *q;

        p =  q = head;

        do {

            p = p->next;
            q = q->next;
            q = (q != NULL)? q->next : q;

        } while( p!=NULL && q!=NULL && p!=q );

        return p==q?true:false;
    }

    friend main();
};



int main(){

    LL l1;

    //this circular LL is different type check createLL()

    l1.createLL();
     //cout<<l1.checkLoop()<<endl;
    //cout<<l1.countNode()<<endl;
     l1.display();
     cout<<endl<<"Destructor called : "<<endl;


return 0;
}

