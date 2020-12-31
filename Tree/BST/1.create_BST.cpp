#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node *Lchild;
    Node *Rchild;
};

class BST{
private:
    Node *root;
public:
    BST(){
        root = nullptr;
    }
    ~BST(){
    }

    Node * getRoot(){
        return root;
    }

    void Insert(int key){
        Node *t = root;
        Node *r, *p;

        if( root == nullptr){
            p = new Node;
            p->data = key;
            p->Lchild = p->Rchild = nullptr;
            root = p;
            return;
        }
        while( t != nullptr){
            r = t;
            if(t->data > key){
                t = t->Lchild;
            }
            else if(t->data < key){
                t = t->Rchild;
            }
            else{
                return;
            }
        }

        p = new Node;
        p->data = key;
        p->Lchild = p->Rchild = nullptr;

        if(r->data > key){
            r->Lchild = p;
        }
        else{
            r->Rchild = p;
        }
    }


Node* rInsert(Node *p, int key) {
    Node* t;
    if (p == nullptr){
        t = new Node;
        t->data = key;
        t->Lchild = nullptr;
        t->Rchild = nullptr;
        return t;
    }

    if (key < p->data){
        p->Lchild = rInsert(p->Lchild, key);
    } else if (key > p->data){
        p->Rchild = rInsert(p->Rchild, key);
    }
    return p;  // key == p->data?
}

    void inOrder(Node *p){
        if(p){
            inOrder(p->Lchild);
            cout<<p->data<<" ";
            inOrder(p->Rchild);
        }
    }

    Node * Search(int key){
        Node *t = root;

        while( t != nullptr){
            if( t->data == key){
                return t;
            }
            else if( t->data < key){
                t = t->Rchild;
            }
            else{
                t = t->Lchild;
           }
        }
    return nullptr;
    }


    Node * Delete(Node *p,  int key){
        Node *q;

        if( p == nullptr){ //
            return nullptr;
        }
        if( p->Lchild == nullptr && p->Rchild == nullptr){ // for leaf node
            if( p == root){
                root = nullptr;
            }
            delete p;
            return nullptr;
        }

        if( p->data > key){ // search for the value
            p->Lchild = Delete(p->Lchild, key);
        }
        else if( p->data < key){
            p->Rchild = Delete(p->Rchild, key);
        }
        else{ // for replacement only last physical space is deleted others are modified
                if(Height(p->Lchild) > Height(p->Rchild)){
                    q = InPre(p->Lchild);
                    p->data = q->data;
                    p->Lchild = Delete (p->Lchild, q->data);
                }
                else{
                    q = InSucc(p->Rchild);
                    p->data = q->data;
                    p->Rchild = Delete (p->Rchild, q->data);
                }
        }
        return p;
    }

    int Height(Node *p){
        int x, y;
        if( p == nullptr){
            return 0;
        }
        x = Height(p->Lchild);
        y = Height(p->Rchild);

        return x>y ? x+1 : y+1;
    }

    Node * InPre(Node *p) // p->Lchild passed,  right most node of left sub tree
    {
        while (p && p->Rchild != nullptr){
            p = p->Rchild;
        }
        return p;
    }

    Node * InSucc(Node *p) // p->Rchild passed,  left most node of right sub tree
    {
        while (p && p->Lchild != nullptr){
            p = p->Lchild;
        }
        return p;
    }

};


int main(){

    BST bst;

    bst.Insert(5);
    bst.Insert(1);
    bst.Insert(2);
    bst.Insert(6);
    bst.Insert(8);
    bst.Insert(7);

    bst.inOrder(bst.getRoot());

    cout<<endl;

    Node *temp = bst.Search(3);
    if( temp != nullptr){
        cout<<"Found : "<< temp->data<<" ";
    }
    else{
        cout<<"Not Found";
    }

    //bst.Delete(bst.getRoot(),20);
    cout<<endl<<"After Delete : ";
    bst.inOrder(bst.getRoot());



    Node *tmp, *p;

//     inorder predecessor and successor
     p = bst.getRoot();
    cout<<endl<<"Root : "<<p<<" " <<p->data;
    tmp = bst.InPre(p->Lchild);
    cout <<endl<< "InPre: " << tmp->data << endl;

    tmp = bst.InSucc(p->Rchild);
    cout << "InSucc: " << tmp->data << endl;



return 0;
}
