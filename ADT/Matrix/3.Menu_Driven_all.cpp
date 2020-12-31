#include<iostream>
#include<memory>
#include <vector>
using namespace std;

class Diagonal {
    private:
       vector<int> A;
       int n;
    public:
       Diagonal() : A(5) {};
       Diagonal(int n) : n(n), A(n) {};

        void Create() {
        cout<<"Enter the Elements : ";
        for(size_t i = 1; i <= A.size(); ++i) {
            cin >> A[i-1];
        }
    }
    void Set(size_t i, size_t j,  int x){
        if(i==j){
            A[i-1] = x;
        }
    }
    int Get(size_t i, size_t j) {
        if(i == j){
            return A[i-1];
        }
        return 0;
    }
    void display() {
        for (int i = 1; i <= A.size(); ++i) {
            for (int j = 1; j <= A.size(); ++j) {
                if (i == j) {
                    cout << A[i-1] << " ";
                } else {
                    cout<<"0 ";
                }
            }
            cout << endl;
        }
    }
};

void functionName(){
    cout<<endl;
    cout<<"----- Functions ------"<<endl;
    cout<<"1. Create "<<endl;
    cout<<"2. Get "<<endl;
    cout<<"3. Set "<<endl;
    cout<<"4. Display "<<endl;
    cout<<"5. Exit "<<endl;
    cout<<endl;
}


int main(){
    int ch;
     do{
            cout<<"------ Menu --------"<<endl;
            cout<<"1. Diagonal "<<endl;
            cout<<"2. Lower Tri-angular "<<endl;
            cout<<"3. Upper Tri-angular "<<endl;
            cout<<"4. Tri-diagonal"<<endl;
            cout<<"5. Toplitz"<<endl;
            cout<<"6. Exit"<<endl;
            cout<<endl;

            cin>>ch;
            int fun;
        do {
                auto d = make_unique<Diagonal>();
                switch (ch) {

            case 1:
                functionName();
                cin >> fun;
                switch (fun) {
                case 1:
                    cout << "Enter the size of matrix : ";
                    size_t n;
                    cin >> n;
                    d = make_unique<Diagonal>(n);
                    d->Create();
                    d->display();
                    break;
                case 2:
                    //get
                    //d->Get();
                    break;
                case 3:
                    //set
                    //d->Set();
                    break;
                case 4:
                    //display
                    d->display();
                    break;
                case 5:
                    break;
                }
                break;

                case 2: functionName();

                break;
                case 3: functionName();

                break;
                case 4: functionName();

                break;
                case 5: functionName();

                break;
            }

        }while(fun<4);

     }while(ch<=5);


return 0;
}

