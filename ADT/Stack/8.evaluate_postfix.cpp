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
        if(x == '+' || x == '-' || x == '*' || x == '/'){
            return 0;
        }
        return 1;
    }

    int precedence(char x){
        if(x == '+' || x == '-'){
            return 1;
        }
        else if( x == '*' || x == '/'){
            return 2;
        }
        return 0;
    }

    friend char * convert(char *);

};


char * convert( char *infix){

    int m = strlen(infix);

    Stack st(m);

    char *postfix = new char[st.size+1];

    int i=0, j=0;


    while( infix[i] != '\0')
        {

        if(st.isOperand(infix[i]))
        {
            postfix[j++] = infix[i++];
        }

        else
        {
            if( st.precedence(infix[i]) > st.precedence(st.stackTop()) )
            {
                st.push(infix[i++]);
            }
            else
            {
                postfix[j++] = st.pop();
            }
        }

    }

    while(!st.isEmpty()){   //pop out other left elements to postfix
        postfix[j++] = st.pop();
    }
    postfix[j] = '\0'; // make last null

        return postfix;
}


int evaluate(char *postfix){

    int m = strlen(postfix);

    Stack st(m);

    int x1,  x2, r;

    for(int i=0; postfix[i] !='\0'; i++){
        if(st.isOperand(postfix[i])){
            st.push(postfix[i] - '0');
        }
        else
        {
            x2 = st.pop(); x1 = st.pop();

            switch(postfix[i])
            {
                case '+': r = x1 + x2; break;
                case '-' : r  = x1 - x2; break;
                case '*' : r = x1 * x2; break;
                case '/' : r = x1 / x2; break;
            }
            st.push(r);
        }
    }

    return int(st.pop()); // or can change all types of return types from char to int
}




int main()
{
    char A[] = "6+5+3*4";
    char *B = convert(A);
    cout<<B<<endl;
    cout<<evaluate(B);

    return 0;
}

