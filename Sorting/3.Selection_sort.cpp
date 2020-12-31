#include<iostream>
using namespace std;

void selection_sort(int A[], int n){
    int j,k;
    for(int i=0; i<n-1; i++){
        for( j = k = i; j<n; j++){
            if(A[j] < A[k]){
                k = j;
            }
        }
        int temp = A[i];
        A[i] = A[k];
        A[k] = temp;
    }

}

int main(){
    int A[] = { 8,5,7,3,2,20, 9, 11 ,21,29,8};
    int n = (sizeof(A)/ sizeof(A[0]));

    selection_sort(A, n);

    for(int i=0; i<n; i++){
        cout<<A[i]<<" ";
    }


return 0;
}


