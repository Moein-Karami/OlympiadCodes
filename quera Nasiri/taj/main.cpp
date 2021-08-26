#include <iostream>
#define ll long long
using namespace std;

int main()
{
    ll int n;
    cin>>n;
    for(ll int i=2;i*i<=n;i++)
    {
        if(n%i==0)
            cout<<i<<" ";
        while(n%i==0)
        {
            n/=i;
        }
    }
    if(n>1)cout<<n;
    return 0;
}
