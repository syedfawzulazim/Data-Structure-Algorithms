#include <iostream>

using namespace std;

void TOH(int n, int a, int b, int c)
{

    if(n>0){

        TOH (n-1, a, c, b);
        cout<<a<<","<<c<<endl;
        TOH (n-1, b, a, c);

    }
}

int fun (int n)

{
    int x=1, k;
  if (n==1) {
    return x;
  }



    for ( k=1; k<n; ++k )
{

   x= x + (fun( k )) * fun(n — k);
}
return x;
}

int main()
{
    TOH(3, 1, 2, 3) ;
    cout<<fun(5);
    return 0;
}


