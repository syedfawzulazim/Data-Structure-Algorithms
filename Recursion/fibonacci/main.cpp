#include <iostream>

using namespace std;
//recursion
int fib (int n){
    if(n<=1){
        return n;
    }
    else {
        return fib(n-2)+fib(n-1);
    }
}
//loop
int Lfib (int n){
    int i, s=0, t0=0,t1=1;
    if(n<=1) {
        return n;
    }
    else {
        for(i=2;i<=n;i++){
            s= t0+t1;
            t0=t1;
            t1=s;
        }
        return s;
    }
}
//recursion with memorization
int f[10];

int rfib (int n){

    if (n<=1){
        f[n] = n;
        return n;
    }
    else{
        if( f[n-2] == -1){
            f[n-2]= rfib (n-2);
        }
        if( f[n-1] == -1){
            f[n-1] = rfib (n-1);
        }
        f[n]=f[n-2]+f[n-1];
        return f[n-2]+f[n-1];
    }


}

int main()
{
    for(int i=0;i<=10;i++){
        f[i]=-1;
    }
    cout << rfib(10);
    return 0;
}
