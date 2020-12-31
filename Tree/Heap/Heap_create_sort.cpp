#include<iostream>
using namespace std;

void Insert(int A[], int n){
    int i =n, temp;
    temp = A[i];

    while(i > 0 && temp > A[(i-1)/2]){
        A[i] = A[(i-1)/2];
        i = (i-1)/2;
    }
    A[i] = temp;
}

int Delete(int A [], int n){
    int i, j, temp, x;

    x = A[0];
    A[0] = A[n];
    i=0; j =2*i;

    while(j < n){

        if(A[j+1] > A[j]){
            j = j+1;
        }
        if(A[i] < A[j]){
            temp = A[j];
            A[j] = A[i];
            A[i] = temp;

            i = j;
            j = 2*j;
        }
        else{
            break;
        }
    }
    A[n] = x;
}

int main(){
    int A[] = {10,20,30,25,5,40,35,50}; //8

    for(int i=0; i < 8; i++){
        Insert(A, i);
    }
//50 40 35 25 5 20 30 10

    for(int i = 7; i >= 0; i-- ){  // heap sort  by deleting
            Delete(A, i);
        }



    for(int i =0; i<8; i++){
        cout<<A[i]<<" ";
    }

return 0;
}
