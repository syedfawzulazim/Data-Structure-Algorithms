#include<iostream>
using namespace std;

void Shellsort(int A[], int n){
    int gap, i, j,temp;

    for(gap =n/2; gap>=1; gap/=2){

        for(i=gap; i<n; i++){

            j = i-gap;
            temp = A[i];

        while(j >= 0 && A[j] > temp){
            A[j+gap] = A[j];
            j = j -gap;
        }
        A[j+gap] = temp;
    }
  }
}

int main(){
    int A[] = { 8,5,7,3,2,20, 8, 11 };
    int n = (sizeof(A)/ sizeof(A[0]));

    Shellsort(A, n);

    for(int i=0; i<n; i++){
        cout<<A[i]<<" ";
    }


return 0;
}

