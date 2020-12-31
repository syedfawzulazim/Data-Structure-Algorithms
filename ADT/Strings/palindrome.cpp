#include<iostream>
#include<string.h>
using namespace std;

int main(){
    char A[] ="madam";


//    char B[7];
//    int i,j;
//    for(i =0; A[i] != '\0'; i++){
//    }
//    i = i-1;
//    for(j =0; i>=0; i--, j++){
//        B[j] = A[i];
//    }
//    B[j] ='\0';
//    cout<<A<<endl;
//    cout<<B<<endl;
//
//    for(i=0, j=0; A[i] !='\0' && B[i] != '\0'; i++, j++){
//        if(A[i] != B[j]){
//            cout<<"Not Palindrome!!!";
//            break;
//        }
//    }
//if(A[i] == B[j]){
//        cout<<"Palindrome!!!";
//}

int length, flag = 0;
length = strlen(A);

for(int i = 0; i <length; i++){
    if(A[i] != A[length - i - 1]){
        flag = 1;
        break;
    }
}

if(flag){
    cout<<"Not Palindrome!!!";
}
else{
    cout<<"Palindrome!!!";
}







return 0;
}
