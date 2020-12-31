#include<iostream>
#include<string.h>
using namespace std;

int main(){
    char a[] ="findings";
    int h[26] = {0};

    for(int i=0; a[i] != '\0'; i++){
        h[a[i]-97]++;
    }
    for(int j=0; j<26; j++){
        if(h[j] > 1){
            cout<<(char)(j+97)<<" " <<h[j]<<endl;
        }
    }

return 0;
}

