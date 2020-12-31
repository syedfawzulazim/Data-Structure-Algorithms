#include <iostream>

using namespace std;

 void fun (int x)
 {
     if(x>0){
        cout<<" "<<x;
        fun (x-1);
     }
 }

int main()
{
    int n=3;
    fun(n);
    return 0;
}
