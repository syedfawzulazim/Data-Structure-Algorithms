#include<iostream>
using namespace std;

int main() {
cout<<"Stack memory"<<endl;

int n=7;
cout<<"Value of n :  "<<n<<" --> "<<&n<<endl;

int *p =&n;
cout<<"Value of p :  "<<*p<<" --> "<<p<<" --> "<<&p<<endl;

*p = 10;
cout<<"New value of n : "<<n<<endl;

cout<<endl;
cout<<"Pointer  Heap memory"<<endl;

int *num = new int;

cout<<"Value of num :  "<<*num<<" --> "<<num<<"--->"<<&num<<endl; ///*num = gurbaze value as not initialized

*num = 20;

cout<<"Value of num :  "<<*num<<" --> "<<num<<"--->"<<&num<<endl;
cout<<endl;

cout<<"More Memory"<<endl;

int x=2, y=5, z=8;
int *a=&x, *b=&y, *c=&z;

cout<<x<<" "<<y<<" "<<z<<" --> "<<*a<<" "<<*b<<" "<<*c<<endl;
z=x;
cout<<x<<" "<<y<<" "<<z<<" --> "<<*a<<" "<<*b<<" "<<*c<<endl;
a=b;
cout<<x<<" "<<y<<" "<<z<<" --> "<<*a<<" "<<*b<<" "<<*c<<endl;
*b=*c;
cout<<x<<" "<<y<<" "<<z<<" --> "<<*a<<" "<<*b<<" "<<*c<<endl;

cout<<endl;

cout<<"Pointer to Heap memory Referencing"<<endl;
int *s = new int;
int &f = *s; /// &f is a reference variable which means *s is now can be called AS 'f' (reference variable must be initialized when declared)
f=4;
///*s = *s+1;;
cout<<"Value of s :  "<<*s<<" --> "<<s<<"--->"<<&s<<endl;
cout<<"Value of f :  "<<f<<" --> "<<&f<<endl;

cout<<endl;

int *g = new int;
*g = 0;
//int &h = *g;
//int h = *g;
int h=8;
g =&h;
h++;
(*g)++; ///increments the value that its holding not the address it points to

cout<<g<<" "<<*g<<" "<<h<<" "<<&h<<endl;

*g++;/// increments the address to the next elements not the actual value the pointer holding

cout<<g<<" "<<*g<<" "<<h<<" "<<&h<<endl;


  return 0;
}
