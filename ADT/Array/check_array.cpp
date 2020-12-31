#include<iostream>
using namespace std;

struct Array {
int A[10];
int siz;
int len;
};

void Insert (struct Array *arr, int n){
    int x =n;
    int i = arr->len-1;
    if(arr->len == arr->siz){
        return;
    }
    while( i >= 0 && arr->A[i] > x ){
        arr->A[i+1] = arr->A[i];
        i--;
    }
   arr->A[i+1] = x;
   arr->len++;
}

void display(struct Array arr){
for(int i =0; i < arr.len; i++){
    cout<<arr.A[i]<<" ";
    }
}

bool isSorted (struct Array arr){
for(int i =0; i<arr.len-1; i++){
    if(arr.A[i] > arr.A[i+1]){
        return false;
    }
 }
return true;
}

void Swap (int *x, int *y){
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void rearrange (struct Array *arr){
    int i =0;
    int j = arr->len-1;
    while(i < j){
        while(arr->A[i]<0){i++;} ///grabs positive numbers otherwise move to next
        while(arr->A[j]>=0){j--;} ///grabs negative numbers otherwise move to previous
        if(i<j){
            Swap(&arr->A[i], &arr->A[j]);
        }
    }
}

int main()
{
//    struct Array arr ={{2,4,5,17,18,20}, 10, 6};
//    Insert(&arr, 7);
//    Insert(&arr, 12);
//    cout<<isSorted(arr)<<endl;
        struct Array arr ={{2,-4,5,-17,18,-20}, 10, 6};
        rearrange(&arr);
        display(arr);

    return 0;
}
