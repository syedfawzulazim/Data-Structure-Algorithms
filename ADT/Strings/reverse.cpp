#include<iostream>
using namespace std;


int main(){
    char  A[] = "Adnan";

//    char  B[4];
//    int i,j;
//    for(i=0; A[i] != '\0'; i++){
//    }
//    i = i-1;
//    for(j=0; i>=0; i--, j++){
//        B[j] = A[i];
//        }
//        B[j] = '\0';
//        cout<<B;




    int i,j;
    for(i=0; A[i] != '\0'; i++){
    }
    j = i -1;

    for(i =0; i<j; i++, j--)
        {
        int temp = A[i];
        A[i] = A[j];
        A[j]=temp;
    }
    cout<<A;





return 0;
}

