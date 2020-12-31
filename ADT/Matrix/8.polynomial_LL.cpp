#include<iostream>
#include<cmath>
using namespace std;

class Node{
public:
    int coff;
    int exp;
    Node *next;
};

class poly_LL{
private:
    Node *head, *tail;
public:
    poly_LL(){
        head = tail = nullptr;
    }
    ~poly_LL(){
    }

    void create(){
        int n;
        cout<<"Enter the number of terms : ";
        cin>>n;

        Node *t;

        for(int i=0; i<n; i++){
            t = new Node;
            cin>>t->coff>>t->exp;
            t->next = nullptr;

            if(head == nullptr){
                head = tail = t;
            }
            else{
                tail->next = t;
                tail = t;
            }
        }
    }

        void display(){
        Node *p =head;
        while (p){
           // cout<<p->prev<<" "<<p->data<<" "<<p->next<<endl;
            cout<<p->coff<<"x"<<p->exp<<"+";
            p=p->next;
        }
    }

    double evaluate(){
    cout<<"Enter the value of x : ";
    int x;
    cin>>x;

    double sum = 0;
    Node * p =  head;

    while(p){
        sum+= p->coff *pow(x, p->exp);
        p = p->next;
    }
    return sum;
}




};




int main(){

    poly_LL l1;
    l1.create();
    //l1.display();
    cout<<endl<<l1.evaluate();
    cout<<endl;
    cout<<endl;
    l1.display();

return 0;
}
