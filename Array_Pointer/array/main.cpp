#include <iostream>

using namespace std;

 class Array{
    private:
        int *A;
        int n, x;
    public:

        void input( ){
            int n;
            cin>>n;
            this->n = n;
        }

        void makeArray( ){

          this->A=new int[n];
        }

        void setArray(int x){
        this->x = x;
        for(int i=0; i<x; i++){
        cin>>A[i];
            }
        }

        void display(){

         for(int i=0; i<x; i++){
         cout<<A[i];
            }
        }
 };

int main()
{
    Array arr;
    arr.input();

    arr.makeArray();

    int x;
    cin>>x;
    arr.setArray(x);

    arr.display();

    return 0;
}
