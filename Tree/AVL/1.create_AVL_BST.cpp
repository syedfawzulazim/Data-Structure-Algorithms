#include <iostream>

using namespace std;

class Node {
public:
    Node* lchild;
    int data;
    Node* rchild;
    int height;
};

class AVL{
public:
    Node* root;

    AVL(){ root = nullptr; }

    // Helper methods for inserting
    int NodeHeight(Node* p);
    int BalanceFactor(Node* p);
    Node* LLRotation(Node* p);
    Node* RRRotation(Node* p);
    Node* LRRotation(Node* p);
    Node* RLRotation(Node* p);

    // Insert
    Node* rInsert(Node* p, int key);

    //Delete
    Node* Delete(Node *p, int key);
    Node* InPre (Node *p);
    Node* InSucc(Node *p);

    // Traversal
    void Inorder(Node* p);
    void Inorder(){ Inorder(root); }
    Node* getRoot(){ return root; }
};

int AVL::NodeHeight(Node *p) {
    int hl;
    int hr;

    hl = (p && p->lchild) ? p->lchild->height : 0;
    hr = (p && p->rchild) ? p->rchild->height : 0;

    return hl > hr ? hl + 1 : hr + 1;
}

int AVL::BalanceFactor(Node *p) {
    int hl;
    int hr;

    hl = (p && p->lchild) ? p->lchild->height : 0;
    hr = (p && p->rchild) ? p->rchild->height : 0;

    return hl - hr;
}

Node* AVL::LLRotation(Node *p) {
    Node* pl = p->lchild;
    Node* plr = pl->rchild;

    pl->rchild = p;
    p->lchild = plr;

    // Update height
    p->height = NodeHeight(p);
    pl->height = NodeHeight(pl);

    // Update root
    if (root == p){
        root = pl;
    }
    return pl;
}

Node* AVL::LRRotation(Node *p) {

        Node *pl = p->lchild;
        Node *plr = pl->rchild;

        pl->rchild = plr->lchild;
        p->lchild = plr->rchild;

        plr->lchild = pl;
        plr->rchild = p;

        p->height    = NodeHeight(p);
        pl->height   = NodeHeight(pl);
        plr->height = NodeHeight(plr);

        if(root == p){
            root = plr;
        }
        return plr;

}

Node* AVL::RRRotation(Node *p) {
    Node* pr = p->rchild;
    Node* prl = pr->lchild;

    pr->lchild = p;
    p->rchild = prl;

    // Update height
    p->height = NodeHeight(p);
    pr->height = NodeHeight(pr);

    // Update root
    if (root == p){
        root = pr;
    }
    return pr;
}



Node* AVL::RLRotation(Node *p) {
    return nullptr;
}

Node* AVL::rInsert(Node *p, int key) {
    Node* t;
    if (p == nullptr){
        t = new Node;
        t->data = key;
        t->lchild = nullptr;
        t->rchild = nullptr;
        t->height = 1;  // Starting height from 1 onwards instead of 0
        return t;
    }

    if (key < p->data){
        p->lchild = rInsert(p->lchild, key);
    } else if (key > p->data){
        p->rchild = rInsert(p->rchild, key);
    }

    // Update height
    p->height = NodeHeight(p);

    // Balance Factor and Rotation
    if (BalanceFactor(p) == 2 && BalanceFactor(p->lchild) == 1) {
        return LLRotation(p);
    } else if (BalanceFactor(p) == 2 && BalanceFactor(p->lchild) == -1){
        return LRRotation(p);
    } else if (BalanceFactor(p) == -2 && BalanceFactor(p->rchild) == -1){
        return RRRotation(p);
    } else if (BalanceFactor(p) == -2 && BalanceFactor(p->rchild) == 1){
        return RLRotation(p);
    }

    return p;
}

Node* AVL::InPre(Node *p) {
    while (p && p->rchild != nullptr){
        p = p->rchild;
    }
    return p;
}

void AVL::Inorder(Node *p) {
    if (p){
        Inorder(p->lchild);
        cout << p->data << ", " << flush;
        Inorder(p->rchild);
    }
}

Node* AVL::InSucc(Node *p) {
    while (p && p->lchild != nullptr){
        p = p->lchild;
    }
    return p;
}

Node* AVL::Delete(Node *p, int key){
    if(p == nullptr){
        return nullptr;
    }
    if(p->lchild == nullptr && p->rchild == nullptr){
        if( p == root){
            root = nullptr;
        }
        delete p;
        return nullptr;
    }

    if( p->data > key){
        p->lchild = Delete(p->lchild, key);
    }
    else if( p->data < key){
        p->rchild = Delete(p->rchild, key);
    }
    else{
            Node *q;
        if( NodeHeight(p->lchild) > NodeHeight(p->rchild)){
            q = InPre(p->lchild);
            p->data = q->data;
            p->lchild = Delete(p->lchild, q->data);
        }
        else{
            q = InSucc(p->rchild);
            p->data = q->data;
            p->rchild = Delete(p->rchild, q->data);
        }
    }

    //update height
    p->height = NodeHeight(p);

    // Balance Factor and Rotation
    if (BalanceFactor(p) == 2 && BalanceFactor(p->lchild) == 1) {  // L1 Rotation
        return LLRotation(p);
    } else if (BalanceFactor(p) == 2 && BalanceFactor(p->lchild) == -1){  // L-1 Rotation
        return LRRotation(p);
    } else if (BalanceFactor(p) == -2 && BalanceFactor(p->rchild) == -1){  // R-1 Rotation
        return RRRotation(p);
    } else if (BalanceFactor(p) == -2 && BalanceFactor(p->rchild) == 1){  // R1 Rotation
        return RLRotation(p);
    } else if (BalanceFactor(p) == 2 && BalanceFactor(p->lchild) == 0){  // L0 Rotation
        return LLRotation(p);
    } else if (BalanceFactor(p) == -2 && BalanceFactor(p->rchild) == 0){  // R0 Rotation
        return RRRotation(p);
    }

    return p;
}


int main() {

    // LL Rotation
    AVL tll;
    tll.root = tll.rInsert(tll.root, 30);
    tll.root = tll.rInsert(tll.root, 20);
    tll.root = tll.rInsert(tll.root, 10);

    tll.Inorder();
    cout << endl;

    // RR Rotation
    AVL trr;
    trr.root = trr.rInsert(trr.root, 10);
    trr.root = trr.rInsert(trr.root, 20);
    trr.root = trr.rInsert(trr.root, 30);

    trr.Inorder();
    cout << endl;

    // LR Rotation
    AVL tlr;
    tlr.root = tlr.rInsert(tlr.root, 20);
    tlr.root = tlr.rInsert(tlr.root, 10);
    tlr.root = tlr.rInsert(tlr.root, 30);
    tlr.root = tlr.rInsert(tlr.root, 25);
    tlr.root = tlr.rInsert(tlr.root, 28);

    tlr.Inorder();
    cout << endl;

    //Delete
    tlr.Delete(tlr.root, 28);

    tlr.Inorder();
    cout<<endl;

    return 0;
}


