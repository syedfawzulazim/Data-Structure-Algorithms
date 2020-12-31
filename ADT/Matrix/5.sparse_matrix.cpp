#include<iostream>
using namespace std;

class element{
public:
    int i;
    int j;
    int x;
};

class sparse {
private:
    int m;
    int n;
    int num;
   element *e;
public:
    sparse(int m, int n, int num)
    :m(m), n(n), num(num)
   {
        e = new element[this->num];
    }
    ~sparse()
    {
        delete [] e;
    }

    void create(){
        cout<<"Enter All non-zero  Elements : "<<endl;
        for(int i=0; i<num; i++){
            cin>>e[i].i>>e[i].j>>e[i].x;
        }
    }

    void display(){
        int k =0;
        for(int i =0; i<m; i++){

            for(int j =0; j<n; j++)
            {
                if(e[k].i == i && e[k].j == j)
                {
                cout<<e[k++].x<<" ";
                }
                else
                {
                    cout<<"0 ";
                }
            }
            cout<<endl;
        }
    }
};


int main()
{
    sparse s(4,5,3);
    s.create();
    s.display();

    return 0;
}
