#include<iostream>
#include<algorithm>
#include<stack>
using namespace std;

class P_Queue{
private:
    stack<int> s1;
    stack<int> s2;
public:
    P_Queue(){
    }
    ~P_Queue(){
    }

    void enqueue(int x){
        s1.push(x);
    }



    int dequeue(){
        int x=-1;
        if(s2.empty()){
                if(s1.empty()){
                    cout << "Queue Underflow" << endl;
                    return x;
                }
                else{
                    while(!s1.empty()){
                        s2.push(s1.top());
                        s1.pop();
                    }
                }
            }
        x = s2.top();
        s2.pop();
        return x;
    }



    void diplay(){
        stack<int> temp = s2;
            while(!temp.empty()){
                cout<<temp.top()<<" ";
                temp.pop();
            }
            cout<<endl;
    }

    friend main();
};



int main(){

    int A[] = {1, 3, 5, 7, 9};
    int s = sizeof(A)/sizeof(A[0]);


    P_Queue pq;

    for (int i=0; i<s; i++){
        pq.enqueue(A[i]);
    }
    cout << endl;


     for (int i=0; i<s; i++){
        cout << pq.dequeue()<<" ";
    }

    //works only for s1 and when dequeue is not called.
    cout<<endl;
    pq.diplay();
    cout<<endl;



return 0;
}

