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
    void Pair();
    void PairHash(Array *);
    int largeE();



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


void Array::Pair(){

    for(int i = 0; i< len-1; i++){
        for(int j = i+1; j < len; j++){
            if(A[i] + A[j] == 10){
                cout<<A[i] << "--> " << A[j]<< " = " <<10<<endl;
            }
        }
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

void Array::PairHash(Array *arr){
    for(int i= 0; i < len; i++){
    if(arr->A[10 - A[i]] != 0 && 10 - A[i] >=0 ){
        cout<<A[i]<<" --> " << 10 - A[i]<< " = "<<10<<endl;
        }
        arr->A[A[i]]++;
    }
}



int main() {

Array *arr1, *arr2;

int siz, large;
cin>>siz;

arr1 = new Array(siz);
arr1->createArray();
large = arr1->largeE();

arr2 = new Array (large + 1);
//arr1->Pair();
arr1->PairHash(arr2);


//arr2->display();
return 0;
}


