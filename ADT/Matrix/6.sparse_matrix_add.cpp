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

    sparse operator+(sparse &s);

    friend istream & operator>>(istream &is, sparse &s);
    friend ostream & operator<<(ostream &os, sparse &s);
};

    sparse sparse::operator+(sparse &s){ //add

        int i,j,k;
        if( m != s.m || n != s.n){
            return sparse(0,0,0);
        }

        sparse *sum = new sparse(m,n, num+s.num);

        i=j=k=0;

        while( i<num && j<s.num){

            if(e[i].i < s.e[j].i){
                sum->e[k++] = e[i++];
            }
            else if(e[i].i > s.e[j].i){
                sum->e[k++] = e[j++];
            }
            else
            {
                if(e[i].j < s.e[j].j){
                    sum->e[k++] = e[i++];
                }
                else if(e[i].j > s.e[j].j){
                    sum->e[k++] = e[j++];
                }
                else
                {
                    sum->e[k] = e[i];
                    sum->e[k++].x = e[i++].x + s.e[j++].x;
                }
            }
        }

        for( ; i<num; i++) sum->e[k++] = e[i];
        for( ; j<num; j++) sum->e[k++] = s.e[j];

        sum->num = k;

        return *sum;

    }

    istream & operator>>(istream &is, sparse &s){ //read/cin
        cout<<"Enter All non-zero  Elements : "<<endl;
        for(int i=0; i<s.num; i++){
            cin>>s.e[i].i>>s.e[i].j>>s.e[i].x;
        }
    }

    ostream & operator<<(ostream &os, sparse &s){ //display/cout
        int k =0;
        for(int i =0; i<s.m; i++){

            for(int j =0; j<s.n; j++)
            {
                if(s.e[k].i == i && s.e[k].j == j)
                {
                cout<<s.e[k++].x<<" ";
                }
                else
                {
                    cout<<"0 ";
                }
            }
            cout<<endl;
        }
    }


int main()
{
    sparse s1(5,5,5);
    sparse s2(5,5,5);

    cin>>s1;
    cin>>s2;

    sparse sum=s1+s2;

    cout<<"First Matrix"<<endl<<s1;
    cout<<"Second MAtrix"<<endl<<s2;
    cout<<"Sum Matrix"<<endl<<sum;

    return 0;
}

