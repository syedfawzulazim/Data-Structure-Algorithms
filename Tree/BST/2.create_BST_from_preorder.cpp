#include<iostream>
#include<stack>
using namespace std;

class Node{
public:
    int data;
    Node * Lchild;
    Node * Rchild;
};

class BSTfromPre{
private:
    Node *root;
public:
    BSTfromPre(){
        root = nullptr;
    }
    ~BSTfromPre(){
    }


    void createFromPre(int pre[], int n);
    void inorder(Node *p);
    Node * getRoot(){return root;}



};

void BSTfromPre::createFromPre(int pre[], int n)
{
        stack<Node *> st;
        Node *t, *p;
        int i = 0;

        root = new Node;
        root->data = pre[i++];
        root->Lchild = root->Rchild = nullptr;
        p = root;

        while( i < n){
            if(p->data > pre[i]){
                t = new Node;
                t->data = pre[i++];
                t->Lchild = t->Rchild = nullptr;
                p->Lchild = t;
                st.push(p);
                p = t;
            }
            else{
                if(p->data < pre[i] && st.empty() ? 32767 : st.top()->data > pre[i]){
                        t = new Node;
                        t->data = pre[i++];
                        t->Lchild = t->Rchild = nullptr;
                        p->Rchild = t;
                        p =t;
                }
                else{
                    p = st.top();
                    st.pop();
                }
            }
        }
}

void BSTfromPre::inorder(Node *p){
    if(p){
        inorder(p->Lchild);
        cout<<p->data<<" ";
        inorder(p->Rchild);
    }
}

int main()
{
    int pre[] = {30, 20, 10, 15, 25, 40, 50 , 45};
    int s = sizeof(pre)/sizeof(pre[0]);

    BSTfromPre bst;

    bst.createFromPre(pre, s);

    bst.inorder(bst.getRoot());

return 0;
}
