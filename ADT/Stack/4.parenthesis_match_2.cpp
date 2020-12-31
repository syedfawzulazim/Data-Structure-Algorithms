
#include<iostream>
using namespace std;

class Node{
public:
    char data;
    Node *next;
};

class LL{
private:
    Node *top, *tail;
public:
    LL(){
        top = tail = nullptr;
    }
    ~LL(){
        Node *p = top;
            while(p){
            top = top->next;
            //cout<<endl<<p->data;
            delete p;
            p = top;
            }
    }

/////
    void display(){
        Node * p =  top;
        while(p){
            cout<<p->data<<" " ;
            p = p->next;
        }
    }

/////
void push(char x) {
    Node* t = new Node;
    if (t == nullptr){
        cout << "Stack Overflow!" << endl;
    } else {
        t->data = x;
        t->next = top;
        top = t;
    }
}


    int countStack(){
        int cn =0;
        Node *p = top;
        while(p){
            cn++;
            p=p->next;
        }
        return cn;
    }

///////
    char pop(){
        char x= -1;
        if(top == nullptr){
            cout<<"Empty!!!";
        }
        else{
            Node *p = top;
            x = top->data;
            top = top->next;
            delete p;
        }
        return x;
    }

/////////
    char peck (){
        int pos;
        char  x = -1;
        cout<<endl<<"Enter the position : ";
        cin>>pos;

        Node *p = top;

        for(int i=0; p != nullptr && i<pos-1; i++){
            p = p->next;
        }
        if(p != nullptr){
            return p->data;
        }
        else{
            return x;
        }
    }

///////
char stackTop() {
    if (top){
        return top->data;
    }
    return -1;
}

///////
    bool isEmpty(){
        return top?0: 1;
    }

    bool isFull(){
       Node *t = new Node;
      int r = t?0:1;
      delete t;
      return r;
    }

};

    int isBalanced(char *exp){
       LL st; //stack
        char x;
       for(int i=0; exp[i] != '\0'; i++ ){
        if(exp[i] == '(' || exp[i] == '{' || exp[i] == '['){
            cout<<"Push :" << exp[i]<<endl;
            st.push(exp[i]);
           }
           else if(exp[i] == ')' || exp[i] == '}' || exp[i] == ']' ){
                if(st.isEmpty()){
                    cout<<"E"<<endl;
                    return false;
                }
                else{
                        x = st.stackTop();

                        if( exp[i] - x == 1 || exp[i] - x == 2 ){
                                st.pop();
                        }
                        else{
                            return false;
                        }
                    }
            }
       }
       return st.isEmpty()?1:0;
    }
int main(){

    char A[] = "{ [ ( ) ] [ {  }] } ";
    cout << isBalanced(A) << endl;

//     char B[] = "{([a+b]}*[c-d])/e}";
//    cout << isBalanced(B) << endl;
//
//    char C[] = "{([{a+b]*[c-d])/e}";
//    cout << isBalanced(C) << endl;







return 0;
}


