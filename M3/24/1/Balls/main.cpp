#include <bits/stdc++.h>

using namespace std;
int mod=10631;
main()
{
    int n;
    cin>>n;
    vector<int> v;
    for(int i=0;i<=n;i++)
        v.push_back(i);
    for(int i=1;i<=n;i++)
    {
        if(n%i==0)
        {
            for(int j=1;j<=n/i;j++)
                reverse(v.begin()+(j-1)*i+1,v.begin()+j*i+1);
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++)
        ans=(ans+i*v[i])%mod;
    cout<<ans;
    return 0;
}
