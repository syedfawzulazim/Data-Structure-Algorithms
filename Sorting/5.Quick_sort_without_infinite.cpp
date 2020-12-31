#include<iostream>
#include<vector>
using namespace std;


void Swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

int Partition(vector<int>&A, int l, int h){
    int pivot = A[l];
    int i = l;
    int j = h;

    while( i < j){
        while( i < h && A[i] <= pivot ){
            i++;
        }
        while( A[j] > pivot){
            j--;
        }
        if(i < j){
            Swap(&A[i], &A[j]);
        }
    }

    Swap(&A[l], &A[j]);

    return j;
}


void QuickSort(vector<int>&A, int l, int h){
    int j;
    if(l<h){
        j = Partition(A, l, h);
        QuickSort(A, l, j-1);
        QuickSort(A, j+1, h);
    }
}




int main(){
    vector<int> A = {11,13,7,9,16,19,28,25,24};
    int n= A.size();

   QuickSort(A,0,n-1);



    for(int i=0; i<n; i++){
        cout<<A[i]<<" ";
    }

return 0;
}

