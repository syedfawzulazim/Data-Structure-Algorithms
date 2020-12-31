#include<iostream>
using namespace std;

void bubble_sort(int A[], int n){

    for(int i=0; i<n-1; i++){

        for(int j=0; j<n-1-i; j++){
            if(A[j] > A[j+1]){
                int temp = A[j];
                A[j] = A[j+1];
                A[j+1] = temp;
            }
        }
//        if( i == 1){ // this is to find max number after 1 iteration
//                cout<<A[n-1]<<" ";
//                break;
//            }
    }
}

int main(){
    int A[] = { 8,5,7,3,2,20, 9, 11 };
    int n = (sizeof(A)/ sizeof(A[0]));

    bubble_sort(A, n);

    for(int i=0; i<n; i++){
        cout<<A[i]<<" ";
    }


return 0;
}
