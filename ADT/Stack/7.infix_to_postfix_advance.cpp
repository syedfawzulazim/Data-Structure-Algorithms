#include<iostream>
#include<cstring>
using namespace std;

class Stack{
private:
    int size;
    int top;
    char *s;

public:
    Stack(int m){
    size = m;
    top = -1;
    s = new char[size];
    }
    ~Stack(){
        delete [] s;
    }

    void display(){
    if(top == -1){
        cout<<"Nothing is Stack.";
    }
    for(int i=top; i>=0; i--){
        cout<<s[i]<<" ";
    }
    cout<<endl;
    }

    void push(char x){
        if(top == size-1){
            cout<<"Overflow.";
        }
        else{
            top++;
            s[top] = x;
        }
    }

    char pop(){
        char x = -1;
        if(top == -1){
            cout<<"ST UF";
        }
        else{
            x = s[top];
            top--;
        }
    return x;
    }

     bool isEmpty(){
        if(top == -1){
            return true;
        }
        return false;
    }

    char stackTop(){
            char x = -1;
        if( top == -1){
            return x;
        }
        else{
            return s[top];
        }
        return x;
    }

int isOperand(char x){
    if (x == '+' || x == '-' || x == '*' || x == '/' ||
        x == '^' || x == '(' || x == ')'){
        return 0;
    }
    return 1;
}

int outPrecedence(char x){
    if (x == '+' || x == '-'){
        return 1;
    } else if (x == '*' || x == '/'){
        return 3;
    } else if (x == '^'){
        return 6;
    } else if (x == '('){
        return 7;
    } else if (x == ')'){
        return 0;
    }
    return -1;
}

int inPrecedence(char x){
    if (x == '+' || x == '-'){
        return 2;
    } else if (x == '*' || x == '/'){
        return 4;
    } else if (x == '^'){
        return 5;
    } else if (x == '('){
        return 0;
    }
    return -1;
}

    friend char * convert(char *);

};


char* convert(char* infix){

    int m = strlen(infix);

    Stack st(m);

    char* postfix = new char [m + 1];

    int i = 0;
    int j = 0;

    while (infix[i] != '\0'){
        if (st.isOperand(infix[i])){
            postfix[j++] = infix[i++];
        } else {
            if (st.isEmpty() || st.outPrecedence(infix[i]) > st.inPrecedence(st.stackTop())){
                st.push(infix[i++]);
            } else if ( st.outPrecedence(infix[i]) == st.inPrecedence(st.stackTop())){
                st.pop();
            }
            else {
                postfix[j++] = st.stackTop();
                st.pop();
            }
        }
    }

    while (! st.isEmpty() && st.stackTop() != ')'){
        postfix[j++] = st.stackTop();
        st.pop();
    }

    postfix[j] = '\0';

    return postfix;

}




int main()
{
    char A[] = "a+b*c-d/e";
    char *B = convert(A);
    cout<<B;

    return 0;
}

