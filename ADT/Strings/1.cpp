#include<iostream>
#include<string>
#include<cstring>
using namespace std;

int main(){
    char a = 'A';  /// right(only one char)
    //char a = 'ABC';  /// wrong

    char b[4] = {65, 66, 67}; /// one is '\0' at the end
    cout<<b<<endl;
    cout<<*b<<endl;
    cout<<*(b+2)<<endl;

    cout<<endl;
    char c[4] = {'X','B','D'};
    cout<<c<<endl;

    cout<<endl;
    char d[] = "AccC";
    cout<<d<<endl;

   cout<<endl;
   string x = "Adnan is a good";
   cout<<x.size()<<endl;



   cout<<endl;
   strcpy(c, d);
   cout<<c<<endl;
   strcat(c,d);
   cout<<c;

    cout<<endl;
   char name1[ ]= "Samim";
  	char *p;
  	p = name1;     /// p holds the address of 'S' only so if we cout<<*P; it prints only 'S'

   // p[0] = 'A';   /// same as *(p + 0)
  //  cout<<*p<<p;

  	while( *p != '\0')
  	{
    	cout << *p; ///prints what is in P(dereference)
    	p++; /// increments P to next address of char array
  	}

    cout<<endl;
    char *name;
    name = new char;
    gets(name); ///takes the full line as input
    cout<<name<<endl;
    cout<<strlen(name)<<endl;


return 0;
}
