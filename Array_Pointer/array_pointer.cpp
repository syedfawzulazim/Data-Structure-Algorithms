// more pointers
#include <iostream>
using namespace std;

int main ()
{
  int numbers[5];

  cout<<numbers[2]<<endl;
  cout<<&numbers<<endl;

  int * p;

  p = numbers;  *p = 10;
  cout<<p<<endl;

  p++;  *p = 20;

  cout<<p<<endl;

  p = &numbers[2];  *p = 30;

  cout<<p<<endl;

  p = numbers + 3;  *p = 40;

  p = numbers;  *(p+4) = 50;

  for (int n=0; n<5; n++)
    cout << numbers[n] << ", ";

    cout<<endl;
    cout<<* (numbers+2)<<endl; /// though numbers is not a pointer, it means (*, points to) numbers+5 th element;

  return 0;
}
