#include<iostream>
using namespace std;

class  Node{
public:
    int data;
    Node *next;
};

 void display(Node *p){
    while( p != 0){
        cout<<p->data<<endl;
        p = p->next;
    }
}

int main(){

    Node *first, *second, *third;

    first = new Node;
    second = new Node;
    third = new Node;

    first->data=20;
    first->next= second;

    second->data=30;
    second->next= third;

    third->data=40;
    third->next= NULL;

    display(first);

    delete first;
    delete second;
    delete third;

return 0;
}
