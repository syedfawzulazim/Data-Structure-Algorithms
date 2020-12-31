#include<iostream>
#include<string.h>
using namespace std;

int main(){
        // a = 5(00000101), b = 9(00001001)
    unsigned char a = 5, b = 9;

    // The result is 00000001
    printf("a = %d, b = %d\n", a, b);
    printf("a&b = %d\n", a & b);

    // The result is 00001101
    printf("a|b = %d\n", a | b);

    // The result is 00001100
    printf("a^b = %d\n", a ^ b);

    // The result is 11111010
    printf("~a = %d\n", a = ~a);

    // The result is 00010010
    printf("b<<1 = %d\n", b << 1);

    // The result is 00000100
    printf("b>>1 = %d\n", b >> 1);


    char c[] = "finding";
    long int h =0, x=0;

    cout<<endl<<"Duplicate : ";
    for(int i=0; c[i] !='\0'; i++){
        x=1;
        x = x << (c[i] - 97);
        if((x & h) >0){
            cout<<c[i]<<"  ";
        }
        else{
            h= h | x;
        }
    }

return 0;
}

