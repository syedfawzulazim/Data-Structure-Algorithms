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

   void circularDisplay(){

    Node *p = head;

    do{
        cout<<p->data<<" ";
        p=p->next;
    }while( p!= head);

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


    int circularDelete(){

    int pos,x;
    cin>>pos;

    if(pos<0 || pos > countNode()){
        return -1;
    }

    if( pos == 1){
            Node *p;
            while(p->next != head) p = p->next;
            p->next = head->next;
            x = head->data;
            delete head;
            head = p->next;
    }
    else{
        Node *p, *q;
        p = head;
        q = NULL;

        for(int i=0; i<pos-1;i++){
            q = p;
            p = p->next;
        }
        x = p->data;
        q->next = p->next;
        delete p;

    }

    return x;
}

};




int main(){

    LL l1,l2;

    l1.createLL();
    l1.circularDisplay();
    cout<<endl;

    cout<<l1.circularDelete();
    cout<<endl;
    l1.circularDisplay();



return 0;
}


