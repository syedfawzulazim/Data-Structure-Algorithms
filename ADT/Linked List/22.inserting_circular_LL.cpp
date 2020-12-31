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
     if (head)
     {
      Node * tmp = head;

      while (tmp->next != head)
        {
          Node * t = tmp;
//          cout<<tmp->data<<" ";
          tmp = tmp->next;
          delete(t);
        }
      delete tmp;
      head = NULL;
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

       do{
        cn++;
        p=p->next;
       }while( p != head);
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
        tail->next = head;
    }


    void circularDisplay(){

    Node *p = head;

    do{
        cout<<p->data<<" ";
        p=p->next;
    }while( p!= head);

    }

void insertNode(){
    int pos, x;
    cin>>pos>>x;

    if(pos<0 || pos > countNode()){
        return;
    }

    Node *t = new Node;
    t->data = x;

    if(pos ==0){
        if( head == NULL){
            head = tail = t;
            head->next = head;
        }
        else{
                Node * p = head;
                while( p->next != head) p = p->next;
                p->next = t;
                t->next = head;
                head =t;
        }
    }
    else{

        Node *p = head;

        for(int i=0; i<pos-1;i++) p = p->next;

        t->next = p->next;
        p->next = t;

    }
}




};




int main(){

    LL l1,l2;

    l1.createLL();
    l1.circularDisplay();
    cout<<endl;

    l1.insertNode();
    cout<<endl;
    l1.circularDisplay();



return 0;
}

