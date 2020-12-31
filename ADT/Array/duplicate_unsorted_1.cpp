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
    cout<<endl;
}

void Array::createArray(){
 for(int i =0; i < len; i++){
        cin>>A[i];
    }
}

void Array::duplicateFind(){

    for(int i = 0; i< len -1; i++){
        int c = 1;
        if(A[i] != -1){
            for(int j = i+1; j < len; j++){
                if(A[i] == A[j]){
                    c++;
                    A[j] = -1;
                }
            }
        }
        if(c>1){
                cout<<A[i]<<"-->"<<c<<endl;
        }
    }
}




int main() {

Array *arr1, *arr2;

int siz, large;
cin>>siz;

arr1 = new Array(siz);
arr1->createArray();
arr1->duplicateFind();


return 0;
}


