#include<iostream>
using namespace std;

// Merging 2 List

void Merging(int A[], int B[], int C[], int m, int n){

    int i, j, k;
    i = j = k = 0;

    while( i<m || j<n){
        if(A[i] < B[j]){
            C[k++] = A[i++];
        }
        else{
            C[k++] = B[j++];
        }
    }
    while(i<m){
        C[k++] = A[i++];
    }
    while(j<n){
        C[j++] = B[j++];
    }
}

// Merging Single List with the help of another array

void MergingSingle(int A[], int l, int mid, int h){
int i = l;
int j = mid+1;
int k = l;

int B[h+1];

while(i <= mid && j <= h ){
    if(A[i] < A[j]){
        B[k++] = A[i++];
    }
    else{
        B[k++] = A[j++];
    }
}
while( i <= mid){
    B[k++] = A[i++];
}
while( j <= h){
    B[k++] = A[j++];
}

for(int i=l; i <=h; i++){
    A[i] = B[i];
}
}




int main(){
    int A[] = {2,10,18,20};
    int B[] = {4,9,14,19,22};

    int m = sizeof(A)/sizeof(A[0]);
    int n = sizeof(B)/sizeof(B[0]);

    int r = m+n;
    int C[r];

    Merging(A,B,C,m,n);

    for(int i=0; i < r; i++){
        cout<<C[i]<<" " ;
    }

    int D[] = {2, 5, 8, 12, 3, 6, 7, 10}; // this needs to sorted [2 to 12 & 3 to 10]
    int s = sizeof(D)/sizeof(D[0]);

    MergingSingle(D,0,3,7);

    cout<<endl;
      for(int i=0; i < s ; i++){
        cout<<D[i]<<" " ;
    }

return 0;
}
