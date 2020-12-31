#include<iostream>
using namespace std;

class Stack{
private:
    int size;
    int top;
    int *s;

public:
    Stack(){
        cout<<"Enter Stack Size : ";
        cin>>size;
        top = -1;
        s = new int[size];
    }
    ~Stack(){
            delete [] s;
    }

/////
    void display(){
        if(top == -1){
            cout<<"Nothing to Show.";
        }
        for(int i=top; i>= 0; i--){
            cout<<s[i]<<" ";
        }
        cout<<endl;
    }

/////
    void push(){
    cout<<"How many numbers want to push ( <="<<size<<" ) :";
    int n;
    cin>>n;

    for(int i=0; i<n;i++){
        int x; cin>>x;
        if(top == size-1){
            cout<<"Stack OverFlow"<<endl;
        }
        else{
            top++;
            s[top] = x;
        }
      }
    }

///////
    int pop(){
        int x = -1;
        if(top == -1){
        cout<<"Stack UnderFlow";
        }
        else{
            x = s[top];
            top--;
        }
        return x;
    }

///////
    int peck (){
        int pos, x = -1;
        cin>>pos;

        if(top-pos+1 < 0){
            cout<<"Invalid Position."<<endl;
        }
        else{
            x = s[top-pos+1];
        }
    return x;
    }

/////
    int stackTop(){
        if(top == -1){
            return -1;
        }
     return s[top];
    }

/////
    bool isEmpty(){
        if(top == -1){
            return true;
        }
        return false;
    }

    bool isFull(){
        if(top == size-1){
            return true;
        }
        return false;
    }


};




int main(){
    Stack st;

    st.push();
    cout<<"Display from top : ";
    st.display();

    //cout<<"poped value : "<<st.pop()<<endl;
    //st.display();

    //cout<<"Peck value : "<<st.peck()<<endl;
    cout<<"Top value : "<<st.stackTop()<<endl;

    cout<<"IsEmpty : "<<st.isEmpty()<<endl;
    cout<<"IsFull : "<<st.isFull()<<endl;


return 0;
}
