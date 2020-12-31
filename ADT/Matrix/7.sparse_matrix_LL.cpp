#include<iostream>
using namespace std;

class Node{
public:
    int col;
    int data;
    Node *next;
};

class sparse_By_LL{
private:
    int row;
    int colm;
    Node  **A;
    Node *head, *tail;

public:
    sparse_By_LL(int m, int n)
    :row(m),colm(n)
    {
        head = tail = nullptr;
        A = new Node *[m];
        for(int i=0;i<m;i++){A[i]=nullptr;};
    }

    ~sparse_By_LL(){
        Node * p = nullptr;
        for(int i=0; i<row; i++){
            p = A[i];
                for(int j=0; j<colm; j++){
                if( p && j == p->col){
                        cout<<endl<<p->data<<" ";
                        Node *tmp = p;
                        delete p;
                        p = tmp->next;
                    }
                }
            }
        }


    void create(){

       cout<<"Number of non-zero elements: ";

        int n;
        cin>>n;


    for(int i=0; i<n; i++){

              int r,c,d;

            cout<<"Enter the positions and value of element "<<i<<": ";

            cin>>r>>c>>d;

                Node *t = new Node;

                t->col = c;
                t->data = d;
                t->next = nullptr;


                if(A[r] == nullptr){
                    A[r] = t;
                }
                else{
                    Node *p=A[r];

                    while(p->next){p=p->next;};

                    p->next=t;
                }
            }
        }



    void display(){
        Node *p = nullptr;
        for(int i=0; i<row; i++){
            p = A[i];
            for(int j=0; j<colm; j++){
                if(p && j == p->col){
                    cout<<p->data<<" ";
                    p=p->next;
                }
                else{
                    cout<<"0 ";
                }
            }
            cout<<endl;
        }
    }


};
int main()
{
    sparse_By_LL Sp(4,4); //row, colm

    Sp.create();
    Sp.display();
    cout<<endl;

    return 0;
}
