#include <iostream>
#include<iterator>

using namespace std;

int Bsearch ( int *arr, int l, int h,  int n){
int mid;
if(l<=h){
    mid = (l+h)/2;
    if(n == arr[mid]){
        return mid;
    }
    else if(n < arr[mid]){
        return Bsearch(arr, l, mid-1, n);
    }
    else
    {
        return Bsearch (arr, mid+1, h, n);
    }
}
return -1;
}

int main(){

    int a[] ={4,6,8,9,12,16,19,20,23,25,29,31,35};
    int s = sizeof(a)/sizeof(a[0]);
    int l = 0;
    int h = s-1;
    int mid=(l+h)/2;

    int n=12;

       //cout<<Bsearch(a, l, h, n); //recursion

 while(l <= h)
{
    if( a[mid] < n )
    {
        l = mid+1;
    }
    else if(a[mid] == n)
    {
      cout<<mid+1;
      break;
    }
    else
    {
            h = mid-1;
    }
    mid = (l+h)/2;
 }

 if(l>h){
    cout<<"Not Found";
 }

   return 0;
}
