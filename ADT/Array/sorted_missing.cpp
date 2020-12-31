#include<iostream>
#include<vector>
using namespace std;

class Array {
private:
    int *A;
    int siz;
    int len;
public:
    Array(){
        siz =1;
        len=0;
        A = new int;
    }

    Array(int sz) {
    this->siz = sz;
    this->len = 0;
    A = new int;
    }

    ~Array() {
    delete [] A;
    }

    void display(){
    for(int i = 0; i<siz; i++){
            cout<<A[i]<<" ";
        }
    }

    void createArray(){
        int n;
        cin>>n;
        this->siz = n;
        for(int i = 0; i < n; i++){
            cin>>A[i];
        }
    }

    void mse(){
        int diff;
        diff = A[0] - 0;
        for(int i = 0; i<siz; i++){
            if(A[i]-i != diff){
                    while(diff < A[i] - i){
                        cout<<i+diff<<" ";
                        diff++;
                    }
            }
        }
    }
};

int main(){

Array *arr1, *arr2;

arr1 = new Array;
arr1->createArray();
arr1->mse();

//arr2->display();

return 0;
}
