#include<iostream>
#include<vector>
using namespace std;
class LowT{
private:
    vector<int> A;
    int n;
public:
    LowT(): A(2){};
    LowT(int n): n(n), A(n*(n+1)/2){};

    void display(){
    for(int i=1; i<=this->n; i++){
        for(int j=1; j<=this->n; j++){
            if(i >= j){
                cout<<A[(i*(i-1)/2) + j - 1]<<" ";
            }
            else{
              cout<<"0 ";
            }
        }
        cout<<endl;
    }
}

void Create() {
        cout<<"Enter the Elements : ";
        for(int i=1; i<=this->n; i++){
            for(int j=1; j<=this->n; j++){
                if(i >= j){
                    cin>>A[(i*(i-1)/2) + j - 1];
                }
            }
        }
    }

int Get(int i, int j){
        if(i >= j){
            return A[i*(i-1)/2+j-1];
        }
        else return 0;
    }

void change(int i, int j, int x){
    if(i>=j){
        A[i*(i-1)/2+j-1] = x;
    }
}




};
int main(){
//using pointer to an obj
//LowT *obj;
//obj = new LowT(5);
//obj->Create();
//obj->display();

LowT obj(3);
obj.Create();

cout<<endl;
obj.display();

cout<<endl;
cout<<obj.Get(3,3);

cout<<endl;
obj.change(3,3, 10);

cout<<endl;
obj.display();

cout<<endl;
cout<<obj.Get(3,3);

cout<<endl;

return 0;
}
