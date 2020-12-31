#include<iostream>
using namespace std;

int main(){

int arr[] = {2,3,5,7,8, 4, 12,10, 18,11,16};
int s = sizeof(arr)/sizeof(arr[0]);
int n = 12;
for(int i=0; i<s; i++){
    if(n==arr[i]){
        swap(arr[i], arr[i-1]);
        cout<<i<<endl;
    }
}
// after swap
for(auto &e : arr){
        cout<< e << " ";
}
return 0;
}
