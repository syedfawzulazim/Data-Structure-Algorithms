#include<iostream>
using namespace std;

struct Array {
 int A[10];
 int siz;
 int len;
};

void display(struct Array arr){
int i;
for(int i=0; i<arr.len; i++){
    cout<<arr.A[i]<<" ";
    }
}

void Swap (int *x, int *y){
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void Append (struct Array *arr, int x){
    if(arr->len <  arr->siz){
            arr->A[arr->len++]=x;
            }
}

void Insert( struct Array *arr, int index, int x ){
 int i;
 if(index>=0 && index<=arr->len){
    for(i=arr->len; i>index; i--){
        arr->A[i]=arr->A[i-1];
    }
    arr->A[index]=x;
    arr->len++;
 }
}

int Delete (struct Array *arr, int index){
    int x=0;
    if(index >= 0 && index < arr->len){
        x = arr->A[index];
        for(int i=index; i < arr->len-1; i++){
            arr->A[i] = arr->A[i+1];
        }
        arr->len--;
        return x;
    }
}

int get (struct Array arr, int index){ ///passed by value (when no change needed in array)
    if(index >0 && index < arr.len ){
        return arr.A[index];
    }
else
    return -1;
}

void Set (struct Array *arr, int index, int n){ ///passed by address (when changes needed)
    if(index>0 && index < arr->len){
        arr->A[index] = n;
    }
}

int Max (struct Array arr){
    int mx = arr.A[0];
    for(int i=1; i< arr.len; i++){
        if(arr.A[i] > mx){
            mx = arr.A[i];
        }
    }
    return mx;
}

int Min (struct Array arr){
    int mn = arr.A[0];
    for(int i=1; i< arr.len; i++){
        if(arr.A[i] < mn){
            mn = arr.A[i];
        }
    }
    return mn;
}

int sum (struct Array arr){
    int s=0;
    for(int i =0; i<arr.len; i++){
        s=s+arr.A[i];
    }
    return s;
}

float Avg (struct Array arr){
    return (float) sum(arr)/arr.len;
}

void Reverse (struct Array *arr){
    int *B;
    B = new int[arr->len];

    for( int i = arr->len-1, j=0; i>=0; i--, j++){
        B[j] = arr->A[i];
    }
    for(int i = 0; i < arr->len; i++){
        arr->A[i] = B[i];
    }
}

void Reverse1(struct Array *arr){
    int i, j;
    for( i = 0, j=arr->len-1; i<j; i++, j--){
        Swap(&arr->A[i], &arr->A[j]);
    }
}

void Lshift (struct Array *arr){
    int temp = arr->A[0];
for(int i= 0; i<arr->len; i++){
    arr->A[i] = arr->A[i+1];
    }
    ///arr->A[arr->len-1] = temp; // rotate add 1st element in the last index after shifting
}


int main(){
    struct Array arr={{1,2,3,4,6},10,5};
    ///when need to modify array, it is passed by address otherwise by value
   // Append(&arr,10);
    //Insert(&arr, 2, 15);
    //cout<<"Delete Item is: "<<Delete(&arr, 2)<<endl;
    //cout<<get(arr,3)<<endl;
    //Set(&arr, 3, 20);
    //cout<<Max(arr)<<endl;
    //cout<<sum(arr)<<endl;
    //cout<<Avg(arr)<<endl;
    //Reverse1(&arr);
    Lshift(&arr);

    display(arr);
}
