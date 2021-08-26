#include <iostream>

using namespace std;
int n;

int main()
{

    cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=i;j<=n*n/2;j+=n)
            cout<<j<<" ";
        for(int j=n*n-i+1;j>n*n/2;j-=n)
            cout<<j<<" ";
        cout<<endl;
    }
    return 0;
}
