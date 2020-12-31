#include<iostream>
#include<string.h>
using namespace std;

void perm(char s[], int l, int h){

    if(l==h){
        cout<<s<<endl;
    }

else{
    for(int i=l; i <= h; i++){
    swap(s[l], s[i]);
    perm(s, l+1, h);
    swap(s[l],s[i]);
        }
    }
}


int main(){
    char a[] = "ABC";
    int length;
    length = strlen(a)-1;
    perm(a, 0, length );

return 0;
}



