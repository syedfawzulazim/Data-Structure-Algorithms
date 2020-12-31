#include<iostream>
#include<algorithm>
using namespace std;

class P_Queue{
private:
    int Size;
    int f;
    int r;
    int *Q;
public:
    P_Queue(int Size)
    :Size(Size)
    {
        f = r = -1;
        Q = new int[this->Size];
    }
    ~P_Queue(){
        delete [] Q;
    }

    void push(int x){
        if( r == Size-1){
            cout<<"FULL";
        }
        else{
            r++;
            Q[r] = x;
        }
    }



    int pop(){
        int x=-1;;
        if( f == r){
            cout<<"Empty.";
        }
        else{
        x = Q[r];
        r--;
        }
    return x;
    }



    void diplay(){
        for(  int i=f+1; i<=r; i++){
            cout<<Q[i]<<" ";
        }
    cout<<endl;
    }


};



int main(){

    int A[] = {5, 3, 1, 5, 1,6,2,8,7,8};
    int s = sizeof(A)/sizeof(A[0]);

    sort(begin(A), end(A), greater<int>());

    P_Queue pq(s);

    for(int i=0; i<s; i++){
        pq.push(A[i]);
    }

    pq.diplay();
    cout<<endl;

    pq.pop();
    pq.pop();
    pq.pop();


    cout<<endl;
    pq.diplay();
    cout<<endl;



return 0;
}
