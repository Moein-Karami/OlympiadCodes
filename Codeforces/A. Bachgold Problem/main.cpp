#include <iostream>

using namespace std;

int main()
{
    int n;
    cin>>n;
    if(n%2==0)
    {
        cout<<n/2;
        cout<<endl;
        for(int i=1;i<=n/2;i++)
            cout<<2<<" ";
    }
    else
    {
        cout<<(n-3)/2+1;
        cout<<endl;
        cout<<3<<" ";
        n-=3;
        for(int i=1;i<=n/2;i++)
            cout<<2<<" ";
    }

    return 0;
}
