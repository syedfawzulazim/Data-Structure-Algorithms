#include<bits/stdc++.h>
using namespace std;
class Node
{
public:
    int col;
    int row;
    int data;
    Node* next;
}*first;

void Create1(int A[][4]){
    Node *p,*t,*last;
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            if(A[i][j]!=0){
                if(first==NULL){
                    first=new Node();
                    first->data=A[i][j];
                    first->col=j;
                    first->row=i;
                    first->next=NULL;
                    last=first;
                }
                else{
                    p=first;
                    while(p){
                        last=p;
                        p=p->next;
                    }
                    t=new Node();
                    t->data=A[i][j];
                    t->col=j;
                    t->row=i;
                    t->next=NULL;
                    last->next=t;
                    last=t;
                }
            }
        }
    }
}



// void Create(Node *p,int r,int c,int d){
//     Node *t,*last;
//     if(first==NULL){
//         first=new Node();
//         first->data=d;
//         first->col=c;
//         first->row=r;
//         first->next=NULL;
//         last=first;
//     }
//     else{
//         while(p){
//             last=p;
//             p=p->next;
//         }
//         t=new Node;
//         t->data=d;
//         t->col=c;
//         t->row=r;
//         t->next=NULL;
//         last->next=t;
//         last=t;
//     }
// }

void Display(Node *p){
    cout<<"R: ";
    while(p){
        cout<<p->row<<" ";
        p=p->next;
    }

    p=first;
    cout<<endl;
    cout<<"C: ";
    while(p){
        cout<<p->col<<" ";
        p=p->next;
    }

    p=first;
    cout<<endl;
    cout<<"D: ";
    while(p){
        cout<<p->data<<" ";
        p=p->next;
    }
}


int main(){
    int A[][4]={‌{0,0,3,0},{0,2,0,1},{1,0,7,0},{0,0,0,9}};
    Create1(A);
    Display(first);
    return 0;
}

