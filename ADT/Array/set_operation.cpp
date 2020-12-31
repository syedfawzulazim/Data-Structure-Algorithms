#include<iostream>
using namespace std;


class Array {
private:
    int *A;
    int siz;
    int len;
public:
    Array(){
        siz =10;
        len=0;
        A = new int[siz];
    }
    Array(int siz){
        this->siz = siz;
        this->len = 0;
        A = new int[this->siz];
    }
    ~Array(){
        delete []A;
    }

    void createArray();
    void display();

    Array *Merge(Array arr);
    Array *Union(Array arr);
    Array *Interception(Array arr);
    Array *Diff(Array arr);
};

void Array::createArray(){
    int ln;
    cin>>ln;
    this->len = ln;
for(int i =0; i<ln; i++){
    cin>>A[i];
    }
}

Array * Array::Merge(Array arr){
    Array *arr3 = new Array[len + arr.len];
    int i,j,k;
    i = j = k = 0;

    while ( i < len && j < arr.len){
        if(A[i] < arr.A[j]){
            arr3->A[k] = A[i];
            k++;
            i++;
        }
        else{
            arr3->A[k] = arr.A[j];
            k++;
            j++;
        }
    }

    for( ; i<len; i++){
        arr3->A[k] = A[i];
        k++;
    }
    for( ; j<arr.len; j++){
        arr3->A[k] = arr.A[j];
        k++;
    }
    arr3->len = len +arr.len;
    return arr3;
}


Array * Array::Union(Array arr){
    Array *arr3 = new Array[len + arr.len];
    int i,j,k;
    i = j = k = 0;

    while ( i < len && j < arr.len){
        if(A[i] < arr.A[j]){
            arr3->A[k] = A[i];
            k++;
            i++;
        }
        else if(arr.A[j] < A[i]){
            arr3->A[k] = arr.A[j];
            k++;
            j++;
        }
        else {
            arr3->A[k]=A[i];
            i++;
            j++;
            k++;
        }
    }

    for( ; i<len; i++){
        arr3->A[k] = A[i];
        k++;
    }
    for( ; j<arr.len; j++){
        arr3->A[k] = arr.A[j];
        k++;
    }
    arr3->len = k;
    return arr3;
}


Array * Array::Interception(Array arr){
    Array *arr3 = new Array[len + arr.len];
    int i,j,k;
    i = j = k = 0;

    while ( i < len && j < arr.len){
        if(A[i] < arr.A[j]){
            i++;
        }
        else if(arr.A[j] < A[i]){
            j++;
        }
        else {
            arr3->A[k]=A[i];
            i++;
            j++;
            k++;
        }
    }

    arr3->len = k;
    return arr3;
}

Array * Array::Diff(Array arr){
    Array *arr3 = new Array[len + arr.len];
    int i,j,k;
    i = j = k = 0;

    while ( i < len && j < arr.len){ /// 1 5 9 11
        if(A[i] < arr.A[j]){                ///   5 8 9 12
            arr3->A[k] = A[i];
            k++;
            i++;
        }
        else if(A[i] > arr.A[j]){
            arr3->A[k] = arr.A[i];
            k++;
            i++;
        }
        else {
            i++;
            j++;
        }
    }

    for( ; i<len; i++){
        arr3->A[k] = A[i];
        k++;
    }

    arr3->len = k;
    return arr3;
}




void Array::display(){
    for(int i = 0; i<len; i++){
       cout<<A[i]<<" ";
    }
}

int main(){

    Array *arr1, *arr2, *arr3;
    int sz,ch;
    cout<<"Enter Array Size : "<<endl;
    cin>>sz;
    cout<<"Enter Array_1 [ <"<<sz <<" ] Length : "<<endl;
    arr1 = new Array[sz];
    arr1->createArray();

    cout<<"Enter Array_2 [ <"<<sz <<" ] Length : "<<endl;
    arr2 = new Array[sz];
    arr2->createArray();


    do{
        cout<<"\n\nMenu\n";
        cout<<"1. Merge\n";
        cout<<"2. Union\n";
        cout<<"3. Interception\n";
        cout<<"4. Difference\n";
        cout<<"5. Display\n";
        cout<<"6.Exit\n";

        cout<<endl<<"Enter Your Choice : "<<endl;
        cin>>ch;

        switch(ch){

        case 1: arr3= arr1->Merge(*arr2); ///passed bay value as not modifying
                    break;
        case 2: arr3= arr1->Union(*arr2);
                    break;
        case 3: arr3= arr1->Interception(*arr2);
                    break;
        case 4:  arr3= arr1->Diff(*arr2);
                    break;
        case 5: arr3->display();

        }
    }while(ch<6);




return 0;
}
