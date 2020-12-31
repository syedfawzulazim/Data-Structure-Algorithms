#include<iostream>
using namespace std;

void CountSort(int A[], int n, int h){

int B[h+1];

for(int i=0; i<h+1; i++){
    B[i] =0;
}

for(int i=0; i<n; i++){
    B[A[i]]++;
}

int i=0; int j =0;

while( i < h+1){
    if(B[i] > 0){
        A[j++] = i;
        B[i]--;
    }
    else{
        i++;
    }
}
}

int main(){
    int A[] ={3,4,4,6,7,8,1,4,5,9};
    int n =  sizeof(A)/sizeof(A[0]);

    CountSort(A,n,9);

    for(int i=0; i < n ; i++){
        cout<<A[i]<<" " ;
    }


return 0;
}
