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


class Node{
public:
    int data;
    Node *next;
};

void Insert(Node **ptrBin, int idx){

    Node *temp = new Node;
    temp->data = idx;
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

void BinSort(int A[], int n){
    int Max = Maxi(A, n);

    Node **Bin = new Node *[Max+1];

    initializeBin(Bin, Max+1);

        for(int i=0; i<n; i++){
            Insert(Bin, A[i]);
        }

        int i=0;
        int j=0;

        while( i< Max +1){
            while(Bin[i] != nullptr){
                A[j++] = Delete(Bin, i);
            }
            i++;
        }
    delete [] Bin;
}


int main(){
    int A[] = {2, 5, 8, 12, 3, 6, 7, 10};
    int n = sizeof(A)/sizeof(A[0]);

    Print(A, n, "A");
    BinSort(A, n);
    cout<<endl;
    Print(A, n, "Sorted A");

return 0;
}

