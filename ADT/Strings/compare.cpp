#include<iostream>
using namespace std;

int main(){
char A[] = "Painter";
char B[] = "Painter";

int i =0, j =0;

for( i=0, j =0; A[i] !='\0' && B[j] != '\0'; i++, j++){
    if(A[i] != B[j]){
        break;
    }
}
    if(A[i] > B[i]) { cout<<"Larger"<<endl; }
    else if(A[i] < B[i]) { cout<<"Smaller"<<endl; }
    else { cout<<"Equal"<<endl;}

return 0;
}
