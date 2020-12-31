#include<iostream>
using namespace std;

struct Node{
    char element;
    int priority;
    Node *next;
};


class P_Queue{
private:
    Node *f ,*r; //front and rear
public:
    P_Queue(){
        f = r = NULL;
    }
    ~P_Queue(){

    }

    void push(char ele, int prio){

        Node *t = new Node;

        if( t==NULL){
            cout<<"Queue is Full";
        }
        else{
            t->element = ele;
            t->priority = prio;

            if( f == NULL || prio < f->priority){
                t->next = f;
                f = t;
            }
            else{

                Node *p = f;
                while( p->next != NULL && p->next->priority <= prio){
                    p = p->next;
                }
                t->next = p->next;
                p->next = t;
            }
        }
    }


    void pop(){
        Node *p = f;
        if( f == NULL){
            cout<<"Empty";
        }
        else{
            f= f->next;
            delete p;
        }
    }



    void display(){
        Node *p = f;
        while(p){
            cout<<p->element<<p->priority<<" ";
            p = p->next;
        }
    }

};





int main(){

    P_Queue pq;

    pq.push('A', 5);
    pq.push('B', 4);
    pq.push('C', 3);
    pq.push('D', 2);
    pq.push('E', 1);

    pq.display();

    pq.pop();
    cout<<endl;
    pq.display();


return 0;
}
