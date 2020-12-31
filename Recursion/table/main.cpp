#include <iostream>

using namespace std;

int main()
{
   /* 2D array declaration*/
   int disp[2][10] = {{1,2,3,4,5,6,7,8,9,10}, {4,5,6,7,3,4,5,6,71,10}};
   /*Counter variables for the loop*/


int j;

      for(int a=0; a<10; a++){

      for(j=a;j<a+2;j++) {
         cout<<disp[0][j]<<" ";

      }
      a=a+1;
        cout<<endl;
      }


    return 0;
}
