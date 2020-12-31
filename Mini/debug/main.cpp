#include <iostream>

using namespace std;

int main()
{
    int sum=0;
    int A[] = {2,4,6,8,10};

    for(auto x:A)
    {
        sum=sum+x;
    }

    cout << sum << endl;
    return 0;
}
