
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
    cout<<endl<<"Delete called : ";
      while (tmp->next != head)
        {
          Node * t = tmp;
          cout<<tmp->data<<" ";
          tmp = tmp->next;
          delete(t);
        }
          cout<<tmp->data<<" ";
      delete tmp;
      head = NULL;
    }
}


    int countNode(){
        int cn=0;
            Node *p = head;

    do{
        cn++;
         p=p->next;
        }while( p != head );

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


    // circular display
    void circularDisplay(){

    Node *p = head;

    do{
        cout<<p->data<<" ";
        p=p->next;
    }while( p!= head);

}

    void display(){
        Node *p =head;
        while (p){
           // cout<<p->prev<<" "<<p->data<<" "<<p->next<<endl;
            cout<<p->data<<" ";
            p=p->next;
        }
    }

    //recursive display
    void CirDisplayRecur(Node *p){
    static int flag = 0;

    if( p != head || flag == 0 ){
        flag=1;
        cout<<p->data<<" ";
        CirDisplayRecur(p->next);
    }
    flag =0;
}


    bool checkLoop(){
        Node *p , *q;

        p =  q = head;

        do {

            p = p->next;
            q = q->next;
            q = (q != NULL)? q->next : q;

        } while( p!=NULL && q!=NULL && p!=q );

        return p == q ? true : false;

}


friend main();
};




int main(){

    LL l1,l2;

    l1.createLL();
    //l1.display(); // this is not circular display

    //l1.CirDisplayRecur(l1.head);
   l1.circularDisplay();


    cout<<endl;

    cout<<l1.countNode();
    //cout<<endl<<"LOOP : "<<l1.checkLoop()<<endl;




return 0;
}

