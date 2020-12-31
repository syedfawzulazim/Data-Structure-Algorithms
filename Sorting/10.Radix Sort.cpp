#include<iostream>
#include<cmath>
using namespace std;

template <class T>
void Print(T &arr, int n, string s){
cout<<s<<" : [ ";
for(int i=0; i<n; i++){
    cout<<arr[i];
    if( i < n-1){
        cout<<", ";
    }
}
    cout<<" ]";
}

int Maxi(int A[], int n){
    int Max = INT_MIN;
    for(int i=0; i<n; i++){
        if(A[i] > Max){
            Max = A[i];
        }
    }
return Max;
}

int CountDigits(int Max){
    int Count=0;
    while(Max !=0){
        Max = Max/10;
        Count++;
    }
return Count;
}


int getBinIndex(int x, int idx){
    return (int) (x / pow(10, idx)) % 10;
}


class Node{
public:
    int data;
    Node *next;
};

void Insert(Node **ptrBin, int value, int idx){

    Node *temp = new Node;
    temp->data = value;
    temp->next = nullptr;

    if(ptrBin[idx] == nullptr){
        ptrBin[idx] = temp;
    }
    else{
        Node* p = ptrBin[idx];
        while(p->next != nullptr){
            p= p->next;
        }
        p->next = temp;
    }
}


int Delete(Node **ptrBin, int idx){
    Node *p = ptrBin[idx];
    ptrBin[idx] = ptrBin[idx]->next;
    int x = p->data;
    delete p;
    return x;
}


void initializeBin(Node **Bin, int n){
    for(int i=0; i<n; i++){
        Bin[i] = nullptr;
    }
}

void RadixSort(int A[], int n){
    int Max = Maxi(A, n);
    int nPass = CountDigits(Max);

    Node **Bin = new Node *[10]; //(0-9) = 10, decimal digits

    initializeBin(Bin, 10);

    for(int pass=0;  pass<nPass; pass++){

        for(int i=0; i<n; i++){
            int binIdx = getBinIndex(A[i], pass);
            Insert(Bin, A[i], binIdx);
        }
        int i=0;
        int j=0;
        while( i<10){
            while(Bin[i] != nullptr){
                A[j++] = Delete(Bin, i);
            }
            i++;
        }
        initializeBin(Bin, 10);
    }
    delete [] Bin;
}


int main(){
    int A[] = {237, 146, 259, 348, 152, 163, 235, 48, 36, 62};
    int n = sizeof(A)/sizeof(A[0]);

    Print(A, n, "A");
    RadixSort(A, n);
    cout<<endl;
    Print(A, n, " Sorted A");

return 0;
}
