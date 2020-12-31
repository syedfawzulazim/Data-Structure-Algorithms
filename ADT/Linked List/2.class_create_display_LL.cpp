
#include<iostream>
using namespace std;

class  Node{
public:
    int data;
    Node *next;
};

class LL{
private:
    Node *head, *tail;
public:
    LL()
    {
        head = NULL;
        tail = NULL;
    }
    ~LL()
    {
        Node *p = head;
        while(head){
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
            temp = NULL;
        }
        else{
            tail->next = temp;
            tail = temp;
            }
        }
    }

     void display(){
        while( head ){

            cout<<"head->data : "<<head->data<<" "<< "head :  "<<head<<" "<< " head-next :"<<head->next<<endl;
            cout<<"tail->data : "<<tail->data<<" "<< "tail :  "<<tail<<" "<< " tail-next :"<<tail->next<<endl;
            cout<<"&head->data : "<<&head->data<<" "<<"&head : "<< &head<<" "<< "&head->next : "<<&head->next<<endl;
            cout<<endl;
            cout<<head->data<<" ";
            cout<<endl;
            head = head->next;
        }
    }

};

int main(){

    LL l;
    l.createNode();
    cout<<endl;

    l.display();

return 0;
}
