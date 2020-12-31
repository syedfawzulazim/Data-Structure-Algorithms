#include<iostream>
#include<string.h>
using namespace std;

int main(){
   char a[] ="medical";
   char b[] = "decimal";
   int i, h[26] ={0};

   if(strlen(a) != strlen(b)){
    cout<<"Not equal";
   }

   else{
   for(i = 0; a[i] != '\0'; i++){
    h[a[i]-97]+=1;
   }

   for(i = 0; b[i] != '\0'; i++){
    h[b[i]-97] -=1;
    if(h[b[i] -97] < 0 ){
        cout<<"Not Anagram!!!";
        break;
    }
   }
   if(b[i] == '\0'){
    cout<<"Anagram!!!";
   }
}

return 0;
}


