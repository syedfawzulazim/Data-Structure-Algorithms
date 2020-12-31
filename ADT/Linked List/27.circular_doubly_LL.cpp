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
     if (head)
     {
      Node * tmp = head;

      while (tmp->next != head)
        {
          Node * t = tmp;
//         cout<<tmp->data<<" ";
          tmp = tmp->next;
          delete(t);
        }
//          cout<<tmp->data<<" ";
      delete tmp;
      head = NULL;
    }
}

    //display from head to tail circular doubly LL

    void display_1(){
        Node *p =head;
        do{
           // cout<<p->prev<<" "<<p->data<<" "<<p->next<<endl;
            cout<<p->data<<" ";
            p=p->next;
        }while(p != head);
    }

     //display from tail to head circular doubly LL
        void display_2(){
        Node *p =tail;
        do{
            cout<<p->data<<" ";
            p=p->prev;
        }while( p != tail);
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
            tail->next = head;
            head->prev = tail;
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


};

int main(){

    dLL l1;

    l1.createDLL();
    l1.display_2();


    cout<<endl<<"LOOP : "<<l1.checkLoop()<<endl;
    cout<<endl<<"Nodes : "<<l1.countNode()<<endl;



return 0;
}


