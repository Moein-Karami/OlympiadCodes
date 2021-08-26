#include <iostream>

using namespace std;

int main()
{
    long long int n,ans=0;
    cin>>n;
    if(n%2==0)
    {
        ans=n/2;
    }
    else
    {
        ans=-(n+1)/2;
    }
    cout<<ans;
    return 0;
}
