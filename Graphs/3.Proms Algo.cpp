#include<iostream>
#define V 8
#define I 32767
using namespace std;

void PrintMST(int T[][V-2], int G[V][V]){
    cout << "\nMinimum Spanning Tree Edges (w/ cost)\n" << endl;
    int sum {0};
    for (int i {0}; i<V-2; i++){
        int c = G[T[0][i]][T[1][i]];
        cout << "[" << T[0][i] << "]---[" << T[1][i] << "] cost: " << c << endl;
        sum += c;
    }
    cout << endl;
    cout << "Total cost of MST: " << sum << endl;
}

PrimsMST(int C[V][V], int n){
  int u;
    int v;
    int MIN {I};
    int near [V];
    int t[2][6] {0};

    // Initial: Find MIN cost edCe
    for (int i {1}; i<V; i++){
        near[i] = I;  // Initialize near array with INFINItY
        for (int j {i}; j<V; j++){
            if (C[i][j] < MIN){
                MIN = C[i][j];
                u = i;
                v = j;
            }
        }
    }
    t[0][0] = u;
    t[1][0] = v;
    near[u] = near[v] = 0;

    // Initialize near array to near MIN cost edges
    for (int i {1}; i<V; i++){
        if (near[i] != 0){
            if (C[i][u] < C[i][v]){
                near[i] = u;
            } else {
                near[i] = v;
            }
        }
    }

    // Repeat
    for (int i {1}; i<n-1; i++){
        int k;
        MIN = I;
        for (int j {1}; j<V; j++){
            if (near[j] != 0 && C[j][near[j]] < MIN){
                k = j;
                MIN = C[j][near[j]];
            }
        }
        t[0][i] = k;
        t[1][i] = near[k];
        near[k] = 0;

        // Update near array to near MIN cost edges
        for (int j {1}; j<V; j++){
            if (near[j] != 0 && C[j][k] < C[j][near[j]]){
                near[j] = k;
            }
        }
    }

    for(int i=0; i<n-1; i++){
        cout<<"("<<t[0][i]<<","<<t[1][i]<<")"<<endl;
    }

    PrintMST(t, C);
}


int main(){

    int cost [V][V] {
            {I, I, I, I, I, I, I, I},
            {I, I, 25, I, I, I, 5, I},
            {I, 25, I, 12, I, I, I, 10},
            {I, I, 12, I, 8, I, I, I},
            {I, I, I, 8, I, 16, I, 14},
            {I, I, I, I, 16, I, 20, 18},
            {I, 5, I, I, I, 20, I, I},
            {I, I, 10, I, 14, 18, I, I},
    };

    int n = sizeof(cost[0])/sizeof(cost[0][0]) - 1; // 32/4 = 8 - 1 = 7

    PrimsMST(cost, n);

return 0;
}

