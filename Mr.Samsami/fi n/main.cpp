#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int ans=1;
    for(int i=2;i*i<=n;i++)
    {
        int t=1;
        while(n%i==0)
        {
            n/=i;
            t*=i;
        }
        ans*=(t-(t/i));
    }
    if(n>1)
    {
        ans*=(n-1);
    }
    cout<<ans;
    return 0;
}
