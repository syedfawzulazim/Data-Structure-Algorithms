#include<iostream>
using namespace std;

// Merging Single List with the help of another array

void Merge(int A[], int l, int mid, int h){
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

void MergeSort(int A[], int n){
int p, i, l, mid, h;

for( p=2; p<=n; p = p*2 ){
    for(i=0; i+p-1<n; i=i+p){
        l=i;
        h=i+p-1;
        mid=(l+h)/2;
        Merge(A,l,mid,h);
    }
}
if(p/2 <n){ // for odd number of elements
    Merge(A,0, p/2-1, n-1);
}
}

int main(){
int A[ ] = {8,3,7,10,4,9,2,6,5,1};
int n = sizeof(A)/sizeof(A[0]);

MergeSort(A, n);

for(int i=0; i < n ; i++){
        cout<<A[i]<<" " ;
    }


return 0;
}
