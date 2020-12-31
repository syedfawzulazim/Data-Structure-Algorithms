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
    int largeE();
    void setH(Array *);


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

int Array::largeE(){
    int large = 0;
    for(int i = 0; i < len; i++){
        if(large < A[i]){
            large = A[i];
        }
    }
    return large;
}

void Array::setH(Array *arr){
    for(int i = 0; i < len; i++){
        arr->A[A[i]]++;
    }
}




void Array::duplicateFind(){
    for(int i = 0; i< len; i++){
        if(A[i] > 1){
            cout<<i <<" --> "<<A[i]<<endl;
        }
    }
}




int main() {

Array *arr1, *arr2;

int siz, large;
cin>>siz;

arr1 = new Array(siz);
arr1->createArray();
large = arr1->largeE();

arr2 = new Array(large+1);

arr1->setH(arr2);

arr2->duplicateFind();

//arr2->display();
return 0;
}

