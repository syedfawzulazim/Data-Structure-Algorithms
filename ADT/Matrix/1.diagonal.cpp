#include<iostream>
using namespace std;

class diagonal {
    private:
        int *A;
        int n;
    public:
        diagonal(){
            n=2;
            A = new int[n];
        }
        diagonal(int n){
            this->n = n;
            A = new  int[n];
        }
        void Set(int i, int j,  int x){
            if(i==j){
                A[i-1] = x;
            }
        }
        int Get(int i, int j){
        if(i == j){
            return A[i-1];
            }
        else{
            return 0;
            }
        }

        void display(){
            for(int i=1; i<n; i++){
                for(int j=1; j<n; j++){
                    if(i==j){
                        cout<<A[i-1]<<" ";
                    }
                    else{
                        cout<<"0 ";
                    }
                }
                cout<<endl;
            }
        }
    ~diagonal(){
    delete []A;
    }
};


int main(){
    diagonal arr(5);

    arr.Set(1,1,3);
    arr.Set(2,2,5);
    arr.Set(3,3,7);
    arr.Set(4,4,9);

    cout<<arr.Get(3,3)<<endl;

    arr.display();

return 0;
}
