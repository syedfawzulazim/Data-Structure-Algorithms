#include<iostream>
using namespace std;
class Array {
private:
    int *A;
    int siz;
    int len;
public:
    Array(){
    siz = 10;
    len =0;
    A = new int;
    }

    Array(int sz){
    this->siz = sz;
    this->len =sz;
    A = new int[sz]{};
    }
    ~Array(){
        delete [] A;
    }

    void display();
    void createArray();
    void duplicateFind();
    void duplicateCount();

};

void Array::display(){
    for(int i =0; i < len; i++){
        cout<<A[i]<<" ";
    }
}

void Array::createArray(){
 for(int i =0; i < len; i++){
        cin>>A[i];
    }
}

void Array::duplicateFind(){
    int lastD = 0;
    for(int i = 0; i < len; i++ ){
        if(A[i] == A[i+1] && A[i] != lastD){
            cout<<A[i]<<" ";
            lastD = A[i];
        }
        cout<<endl;
    }
}

void Array::duplicateCount(){
        for( int i =0; i < len; i++ ){
        if(A[i] == A[i+1]){
            int j = i+1;
            while( A[j] == A[i]) j++;
            cout<<A[i]<<endl;
            cout<<j - i<<endl;;
            i = j -1;
        }
    }
}


int main() {

Array *arr1, *arr2;

int siz;
cin>>siz;

arr1 = new Array(siz);
arr1->createArray();
arr1->duplicateFind();
arr1->duplicateCount();

//arr1->display();
return 0;
}
