#include<iostream>
using namespace std;

class MyInt{ //deletes the heap memory
private:
    int *data;
public:
    explicit MyInt(int *p=nullptr){
        data = p;
    }
    ~MyInt(){
        delete data;
    }
    int  &operator * (){
    return *data;
    }
};


int main(){

int *p = new int(10);
MyInt obj = MyInt(p);
cout<< *obj<<endl;

return 0;
}
