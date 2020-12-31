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
        siz =10;
        len=5;
        A = new int;
    }

    Array(int sz) {
    this->siz = sz;
    this->len = sz;
    A = new int[sz]{};
    }

    ~Array() {
    delete [] A;
    }

    void display(){
    for(int i = 0; i<len; i++){
            cout<<A[i]<<" ";
        }
    }

    void createArray(){
        for(int i = 0; i < len ; i++){
            cin>>A[i];
        }
    }

    int maxE(){
        int temp = 0;
    for(int i =0; i< len; i++){
        if(temp < A[i]){
            temp = A[i];
        }
    }
    return temp;
}

    void setH(Array *arr2){ ///received by pointer as address was passed;
    for(int i = 0; i<len; i++){ /// 3 6 8 2 9
        arr2->A[A[i]] = 1;      /// 0 0 0   0 0 0   0 0 0
        }
    }

    void MissE(){

    for( int i = 1; i < len; i++){
            if(A[i] == 0){
                  cout<<i<<" ";
            }
      }
    }


};

int main(){

Array *arr1, *arr2;

int siz, large;
cin>>siz;

arr1 = new Array(siz); ///[] make array of objs[multiple arrays of arr1] & () call the parameterized constructor
arr1->createArray();
large = arr1->maxE();

arr2 = new Array(large+1);

arr1->setH(arr2); ///passed by address as values going to change from 0 to 1;

arr1->display();
cout<<endl;
arr2->display();
cout<<endl;
arr2->MissE();

return 0;
}

