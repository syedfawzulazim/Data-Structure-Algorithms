#include<iostream>
#include <stdio.h>
using namespace std;

int valid (char *c){

for(int i=0; c[i] != '\0'; i++){
    if( !(c[i] >=65 && c[i] <= 90) && !(c[i] >=90 && c[i] <= 122) && !( c[i] >= 48 && c[i] <=57 ) ){
        return 0;
    }
    }
   return 1;  // 1 for valid
}

int main(){

    for (int i =0; i <256; i++){
        cout<< i <<" --> "<<(char)i<<endl;
    }






    char *uname = "Adnan8888Khan";
    if(valid(uname)){
        cout<<"Valid";
    }
    else{
        cout<<"Invalid";
    }
return 0;
}
