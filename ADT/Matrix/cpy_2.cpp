#include <iostream>
using namespace std;

class node{

public:

    int col_no;

    int val;

    node *next;

};

class SparseMatrix{

private:

    int rows;

    int columns;

    node **A;

public:

    SparseMatrix(int r=0, int c=0){

        columns=c;

        rows=r;

        A=new node*[r];

        for(int i=0;i<r;i++){A[i]=0;};

    }

    void create(){

        cout<<"Number of non-zero elements: ";

        int n;

        cin>>n;



        for(int i=1;i<=n;i++){

            int r,j,v;

            cout<<"Enter the value and position of element "<<i<<": ";

            cin>>r>>j>>v;

                node *t=new node;

                t->val=v;

                t->col_no=j;

                t->next=0;

            if(A[r-1]==0){

                A[r-1]=t;

            }

            else{

              node *p=A[r-1];

              while(p->next){p=p->next;};

              p->next=t;

            };

        };
    }

    void display(){

        node *p;

    for(int i=1;i<=rows;i++){

            p=A[i-1];

        for(int j=1;j<=columns;j++){

            if(p&&p->col_no==j){

                    cout<<p->val<<" ";

                    p=p->next;

            }else{cout<<0<<" ";};

        };

        cout<<endl;

    };

    }

    friend SparseMatrix * add(SparseMatrix *p, SparseMatrix *q);

};



SparseMatrix * add(SparseMatrix *p, SparseMatrix *q){

SparseMatrix *r= new SparseMatrix(p->rows,p->columns);

if(p->rows!=q->rows||p->columns!=q->columns){

    return 0;

};

for(int i=1;i<=r->rows;i++){

        node *x,*y;

    x=p->A[i-1];

    y=q->A[i-1];

    if(x->col_no<y->col_no){

        r->A[i-1]=new node;

        r->A[i-1]->col_no=x->col_no;

        r->A[i-1]->val=x->val;

        r->A[i-1]->next=0;

        x=x->next;

    }else if(x->col_no>y->col_no){

        r->A[i-1]=new node;

        r->A[i-1]->col_no=y->col_no;

        r->A[i-1]->val=y->val;

        r->A[i-1]->next=0;

        y=y->next;}

    else{

        r->A[i-1]=new node;

        r->A[i-1]->col_no=x->col_no;

        r->A[i-1]->val=x->val+y->val;

        r->A[i-1]->next=0;

        x=x->next;

        y=y->next;};

        node *z=r->A[i-1];

    while(x&&y){

            node *t=new node;

        if(x->col_no<y->col_no){

        t->col_no=x->col_no;

        t->val=x->val;

        t->next=0;

        z->next=t;

        z=t;

        x=x->next;

        }else if(x->col_no>y->col_no){

        t->col_no=y->col_no;

        t->val=y->val;

        t->next=0;

        z->next=t;

        z=t;

        y=y->next;}else{

        t->col_no=x->col_no;

        t->val=x->val+y->val;

        t->next=0;

        z->next=t;

        z=t;

        x=x->next;

        y=y->next;};

    };

    if(x){z->next=x;};

    if(y){z->next=y;};



};

return r;

}

int main()

{

    SparseMatrix S(4,4);

   S.create();

   S.display();

   SparseMatrix T(4,4);

   T.create();

   T.display();

   cout<<"Addition of two matrix is: "<<endl;

   SparseMatrix *W=add(&S,&T);

   W->display();

    return 0;

}
