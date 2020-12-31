#include <iostream>
#include "Queue.h"

using namespace std;

class Tree{
public:
    Node *root;

    Tree(){
        root = nullptr;
    }
    ~Tree(){
        postorderDelete(root); //best way to delete a tree
    }

    void createTree();
    void preOrder(Node *p);
    void postOrder(Node *p);
    void inOrder(Node *p);
    void levelOrder(Node *p);
    int Level(Node *root);
    int Count_Node(Node *p);
    int Count_degree_0(Node *p);
    int Count_degree1(Node *p);
    int Count_degree2(Node *p);
    int Count_degree_1_2(Node *p);

    void postorderDelete(Node *ptr);

};

void Tree::createTree(){

    int x;
    cout<<"Enter the root value : ";
    cin>>x;

    root = new Node;
    root->data = x;
    root->Lchild = root->Rchild = nullptr;

    Queue q(100);
    q.enqueue(root);

    Node *p, *t;

    while( !q.isEmpty()){

        p = q.dequeue();

        cout<<"Enter the Left Child "<< p->data <<" : ";
        cin>>x;

        if(x != 0){
            t = new Node;
            t->data = x;
            t->Lchild = t->Rchild = nullptr;

            p->Lchild = t;
            q.enqueue(t);
        }

        cout<<"Enter the Right Child "<< p->data <<" : ";

        cin>>x;

        if(x != 0){
            t = new Node;
            t->data = x;
            t->Lchild = t->Rchild = nullptr;

            p->Rchild = t;
            q.enqueue(t);
        }
    }
}

void Tree::preOrder(Node *p){
    if(p){
        cout<<p->data<<" ";
        preOrder(p->Lchild);
        preOrder(p->Rchild);
    }
}

void Tree::postOrder(Node *p){
    if(p){
        postOrder(p->Lchild);
        postOrder(p->Rchild);
        cout<<p->data<<" ";
    }
}


void Tree::inOrder(Node *p){
    if(p){
        inOrder(p->Lchild);
        cout<<p->data<<" ";
        inOrder(p->Rchild);

    }
}


int Tree::Level(Node *root){
    int x=0, y=0;
    if(root == NULL){
        return 0;
    }

    x = Level(root->Lchild);
    y = Level(root->Rchild);

    if(x>y){
        return x+1;
    }
    else{
        return y+1;
    }
}


int Tree::Count_Node(Node *p)
{
    int x=0, y=0;
    if( p != NULL){
        x = Count_Node(p->Lchild);
        y = Count_Node(p->Rchild);
        return x+y+1;
    }
    return 0;
}

int Tree::Count_degree_0(Node *p)
{
    int x=0, y=0;
    if( p != NULL){
        x = Count_degree_0(p->Lchild);
        y = Count_degree_0(p->Rchild);
        if( p->Lchild == NULL && p->Rchild == NULL){
            return x+y+1;
        }
        else{
            return x+y;
        }
    }
    return 0;
}


//short code for degree_0
/*
int Count_degree_0(Node *p)
{
    if(p == NULL){
        return 0;
    }
    if( !p->Lchild && !p->Rchild){
        return Count_degree_0(p->Lchild)+Count_degree_0(p->Rchild)+1;
    }

    return Count_degree_0(p->Lchild)+Count_degree_0(p->Rchild);
}
*/






int Tree::Count_degree1(Node *p)
{
    int x=0, y=0;
    if( p != NULL){
        x = Count_degree1(p->Lchild);
        y = Count_degree1(p->Rchild);
        if( p->Lchild != NULL ^ p->Rchild != NULL){
            return x+y+1;
        }
    }
    return 0;
}

int Tree::Count_degree2(Node *p)
{
    int x=0, y=0;
    if( p != NULL){
        x = Count_degree2(p->Lchild);
        y = Count_degree2(p->Rchild);
        if( p->Lchild != NULL && p->Rchild != NULL){
            return x+y+1;
        }
    }
    return 0;
}

int Tree::Count_degree_1_2 (Node *p)
{
    int x=0, y=0;
    if( p != NULL){
        x = Count_degree_1_2(p->Lchild);
        y = Count_degree_1_2(p->Rchild);
        if( p->Lchild || p->Rchild ){
            return x+y+1;
        }
    }
    return 0;
}









//destructor function
void Tree::postorderDelete(Node *ptr)
        {
            if(ptr !=NULL)
            {
                postorderDelete(ptr->Lchild);
                postorderDelete(ptr->Rchild);
                cout<<"\n deleting "<<ptr<<flush;
                delete ptr;
            }
        }




int main()
{
    Tree t;

    t.createTree();

    cout<<endl;
    cout<<endl;
    cout<<"PreOdrer  : ";
    t.preOrder(t.root);

    cout<<endl;

    cout<<"PostOdrer : ";
    t.postOrder(t.root);

    cout<<endl;

    cout<<"InOdrer   : ";
    t.inOrder(t.root);

    cout<<endl;
    cout<<endl;
    cout<<"Level : ";
    cout<<t.Level(t.root);
     cout<<endl;
    cout<<"Height : ";
    cout<<t.Level(t.root)-1;

    cout<<endl;
    cout<<endl;
    cout<<"Count Node : ";
    cout<<t.Count_Node(t.root);
     cout<<endl;

    cout<<endl;
    cout<<endl;
    cout<<"Count Degree 0: ";
    cout<<t.Count_degree_0(t.root);
     cout<<endl;



    return 0;
}
