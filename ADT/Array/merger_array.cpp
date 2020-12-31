#include<iostream>
using namespace std;

struct Array {
 int A[12];
 int siz;
 int len;
};

void display(struct Array arr){
int i;
for(int i=0; i<arr.len; i++){
    cout<<arr.A[i]<<" ";
    }
}

struct Array *Merge(struct Array arr1, struct Array arr2){
    int i,j,k;
    i=j=k=0;

    Array *arr3 =  new  Array;

    while (i < arr1.len && j<arr2.len){
        if(arr1.A[i] < arr2.A[j]){
            arr3->A[k]=arr1.A[i];
            k++; i++;
        }
        else {
            arr3->A[k++] = arr2.A[j++];
           /// k++; j++;
        }
    }
    for( ; i<arr1.len; i++){
        arr3->A[k] = arr1.A[i];
        k++;
    }
    for( ; j<arr2.len; j++){
        arr3->A[k++] = arr2.A[j];
       /// k++;
    }
    arr3->len = arr1.len + arr2.len;
    arr3->siz =12;

return arr3; ///as it is made in heap we can return its address(so we need pointer type return type->above)
}

int main()
{
    struct Array arr1 = {{2,4,6,7,11,16},12, 6};
    struct Array arr2 = {{3,5,8,9,10,13},12, 6};
    struct Array *arr3;

    arr3 = Merge(arr1, arr2); /// don't need to modify so also can pass it by value
    display(*arr3);///passed by value

    return 0;
}
