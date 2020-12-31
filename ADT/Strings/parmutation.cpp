#include<iostream>
#include<string.h>
using namespace std;

void perm(char s[], int k){
    static int a[10] = {0};
    static char r[10];
    int i;
    if(s[k] == '\0'){
    r[k] = '\0';
    cout<<r<<endl;
    }
    else{
    for(i =0; s[i] != '\0'; i++){
        if(a[i] == 0){

            r[k] = s[i];
            a[i] =1;
            perm(s, k+1);
            a[i] =0;

            }
        }
    }

}

int main(){
char s[] = "ABC";
perm(s, 0);

return 0;
}


