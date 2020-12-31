#include <iostream>
#include "Queue.h"
#include<stack>
#include<queue>

using namespace std;

class Tree{
public:
    Node *root;

    Tree(){
        root = nullptr;
    }
    ~Tree(){
        //postorderDelete(root); //best way to delete a tree
    }

    void createTree();
    void IterativePreOrder(Node *p);
    void IterativePostOrder(Node *p);
    void IterativeInOrder(Node *p);
    void LevelOrder(Node *p);
    int Level(Node *root);
    int Count(Node *p);

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


void Tree::IterativePreOrder(Node *p){

    stack<Node *> st;

    while( p || ! st.empty()){
        if(p){
            cout<<p->data<<" ";
            st.emplace(p);
            p = p->Lchild;
        }
        else{
            p = st.top();
            st.pop();
            p = p->Rchild;
        }
    }
}

void Tree::IterativePostOrder(Node *p){
    stack<long int> st;
    long int temp;
    while( p || !st.empty()){
        if(p){
            st.emplace((long int)p);
            p = p->Lchild;
        }
        else{
            temp = st.top();
            st.pop();
            if(temp > 0){
                st.emplace(-temp);
                p = ((Node *)temp)->Rchild;
            }
            else{
                cout<<((Node *)(-1 * temp))->data<<" ";
                p = NULL;
            }
        }
    }
}

void Tree::IterativeInOrder(Node *p){

      stack<Node *> st;

    while( p || ! st.empty()){
        if(p){
            st.emplace(p);
            p = p->Lchild;
        }
        else{
            p = st.top();
            st.pop();
            cout<<p->data<<" ";
            p = p->Rchild;
        }
    }

}

void Tree::LevelOrder(Node *p){
    queue<Node *> Q;

    cout<<p->data<<" ";

    Q.emplace(p);

    while(!Q.empty()){
        p = Q.front();
        Q.pop();
        if(p->Lchild){
            cout<<p->Lchild->data<<" ";
            Q.emplace(p->Lchild);
        }
        if(p->Rchild){
            cout<<p->Rchild->data<<" ";
            Q.emplace(p->Rchild);
        }
    }
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
    t.IterativePreOrder(t.root);

    cout<<endl;

    cout<<"PostOdrer : ";
    t.IterativePostOrder(t.root);

    cout<<endl;

    cout<<"InOdrer   : ";
    t.IterativeInOrder(t.root);

    cout<<endl;

    cout<<"LevelOdrer: ";
    t.LevelOrder(t.root);



    cout<<endl;
    cout<<endl;

    return 0;
}
