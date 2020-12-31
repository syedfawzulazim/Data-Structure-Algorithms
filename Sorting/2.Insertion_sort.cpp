#include<iostream>
using namespace std;

void insertion_sort(int A[], int n){
    int j,x;
    for(int i=1; i<n; i++){
        j = i-1;
        x = A[i];

        while(j > -1 && A[j] > x){
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = x;
    }

}

int main(){
    int A[] = { 8,5,7,3,2,20, 8, 11 };
    int n = (sizeof(A)/ sizeof(A[0]));

    insertion_sort(A, n);

    for(int i=0; i<n; i++){
        cout<<A[i]<<" ";
    }


return 0;
}

