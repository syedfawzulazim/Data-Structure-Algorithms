#include<iostream>
using namespace std;

int main(){

    //length
    char *name = "Adnan";
    int i;
    for(i =0; name[i] != '\0'; i++){}
    cout<<i<<endl;

    cout<<endl;
    //change case toggle

    char s[] ="ADNAN";

    for(int i = 0; s[i] != '\0'; i++){
        if(s[i] >= 65 && s[i] <=90){
            s[i] += 32;
        }
        else if(s[i] >=97 && s[i]<=122){
            s[i]-= 32;
        }
    }
    cout<<s;

    cout<<endl;
    //count words and vowel

    char s1[] = "how are you";
    int vCount = 0 , cCount = 0, word =0;
    for(int i=0; s1[i] != '\0'; i++){
        if(s1[i] == 'a' || s1[i] == 'e' || s1[i] == 'i' || s1[i] == 'o' || s1[i] == 'u' ){
            vCount++;
        }
        else if((s1[i] >= 65 && s[i] <=90) || (s1[i] >= 97 && s[i] <=122)){
            cCount++;
        }
    }
    cout<<vCount<<"  "<<vCount<<endl;

    for(int i=0; s1[i] !='\0'; i++){
        if(s1[i] == ' '  && s1[i-1] != ' '){
            word++;
        }
    }
    cout<<word+1<<endl;




return 0;
}
