#include<iostream>
#include<cmath>
using namespace std;

class Term{
public:
    int coeff;
    int expo;
};

class Poly{
private:
    int n;
    Term *t;
public:
    Poly(int n)
    :n(n)
    {
     t = new Term[n]; //[] number of objs
    }
    ~Poly(){
    delete [] t;
    }

    void create(){
        cout<<"Enter the coeff & expo : "<<endl;
        for(int i=0; i<n; i++){
            cin>>t[i].coeff>>t[i].expo;
        }
    }

    void display(){
        for(int i=0; i<n; i++){
            cout<<t[i].coeff<<"x"<<t[i].expo<<"+";
        }
        cout<<endl;
    }

    int Psum(){
        int sum =0;
        int x;
        cin>>x;
        for(int i=0; i<n; i++){
            sum +=  t[i].coeff  * pow( x, t[i].expo);
        }
    return sum;
    }

    friend Poly *add(Poly *p1, Poly *p2);

};

Poly *add(Poly *p1, Poly *p2){

    int i,j,k;

    Poly *sum = new Poly(p1->n+p2->n);

    i=j=k=0;

    while(i < p1->n && j < p2->n){

        if(p1->t[i].expo > p2->t[j].expo){
            sum->t[k++] = p1->t[i++]; // copies all coff + expo
        }
        else if(p1->t[i].expo < p2->t[j].expo){
            sum->t[k++] = p2->t[j++];
        }
        else{
            sum->t[k].expo = p1->t[i].expo;
            sum->t[k++].coeff = p1->t[i++].coeff + p2->t[j++].coeff;
        }

    }

    for( ; i< p1->n; i++) sum->t[k++] = p1->t[i];
    for( ; j< p2->n; j++) sum->t[k++] = p2->t[j];
    sum->n = k;


    return sum;
}

int main(){

    Poly p1(3), p2(3), *p3;

    p1.create();
    p2.create();

    p3 = add(&p1,&p2);

    p3->display();
    cout<<endl;
    //result
    cout<<p3->Psum();


return 0;
}
