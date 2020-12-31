#include<iostream>
using namespace std;


void Swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

int Partition(int A[], int l, int h){
    int pivot = A[l];
    int i = l;
    int j = h;

    do{
        do{i++;}while(A[i]<=pivot);
        do{j--;}while(A[j]>pivot);
        if(i < j){
            Swap(&A[i], &A[j]);
        }
    }while(i<j);

    Swap(&A[l], &A[j]);

    return j;
}


void QuickSort(int A[], int l, int h){
    int j;
    if(l<h){
        j = Partition(A, l, h);
        QuickSort(A, l, j);
        QuickSort(A, j+1, h);
    }
}




int main(){
    int A[] = {11,13,7,9,16,19,28,25,24, INT_MAX};
    int n= sizeof(A)/sizeof(A[0]);

    QuickSort(A,0,n-1);

    for(int i=0; i<n-1; i++){
        cout<<A[i]<<" ";
    }

return 0;
}
